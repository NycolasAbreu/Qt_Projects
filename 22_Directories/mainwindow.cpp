#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDir units;
    foreach(QFileInfo fileInfo, units.drives())         // Adiciona as unidades do computador no combobox
    {
        ui->comboBox->addItem(fileInfo.filePath());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    ui->listWidget->clear();                                    // Limpa a lista para o próximo diretório
    ui->listWidget->addItem(arg1);                              // Unidade Principal sempre em cima

    QDir content(arg1);
    foreach(QFileInfo fileInfo, content.entryInfoList())         // Adiciona as unidades do computador no combobox
    {
        if(fileInfo.isDir()){
            ui->listWidget->addItem("Dir : " + fileInfo.absoluteFilePath());        // Mostra o diretório na lista
        }


//        else if(fileInfo.isFile()){
//            ui->listWidget->addItem("File: " + fileInfo.absoluteFilePath());        // Mostra o arquivo na lista
//        }
    }
}


void MainWindow::on_pushButtonNewDir_clicked()
{
    QString local = ui->listWidget->currentItem()->text();              // Recebe o diretorio selecionado na lista
    QString dirName = "/"+ui->lineEditNameDir->text();                  // Recebe o nome digitado
    QDir newDir(local+dirName);

    if(newDir.exists())                                                 // Cria o diretorio novo
    {
        QMessageBox::about(this,"pasta","Diretório já existe");
    }
    else
    {
        newDir.mkdir(local+dirName);
        ui->listWidget->clear();
        ui->listWidget->addItem(ui->comboBox->currentText());
        QDir content(ui->comboBox->currentText());

        foreach(QFileInfo fileInfo, content.entryInfoList())         // Adiciona as unidades do computador no combobox
        {
            if(fileInfo.isDir())
            {
                ui->listWidget->addItem(fileInfo.absoluteFilePath());        // Mostra o diretório na lista
            }
        }
    }
    ui->lineEditNameDir->clear();
}


void MainWindow::on_pushButtonRemoveDir_clicked()
{
    QString local = ui->listWidget->currentItem()->text();              // Recebe o diretorio selecionado na lista
    QDir newDir(local);

    if(!newDir.exists())
    {
        QMessageBox::about(this,"pasta","Diretório não existe");
    }
    else
    {
        newDir.rmdir(local);
        ui->listWidget->clear();
        ui->listWidget->addItem(ui->comboBox->currentText());
        QDir content(ui->comboBox->currentText());

        foreach(QFileInfo fileInfo, content.entryInfoList())         // Adiciona as unidades do computador no combobox
        {
            if(fileInfo.isDir())
            {
                ui->listWidget->addItem(fileInfo.absoluteFilePath());        // Mostra o diretório na lista
            }
        }
    }
    ui->lineEditNameDir->clear();
}

