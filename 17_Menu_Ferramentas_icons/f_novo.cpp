#include "f_novo.h"
#include "ui_f_novo.h"

F_novo::F_novo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::F_novo)
{
    ui->setupUi(this);
}

F_novo::~F_novo()
{
    delete ui;
}
