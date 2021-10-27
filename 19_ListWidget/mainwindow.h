#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Add_clicked();

    void on_lineEdit_item_returnPressed();

    void on_pushButton_AddMore_clicked();

    void on_pushButton_Mark_clicked();

    void on_pushButton_Unmark_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
