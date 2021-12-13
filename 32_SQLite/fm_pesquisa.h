#ifndef FM_PESQUISA_H
#define FM_PESQUISA_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>

namespace Ui {
class fm_pesquisa;
}

class fm_pesquisa : public QDialog
{
    Q_OBJECT

public:
    explicit fm_pesquisa(QWidget *parent = nullptr);
    ~fm_pesquisa();

private slots:
    void on_pushButtonExcluir_clicked();

private:
    Ui::fm_pesquisa *ui;
};

#endif // FM_PESQUISA_H
