#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit_Senha->setEchoMode(QLineEdit::Password);       // Esconde a senha
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    QString login = ui->lineEdit_Login->text();     // Salva na variavel o dado
    QString senha = ui->lineEdit_Senha->text();

    if(login == "Nycolas" && senha == "1234")
        QMessageBox::information(this,"Login","Login Correto");
    else
        QMessageBox::information(this,"Login","Login Errado");



    ui->lineEdit_Login->clear();        // Limpa a linha
    ui->lineEdit_Senha->clear();
}

