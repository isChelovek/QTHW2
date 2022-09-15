#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAbstractItemModel>
#include <QtGlobal>
#include <QDebug>
#include <QItemSelectionModel>
#include <QModelIndex>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList      lst;




    QItemSelectionModel *sMode = new QItemSelectionModel(model , this);
sMode->selectedRows();

    for (int row = 0; row < model->rowCount(); ++row) {
        for (int column = 0; column < model->columnCount(); ++column) {
            QStandardItem *item = new QStandardItem();
            model->setItem(row, column, item);
        }
    }

    model->setHeaderData(0, Qt::Horizontal, tr("No"));
    model->setHeaderData(1, Qt::Horizontal, tr("Имя компьютера"));
    model->setHeaderData(2, Qt::Horizontal, tr("IP адрес"));
    model->setHeaderData(3, Qt::Horizontal, tr("MAC адрес"));

    model->item(0,0)->setData("1", Qt::EditRole);
    model->item(1,0)->setData("2", Qt::EditRole);
    model->item(2,0)->setData("3", Qt::EditRole);
    model->item(3,0)->setData("4", Qt::EditRole);

    model->item(0,1)->setData("Server",             Qt::EditRole);
    model->item(0,2)->setData("192.168.0.1",        Qt::EditRole);
    model->item(0,3)->setData("00-B0-D0-63-C2-26.", Qt::EditRole);

    model->item(2,1)->setData("Admin",              Qt::EditRole);
    model->item(2,2)->setData("192.168.0.2",        Qt::EditRole);
    model->item(2,3)->setData("00-B0-D0-63-C2-26.", Qt::EditRole);

    ui->tableView->setModel(model);
    ui->tableView->setSelectionModel(sMode);

    ui->tableView->setSelectionBehavior (QAbstractItemView::SelectRows);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnSELECT_clicked()
{
    QModelIndexList selectind = ui->tableView->selectionModel()->selectedIndexes();
    for (int i = 0; i < selectind.size(); i++)
    {
       for  (int j = 0; j < model->columnCount(); j++)
       {
            model->setData(model->index(selectind[i].row(), j), QVariant(QBrush(Qt::red)), Qt::BackgroundRole);
       }
    }
}

