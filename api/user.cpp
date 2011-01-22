#include "user.h"

User::User(QObject *parent) :
    QObject(parent)
{

}

void User::setId(QString id)
{
    this->id=id;
}

void User::setFirstName(QString name)
{
    this->firstName = name;
}

void User::setPhoto(QString photo)
{
    this->photo = photo;
}

void User::setGender(QString gender)
{
    this->gender = gender;
}

void User::setHomecity(QString homecity)
{
    this->homeCity = homecity;
}

void User::setRelationship(QString relationship)
{
    this->relationship = relationship;
}

QString User::getId()
{
    return id;
}

QString User::getFirstName()
{
    return firstName;
}

QString User::getPhoto()
{
    return photo;
}

QString User::getGender()
{
    return gender;
}

QString User::getHomecity()
{
    return homeCity;
}

QString User::getRelationship()
{
    return relationship;
}
