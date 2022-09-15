#ifndef FINDANDREPLACE_H
#define FINDANDREPLACE_H
#include <QObject>


class findAndReplace: public QObject
{
        Q_OBJECT
public:
    explicit findAndReplace(QObject *parent = nullptr);
public slots:
    void replaceCharacters(QString data);
signals:
    void resultString(QString result);

};

#endif // FINDANDREPLACE_H
