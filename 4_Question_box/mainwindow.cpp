#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    //   Salva o valor da resposta em uma variavel
    QMessageBox::StandardButton resposta = QMessageBox::question(this,"","Deseja fechar o programa?",QMessageBox::Yes|QMessageBox::No);
    if (resposta == QMessageBox::Yes){
        close();
    }
}

