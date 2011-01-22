#ifndef VENUE_H
#define VENUE_H

#include <QObject>

class Venue : public QObject
{
    Q_OBJECT
    public:
        explicit Venue(QObject *parent = 0);
        void setId(QString string);
        void setName(QString name);
        void setTwitterContact(QString twitter);
        void setPhoneContact(QString phone);
        void setAddress(QString address);
        void setCity(QString city);
        void setState(QString state);
        void setPostalCode(QString code);
        void setLat(double lat);
        void setLong(double lng);

        QString getId();
        QString getName();
        QString getTwitterContact();
        QString getPhoneContact();
        QString getAddress();
        QString getCity();
        QString getState();
        QString getPostalCode();
        double getLat();
        double getLng();
    private:
        QString id;
        QString name;
        QString twitterContact;
        QString phoneContact;
        QString address;
        QString city;
        QString state;
        QString postalCode;
        double lat;
        double lng;
};

#endif // VENUE_H
