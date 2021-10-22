#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap livro(":/imgs/Imagens/book1.png");

    ui->label->setPixmap(livro);
}

MainWindow::~MainWindow()
{
    delete ui;
}

