#include "fm_pesquisa.h"
#include "ui_fm_pesquisa.h"

fm_pesquisa::fm_pesquisa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fm_pesquisa)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.prepare("select * from tb_contatos");
    if(query.exec()){
        int cont = 0;
        ui->tableWidgetPesquisar->setColumnCount(4);
        while(query.next()){
            ui->tableWidgetPesquisar->insertRow(cont);
            ui->tableWidgetPesquisar->setItem(cont,0,new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidgetPesquisar->setItem(cont,1,new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidgetPesquisar->setItem(cont,2,new QTableWidgetItem(query.value(2).toString()));
            ui->tableWidgetPesquisar->setItem(cont,3,new QTableWidgetItem(query.value(3).toString()));
            ui->tableWidgetPesquisar->setRowHeight(cont,20);
            cont++;
        }
        ui->tableWidgetPesquisar->setColumnWidth(0,30);
        ui->tableWidgetPesquisar->setColumnWidth(1,150);
        ui->tableWidgetPesquisar->setColumnWidth(3,300);

        QStringList cabecalho = {"Id","Nome","Telefone","E-mail"};
        ui->tableWidgetPesquisar->setHorizontalHeaderLabels(cabecalho);

        ui->tableWidgetPesquisar->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableWidgetPesquisar->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidgetPesquisar->verticalHeader()->setVisible(false);
        ui->tableWidgetPesquisar->setStyleSheet("QTableView {selection-background-color:blue}");
    }
}

fm_pesquisa::~fm_pesquisa()
{
    delete ui;
}

void fm_pesquisa::on_pushButtonExcluir_clicked()
{
    int linha = ui->tableWidgetPesquisar->currentRow();
    QString id = ui->tableWidgetPesquisar->item(linha,0)->text();

    QSqlQuery query;
    query.prepare("delete from tb_contatos where id_contato ="+id);
    if(query.exec()){
        QMessageBox::information(this,"","Registro excluido");
        ui->tableWidgetPesquisar->removeRow(linha);
    }
}

