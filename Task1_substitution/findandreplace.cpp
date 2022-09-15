#include "findandreplace.h"

findAndReplace::findAndReplace(QObject *parent)
        : QObject{parent}
{

}


void findAndReplace::replaceCharacters(QString data)
{
    data.replace(QString("#@PROM@"),  QString("‰"));
    data.replace(QString("#@AUTOR@"), QString("©"));
    data.replace(QString("#@R@"),     QString("®"));
    data.replace(QString("#@EVRO@"),  QString("€"));
    data.replace(QString("#@RUB@"),   QString("₽"));
    emit resultString(data);
}
