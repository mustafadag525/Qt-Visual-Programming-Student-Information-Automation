#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include<QObjectList>
QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_btnBilgiyaz_clicked();

    void on_btnMezuniyet_clicked();

    void on_btnOgrencidurum_clicked();

    bool mezuniyetsorgula();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
