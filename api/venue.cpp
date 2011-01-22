#include "venue.h"

Venue::Venue(QObject *parent) :
    QObject(parent)
{
}

void Venue::setId(QString id)
{
    this->id = id;
}

void Venue::setName(QString name)
{
    this->name = name;
}

void Venue::setTwitterContact(QString twitter)
{
    this->twitterContact = twitter;
}

void Venue::setPhoneContact(QString phone)
{
    this->phoneContact = phone;
}

void Venue::setAddress(QString address)
{
    this->address = address;
}

void Venue::setCity(QString city)
{
    this->city = city;
}

void Venue::setState(QString state)
{
    this->state = state;
}

void Venue::setPostalCode(QString code)
{
    this->postalCode = code;
}

void Venue::setLat(double lat)
{
    this->lat = lat;
}

void Venue::setLong(double lng)
{
    this->lng=lng;
}

QString Venue::getId()
{
    return id;
}

QString Venue::getName()
{
    return name;
}

QString Venue::getTwitterContact()
{
    return twitterContact;
}

QString Venue::getPhoneContact()
{
    return phoneContact;
}

QString Venue::getAddress()
{
    return address;
}

QString Venue::getCity()
{
    return city;
}

QString Venue::getState()
{
    return state;
}

QString Venue::getPostalCode()
{
    return postalCode;
}

double Venue::getLat()
{
    return lat;
}

double Venue::getLng()
{
    return lng;
}
