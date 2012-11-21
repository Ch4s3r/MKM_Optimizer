#include "mkmcardparser.h"

MkmCardParser::MkmCardParser()
{
}

QStringList MkmCardParser::getCardURLs(QString cardname)
{
    QString mRequestURL = "https://www.magickartenmarkt.de/?mainPage=showSearchResult&searchFor=";
    mRequestURL.append(cardname);
    QByteArray mHTML = manager.getURL(mRequestURL);


    QStringList mEditionsFound;
    //if more editions of one card are available
    if (!mHTML.contains("<redirected>")){
        int pos = 0;
        while(1){
            QRegExp mRegex("(<a href=\")(.{0,100}\\.prod)(\">)");
            pos = mRegex.indexIn(mHTML,pos);
            if (pos > -1) {
//                 qDebug() << mRegex.cap(2);
                 mEditionsFound.append(mRegex.cap(2));
            }else break;
            pos += mRegex.cap(0).length();
        }
        mEditionsFound.removeDuplicates();
//        qDebug() << mEditionsFound;
    } else {
        mEditionsFound.append(mHTML.replace("<redirected>",""));
    }

    current_card_name = mEditionsFound.at(0).left(cardname.length());

    return mEditionsFound;
}

QString MkmCardParser::getCurrentCardName()
{
    return current_card_name;
}

bool MkmCardParser::checkEditionsAvailable()
{
    return 0;
}
