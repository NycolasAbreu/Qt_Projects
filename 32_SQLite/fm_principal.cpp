#include "fm_principal.h"
#include "ui_fm_principal.h"
#include "fm_contatos.h"
#include "fm_pesquisa.h"

Fm_principal::Fm_principal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fm_principal)
{
    ui->setupUi(this);
}

Fm_principal::~Fm_principal()
{
    delete ui;
}


void Fm_principal::on_pushButtonAdd_clicked()
{
    fm_contatos fcontato;
    fcontato.exec();
}


void Fm_principal::on_pushButtonPesquisar_clicked()
{
    fm_pesquisa fpesquisa;
    fpesquisa.exec();
}

