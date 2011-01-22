#ifndef FOURSQUAREAPI_H
#define FOURSQUAREAPI_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QMap>
#include <QScriptValue>
#include <QScriptEngine>

const QString KRecentCheckins ="https://api.foursquare.com/v2/checkins/recent";
class Checkin;
class User;
class Venue;
class FoursquareApi : public QObject
{
    Q_OBJECT
    public:
        explicit FoursquareApi(QObject *parent = 0);

        enum ApiCalls{
            Recent_Checkins
        };
        void getRecentCheckins(double latitude=0,double longitude=0);

        void setAuthToken(QString);
    signals:
        void ApiError(QString);
        void checkinsRecieved(QList<Checkin*>*);
    public slots:
        void recievedReply(QNetworkReply*);
        Checkin* extractCheckin(QScriptValue value);
        User* extractUser(QScriptValue value);
        Venue* extractVenue(QScriptValue value);
    private:
        QNetworkAccessManager* netmgr;
        QString authToken;
        QMap<QNetworkReply* , int> callTypeMap;
        QScriptEngine* scriptEngine;
};

#endif // FOURSQUAREAPI_H
