#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAbstractItemModel>
#include <QtGlobal>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList      lst;
    lst << "С++" << "Python" << "Java" << "C#" << "PHP" << "JavaScript";
    for (int i = 0; i < lst.size(); ++i)
    {
        QStandardItem* item = new QStandardItem(lst[i]);
        item->setIcon(QIcon(":/image/" + lst[i] + ".png"));
        model->appendRow(item);
    }
    ui->listView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_iconMode_clicked()
{
    if (ui->iconMode->isChecked()){
        ui->listView->setViewMode(QListView::IconMode);
    } else {
        ui->listView->setViewMode(QListView::ListMode);
    }
}


void MainWindow::on_btnAdd_clicked()
{
   QStandardItem* item = new QStandardItem("qt");
   item->setIcon(QIcon(":/image/qt.png"));
   model->appendRow(item);
}


void MainWindow::on_btnUp_clicked()
{
    QStandardItem* itemTemp = new QStandardItem();    // Создаем новый указатель
    QModelIndex index = ui->listView->currentIndex(); // Узнаем индекс выделенного элемента
    if (index.row() != 0)
    {
        itemTemp = model->item(index.row())->clone();     // Копируем выделенный элемент
        model->removeRow(index.row());                    // Удаляем выделенный элемент
        model->insertRow(index.row() - 1, itemTemp);
    }
}


void MainWindow::on_btnDown_clicked()
{
    QStandardItem* itemTemp = new QStandardItem();    // Создаем новый указатель
    QModelIndex index = ui->listView->currentIndex(); // Узнаем индекс выделенного элемента
    itemTemp = model->item(index.row())->clone();     // Копируем выделенный элемент
    model->removeRow(index.row());                    // Удаляем выделенный элемент
    model->insertRow(index.row() + 1, itemTemp);
}


void MainWindow::on_btnDelete_clicked()
{
    QModelIndex index = ui->listView->currentIndex();
    model->removeRow(index.row());
}

