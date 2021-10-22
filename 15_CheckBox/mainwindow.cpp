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
    bool cb1, cb2, cb3;     // Resposta do checkbox é bool

    cb1 = ui->checkBox_1->isChecked();      // Salva a variavel do checkbox
    cb2 = ui->checkBox_2->isChecked();
    cb3 = ui->checkBox_3->isChecked();

    if(cb1)
        QMessageBox::information(this, "MSG","Cb1");    // Se estiver selecionado printa
    else if(cb2)
        QMessageBox::information(this, "MSG","Cb2");
    else if(cb3)
        QMessageBox::information(this, "MSG","Cb3");
}

void MainWindow::on_checkBox_1_stateChanged(int arg1)   // Direto no check box, retorna 0 ou 1
{
    if(arg1)
        QMessageBox::information(this, "MSG","Cb1");
}

