#include "checkin.h"

Checkin::Checkin(QObject *parent) :
    QObject(parent)
{
}

void Checkin::setUser(User* user)
{
    this->user = user;
}

void Checkin::setVenue(Venue * v)
{
    this->venue =v;
}

void Checkin::setId(QString id)
{
    this->id = id;
}

void Checkin::setCreatedAt(qint64 createdAt)
{
    this->createdAt = createdAt;
}

void Checkin::setType(QString type)
{
    this->type = type;
}

void Checkin::setTimeZone(QString timezone)
{
    this->timeZone = timezone;
}

User* Checkin::getUser()
{
    return user;
}

Venue* Checkin::getVenue()
{
    return venue;
}

QString Checkin::getId()
{
    return id;
}

qint64 Checkin::getCreatedAt()
{
    return createdAt;
}

QString Checkin::getType()
{
    return type;
}

QString Checkin::getTimezone()
{
    return timeZone;
}
