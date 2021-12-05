#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QFileDialog>

QString fileDir = "H:/Qt_Projects/24_Files/Txt file/";
QString fileName = "test.txt";

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


void MainWindow::on_pushButtonSave_clicked()
{
    QFile file(fileDir + fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text))                             // Checa se é possível abrir o arquivo
    {
        QMessageBox::about(this,"Error","Não foi possível abrir o documento");
    }

    QTextStream out(&file);
    QString text = ui->plainTextEdit->toPlainText();                            // Recebe o texto da caixa de edição

    out<<text;                                                                  // Armazena no arquivo

    file.flush();
    file.close();
}


void MainWindow::on_pushButtonRead_clicked()
{
    QFile file(fileDir+ fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text))                              // Checa se é possível abrir o arquivo
    {
        QMessageBox::about(this,"Error","Não foi possível abrir o documento");
    }

    QTextStream in(&file);                                                      // le o texto do arquivo
    QString text = in.readAll();

    ui->plainTextEdit->setPlainText(text);                                      // Adiciona o texto na caixa de edição
    file.close();
}


void MainWindow::on_pushButtonOpenFile_clicked()
{
    QString filter = "Todos Arquivos (*.*) ;; Arquivo de texto (*.txt)";        // Filtros de arquivos permitidos

    QString openFile = QFileDialog::getOpenFileName(this,"Abrir Arquivos",QDir::homePath(),filter);     // Abre em mode de leitura

    QFile file(openFile);

    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::about(this,"Error","Não foi possível abrir o documento");
    }

    QTextStream in(&file);
    QString text = in.readAll();

    ui->plainTextEdit->setPlainText(text);
    file.close();
}

