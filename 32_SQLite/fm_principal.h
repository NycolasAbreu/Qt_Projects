#ifndef FM_PRINCIPAL_H
#define FM_PRINCIPAL_H

#include <QDialog>
#include "fm_contatos.h"

namespace Ui {
class Fm_principal;
}

class Fm_principal : public QDialog
{
    Q_OBJECT

public:
    explicit Fm_principal(QWidget *parent = nullptr);
    ~Fm_principal();

private slots:

    void on_pushButtonAdd_clicked();

    void on_pushButtonPesquisar_clicked();

private:
    Ui::Fm_principal *ui;
};

#endif // FM_PRINCIPAL_H
