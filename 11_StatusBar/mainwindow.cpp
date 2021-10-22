#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->addPermanentWidget(ui->pushButton_2);   // adiciona um botal na barra de status
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ok_clicked()
{
    ui->statusbar->showMessage("Nome = " + ui->lineEdit_nome->text() + " Email = " + ui->lineEdit_email->text()); // Se o botão for clicacdo adiciona a informação na barra de status
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->statusbar->showMessage("teste");
    QMessageBox::about(this,"teste","teste");       // Troca a informação com o botão da barra de status
}

