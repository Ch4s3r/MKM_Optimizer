#ifndef MKMCARDPARSER_H
#define MKMCARDPARSER_H

#include <QtCore>
#include "networkmanager.h"

class MkmCardParser
{
    NetworkManager manager;
    QString current_card_name;
public:
    MkmCardParser();
    QStringList getCardURLs(QString cardname);
    QString getCurrentCardName();
    bool checkEditionsAvailable();
};

#endif // MKMCARDPARSER_H


