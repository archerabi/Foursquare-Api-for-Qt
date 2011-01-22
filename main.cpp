#include <QtCore/QCoreApplication>
#include <QUrl>
#include "api/foursquareapi.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

   FoursquareApi api;
   api.setAuthToken("");
   api.getRecentCheckins();
   return a.exec();
}
