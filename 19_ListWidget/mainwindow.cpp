#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

QVector <int> mark;

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


void MainWindow::on_pushButton_Add_clicked()
{
    ui->listWidget->addItem(ui->lineEdit_item->text());     // Lista recebe a string digitada na linha
    ui->lineEdit_item->clear();     // Apaga a linha
    ui->lineEdit_item->setFocus();      // Retorna o cursor na linha
}


void MainWindow::on_lineEdit_item_returnPressed()       // Adiciona caso aperte enter
{
    on_pushButton_Add_clicked();        // Chama a função de adicionar
}


void MainWindow::on_pushButton_AddMore_clicked()
{
    QListWidgetItem *item1 = new QListWidgetItem("ola");        // Adiciona o conteudo na lista
    QListWidgetItem *item2 = new QListWidgetItem("teste");
    QListWidgetItem *item3 = new QListWidgetItem("oie");
    QListWidgetItem *item4 = new QListWidgetItem("blabla");

    ui->listWidget->addItem(item1);
    ui->listWidget->addItem(item2);
    ui->listWidget->addItem(item3);
    ui->listWidget->addItem(item4);
}


void MainWindow::on_pushButton_Mark_clicked()
{
    ui->listWidget->currentItem()->setForeground(Qt::lightGray);        // Altera design do item selecionado
    ui->listWidget->currentItem()->setBackground(Qt::darkGreen);
    mark.push_back(ui->listWidget->currentRow());
    qDebug() << "Marcado" << mark;
}


void MainWindow::on_pushButton_Unmark_clicked()
{
    ui->listWidget->currentItem()->setForeground(Qt::black);
    ui->listWidget->currentItem()->setBackground(Qt::white);
    mark.erase(mark.begin()+ui->listWidget->currentRow());
    qDebug() << "Desmarcado" << mark;
}

