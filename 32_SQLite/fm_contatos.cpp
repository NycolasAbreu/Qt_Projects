#include "fm_contatos.h"
#include "ui_fm_contatos.h"

fm_contatos::fm_contatos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fm_contatos)
{
    ui->setupUi(this);
}

fm_contatos::~fm_contatos()
{
    delete ui;
}

void fm_contatos::on_pushButtonGravar_clicked()
{
    QString nome = ui->lineEditNome->text();
    QString telefone = ui->lineEditTelefone->text();
    QString email = ui->lineEditEmail->text();

    QSqlQuery query;
    query.prepare("insert into tb_contatos (nome_contato, tel_contato, email_contato) values ('"+nome+"','"+telefone+"','"+email+"')");
    if(query.exec()){
        ui->lineEditNome->clear();
        ui->lineEditTelefone->clear();
        ui->lineEditEmail->clear();
        ui->lineEditNome->setFocus();
    }
}

void fm_contatos::on_pushButtonCancelar_clicked()
{
    close();
}

