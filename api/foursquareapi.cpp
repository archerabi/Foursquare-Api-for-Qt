#include "foursquareapi.h"
#include <QNetworkReply>
#include <QUrl>
#include <QDebug>
#include "checkin.h"
#include "user.h"
#include <QScriptValueIterator>
#include <QList>
#include "venue.h"

FoursquareApi::FoursquareApi(QObject *parent) :
    QObject(parent)
{
    scriptEngine = new QScriptEngine(this);
    netmgr = new QNetworkAccessManager(this);
    connect(netmgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(recievedReply(QNetworkReply*)));
}

void FoursquareApi::setAuthToken(QString token)
{
    this->authToken = token;
}

void FoursquareApi::getRecentCheckins(double latitude,double longitude)
{
    QUrl  url(KRecentCheckins);
    url.addQueryItem("oauth_token",authToken);
    if(latitude!=0 && longitude!=0)
        url.addQueryItem("ll",QString().setNum(latitude) + ',' + QString().setNum(longitude));

    QNetworkRequest req;
    req.setUrl(url);

    QNetworkReply* reply = netmgr->get(req);
    callTypeMap.insert(reply,Recent_Checkins);
    qDebug() << req.url();
}

void FoursquareApi::recievedReply(QNetworkReply * reply)
{
    QString str = reply->readAll();
    qDebug() << str;

    if(reply->error() != QNetworkReply::NoError)
    {
        emit ApiError(reply->errorString());
    }
    else
    {
        QScriptValue val =scriptEngine->evaluate( "(" + str + ")");
        switch(callTypeMap.value(reply))
        {
            case Recent_Checkins:
                QList<Checkin*> list;
                QScriptValueIterator iter (val.property("response").property("recent"));
                while(iter.hasNext()){
                    iter.next();
                    list.append( extractCheckin( iter.value() ) );
                }
                emit checkinsRecieved(&list);
                break;
        }
    }
    callTypeMap.remove(reply);
    reply->deleteLater();
}

Checkin* FoursquareApi::extractCheckin(QScriptValue value)
{
    Checkin* checkin = new Checkin(this);
    checkin->setId( value.property("id").toString() );
    checkin->setCreatedAt( value.property("createdAt").toUInt32());
    checkin->setTimeZone( value.property("timeZone").toString());
    checkin->setType( value.property("type").toString());
    checkin->setUser( extractUser(value.property("user")) );
    checkin->setVenue( extractVenue(value.property("venue")));
    return checkin;
}
User* FoursquareApi::extractUser(QScriptValue value)
{
    User* user = new User(this);
    user->setFirstName( value.property("firstName").toString() );
    user->setGender( value.property("gender").toString() );
    user->setHomecity( value.property("homeCity").toString() );;
    user->setId( value.property("id").toString() );;
    user->setPhoto( value.property("photo").toString());
    user->setRelationship( value.property("relationship").toString());
    return user;
}

Venue* FoursquareApi::extractVenue(QScriptValue value)
{
    Venue* ven = new Venue(this);
    ven->setId( value.property("id").toString() );
    ven->setName( value.property("name").toString() );
    ven->setTwitterContact( value.property("contact").property("twitter").toString() );
    ven->setPhoneContact( value.property("contact").property("phone").toString() );
    ven->setAddress( value.property("location").property("address").toString() );
    ven->setCity( value.property("location").property("city").toString() );
    ven->setState( value.property("location").property("state").toString() );
    ven->setPostalCode(value.property("location").property("postalCode").toString() );
    ven->setLat( value.property("location").property("lat").toString().toDouble() );
    ven->setLong( value.property("location").property("lng").toString().toDouble() );
    return ven;
}
