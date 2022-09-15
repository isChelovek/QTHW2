#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "findandreplace.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    findAndReplace *replaceCharacters = new findAndReplace();
    connect(this,              &MainWindow::sendData,              replaceCharacters, &findAndReplace::replaceCharacters);
    connect(replaceCharacters, &findAndReplace::resultString,      this,              &MainWindow::getResult);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::getResult(QString data)
{
    ui->plainTextEdit->setPlainText(data);
}


void MainWindow::on_pushButton_clicked()
{
    emit sendData( ui->plainTextEdit->toPlainText());
}

