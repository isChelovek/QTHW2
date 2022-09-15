#ifndef MYTABLE_H
#define MYTABLE_H
#include <QAbstractItemView>


class myTable:QAbstractItemView
{
    Q_OBJECT

public:
    explicit myTable(QObject *parent = nullptr);

};

#endif // MYTABLE_H
