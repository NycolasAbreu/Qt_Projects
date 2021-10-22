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


void MainWindow::on_pushButton_mostrar_clicked()
{
    QString nome = ui->lineEdit_nome->text();           // Recebe o texto nas variaveis
    QString email = ui->lineEdit_email->text();
    QString telefone = ui->lineEdit_telefone->text();

    //      Mostra uma caixa de msg com os dados
    QMessageBox::information(this,"Dados","Nome =" + nome + "\nFone =" + telefone + "\n Email = " + email);
}

void MainWindow::on_pushButton_limpar_clicked()
{
    ui->lineEdit_nome->clear();     // Limpa os valores na linha
    ui->lineEdit_email->clear();
    ui->lineEdit_telefone->clear();

    ui->lineEdit_nome->setFocus();  // Seta o cursor para a linha de cima
}

