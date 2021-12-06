#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QFontDialog>
#include <QFont>
#include <QColorDialog>
#include <QColor>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNovo_triggered()      // Inicia um novo documento
{
    fileDir = "";
    ui->textEdit->clear();
    ui->textEdit->setFocus();
}


void MainWindow::on_actionAbrir_triggered()
{
    QString filter = "Todos Arquivos (*.*) ;; Arquivo de texto (*.txt)";        // Filtro para tipos de arquivos a serem abertos
    QString fileName = QFileDialog::getOpenFileName(this,"Open", QDir::homePath(),filter);      // Recebe o nome do arquivo utilizando o File Dialog

    QFile file(fileName);
    fileDir = fileName;

    if(!file.open(QFile::ReadOnly | QFile::Text))       // Caso não abra gera um erro
    {
        QMessageBox::warning(this,"Erro","Arquivo não pode ser aberto");
        return;
    }
    else
    {
        QTextStream in(&file);
        QString content = in.readAll();         // Lê o conteudo do arquivo e printa no textEdit
        ui->textEdit->setText(content);
        file.close();
    }
}


void MainWindow::on_actionSalvar_como_triggered()
{
    QString filter = "Todos Arquivos (*.*) ;; Arquivo de texto (*.txt)";
    QString fileName = QFileDialog::getSaveFileName(this,"Salvar como", QDir::homePath(),filter);

    QFile file(fileName);
    fileDir = fileName;

    if(!file.open(QFile::WriteOnly | QFile::Text))       // Caso não abra gera um erro
    {
        QMessageBox::warning(this,"Erro","Arquivo não pode ser salvo");
        return;
    }
    else
    {
        QTextStream out(&file);
        QString content = ui->textEdit->toPlainText();
        out << content;
        file.flush();
        file.close();
    }
}


void MainWindow::on_actionSalvar_triggered()
{
    QFile file(fileDir);

    if(!file.open(QFile::WriteOnly | QFile::Text))       // Caso não abra gera um erro
    {
        QMessageBox::warning(this,"Erro","Arquivo não pode ser salvo");
        return;
    }
    else
    {
        QTextStream out(&file);
        QString content = ui->textEdit->toPlainText();
        out << content;
        file.flush();
        file.close();
    }
}


void MainWindow::on_actionFechar_triggered()
{
    close();
}


void MainWindow::on_actionCopiar_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionRecortar_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionColar_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionDesfazer_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionRefazer_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionFonte_triggered()
{
    bool isFontOk;
    QFont font = QFontDialog::getFont(&isFontOk,this);

    if(isFontOk){
        ui->textEdit->setFont(font);
    }
    else
        return;
}


void MainWindow::on_actionCor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::black,this,"Escolha a cor");
    if(color.isValid()){
        ui->textEdit->setTextColor(color);
    }
    else
        return;
}

