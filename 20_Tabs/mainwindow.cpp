#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "form.h"

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


void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);        // Remove a tag da UI
}


void MainWindow::on_pushButton_clicked()
{
    ui->tabWidget->addTab(new QWidget,QString::number(ui->tabWidget->count()+1));   // Adiciona uma nova tag e incrementa o número de tags
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->tabWidget->addTab(new Form,QString::number(ui->tabWidget->count()+1));      // Adiciona a pagina com formulário pré programado
}

