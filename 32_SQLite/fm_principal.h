#ifndef FM_PRINCIPAL_H
#define FM_PRINCIPAL_H

#include <QDialog>

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

private:
    Ui::Fm_principal *ui;
};

#endif // FM_PRINCIPAL_H
