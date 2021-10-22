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
    QMessageBox::about(this,"Teste","Qt é legal");      // Apresenta na tela diferente caixas de msg
    QMessageBox::critical(this,"testee","ta pegando fogo bixo");
    QMessageBox::information(this,"testee","informação");
    QMessageBox::question(this,"teste","bora?");
    QMessageBox::warning(this,"teste","warning");
}

