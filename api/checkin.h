#ifndef CHECKIN_H
#define CHECKIN_H

#include <QObject>

class User;
class Venue;
class Checkin : public QObject
{
    Q_OBJECT
    public:
        explicit Checkin(QObject *parent = 0);

        void setUser(User*);
        void setVenue(Venue*);
        void setId(QString);
        void setCreatedAt(qint64);
        void setType(QString type);
        void setTimeZone(QString timezone);

        User* getUser();
        Venue* getVenue();
        QString getId();
        qint64 getCreatedAt();
        QString getType();
        QString getTimezone();

    private:
        User* user;
        Venue* venue;
        QString id;
        qint64 createdAt;
        QString type;
        QString timeZone;
};

#endif // CHECKIN_H
