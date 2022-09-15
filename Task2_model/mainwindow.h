#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

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
      QStandardItemModel *model = new QStandardItemModel();
private slots:
    void on_iconMode_clicked();

    void on_btnAdd_clicked();

    void on_btnUp_clicked();

    void on_btnDown_clicked();

    void on_btnDelete_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
