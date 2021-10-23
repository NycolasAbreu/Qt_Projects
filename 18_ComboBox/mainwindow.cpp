#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->comboBox->addItem(QIcon(":/img/Img/icons8-python-48.png"),"Python");    // Adiciona item no final
    ui->comboBox->addItem(QIcon(":/img/Img/icons8-css3-48.png"),"Css");

    ui->comboBox->insertItem(0,QIcon(":/img/Img/icons8-css3-48.png"),"Css");    // Adiciona item no ponto indicado
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::about(this, "linguagens", ui->comboBox->currentText());    // Recebendo valor do combobox
}

