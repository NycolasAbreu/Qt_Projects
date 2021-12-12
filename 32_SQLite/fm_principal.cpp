#include "fm_principal.h"
#include "ui_fm_principal.h"

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

