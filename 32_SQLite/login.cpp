#include "login.h"
#include "ui_login.h"
#include "fm_principal.h"
#include "ui_fm_principal.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase bancoDados=QSqlDatabase::addDatabase("QSQLITE");
    bancoDados.setDatabaseName("H:/Qt_Projects/32_SQLite/Database.db");

    if (!bancoDados.open()){
        ui->label->setText("Não foi possível abrir");
    }
    else{
        ui->label->setText("Abriu");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();

    QSqlQuery query;

    query.exec("select * from tb_login where username = '"+username+"' and senha = '"+password+"'");

    int cont = 0;

    while (query.next()){
        cont ++;
    }

    if (cont>0){
        this->close();
        Fm_principal fprincipal;
        fprincipal.setModal(true);
        fprincipal.exec();
    }
    else{
        ui->lineEdit_Password->clear();
        ui->lineEdit_Username->clear();
        ui->lineEdit_Username->setFocus();
    }
}
