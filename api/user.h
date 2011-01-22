#ifndef USER_H
#define USER_H

#include <QObject>

class User : public QObject
{
    Q_OBJECT
    public:
        explicit User(QObject *parent = 0);

        void setId(QString id);
        void setFirstName(QString name);
        void setPhoto(QString photo);
        void setGender(QString gender);
        void setHomecity(QString homecity);
        void setRelationship(QString relationship);

        QString getId();
        QString getFirstName();
        QString getPhoto();
        QString getGender();
        QString getHomecity();
        QString getRelationship();
    private:
        QString id;
        QString firstName;
        QString photo;
        QString gender;
        QString homeCity;
        QString relationship;
 };

#endif // USER_H
