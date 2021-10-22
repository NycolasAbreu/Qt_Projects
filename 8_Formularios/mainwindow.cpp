#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "janela2.h"

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
    Janela2 form2;      // Quando o botão for clicado abre uma nova tela(form)
    form2.exec();
}

