#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap logo("C:/Users/Nycolas/Desktop/Aulas.png");     // Variavel para armazenar a imagem
    ui->label->setPixmap(logo.scaled(1133,665,Qt::KeepAspectRatio));        // utilizando um label para mostrar a imagem
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   QPixmap logoNew("C:/Users/Nycolas/Desktop/Facul agora.png");
   ui->label->setPixmap(logoNew.scaled(1133,665,Qt::KeepAspectRatio));
}

