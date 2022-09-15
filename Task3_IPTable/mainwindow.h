#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

#include <QModelIndex>
#include <QTableView>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QListWidgetItem    *pitem = new QListWidgetItem();
    QListWidget        *lwg   = new QListWidget();
    QStandardItemModel *model = new QStandardItemModel(4,4);
private slots:
    QModelIndex tableViewClicked();



    void on_btnSELECT_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
