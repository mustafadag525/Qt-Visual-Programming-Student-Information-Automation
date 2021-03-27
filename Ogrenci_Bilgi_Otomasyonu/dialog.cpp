#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_radioButton_clicked()
{
    ui->gr_sinif->setEnabled(true);
    ui->gr_zorunluders->setEnabled(true);
    ui->gr_alinanderslerlisansustu->setEnabled(false);
    ui->gr_durum->setEnabled(false);
}

void Dialog::on_radioButton_2_clicked()
{
    ui->gr_sinif->setEnabled(false);
    ui->gr_zorunluders->setEnabled(false);
    ui->gr_alinanderslerlisansustu->setEnabled(true);
    ui->gr_durum->setEnabled(true);
}

void Dialog::on_btnBilgiyaz_clicked()
{
    QString ad,soyad,bolum,seviye;
    ad=ui->edtad->text();
    soyad=ui->edtsoyad->text();
    bolum=ui->edtbolum->text();

   /* // 1.yöntem seviyeyi alma yöntemi 1.yol;



QObjectList objler=this->children();
    foreach(QObject* obj,objler)
    {
        if(obj->inherits("QRadioButton"))
        {
            QRadioButton* rd=qobject_cast<QRadioButton*>(obj);
            if(rd->isChecked())
            {
                seviye=rd->text();
            }
        }
    }
*/

/*
// 2.yöntem;

QObject* obj=ui->groupBox;
QList<QRadioButton*>liste=obj->findChildren<QRadioButton*>(QString(),Qt::FindDirectChildrenOnly);
foreach(QRadioButton* rd,liste)
{
    if(rd->isChecked())
    {
        seviye=rd->text();
    }
}*/



    // 3.yöntem

if(ui->radioButton->isChecked())
{
    seviye=ui->radioButton->text();
}
if(ui->radioButton_2->isChecked())
{
    seviye=ui->radioButton_2->text();
}



QMessageBox::information(this,"öğrenci bilgileri","ad:"+ad+"\n"+"soyad:"+soyad+"\n"+"bolum:"+bolum+"\n"+"seviye:"+seviye);

}








void Dialog::on_btnMezuniyet_clicked()
{
    QString ad,soyad,bolum,seviye;
    ad=ui->edtad->text();
    soyad=ui->edtsoyad->text();
    bolum=ui->edtbolum->text();



    if(ui->radioButton->isChecked())
    {
        seviye=ui->radioButton->text();
    }
    if(ui->radioButton_2->isChecked())
    {
        seviye=ui->radioButton_2->text();
    }


    if(ui->radioButton->isChecked())
    {
        if(ui->rd_4snf->isChecked() && ui->ch_aiit->isChecked() && ui->ch_ingilizce->isChecked() && ui->ch_td->isCheckable())
        {
            QMessageBox::information(this,"mezuniyet biilgileri","öğrenci lisanstan mezun olabilir","tamam");
        }
        else
        {
            QMessageBox::information(this,"mezuniyet biilgileri","öğrenci lisanstan mezun olamaz","tamam");

        }



    }

    if(ui->radioButton_2->isChecked()){


        if(ui->rd_tez->isChecked() && ui->ch_secmeli->isChecked() && ui->ch_secmeli->isChecked() && ui->ch_seminer->isChecked())
        {
            QMessageBox::information(this,"mezuniyet biilgileri","öğrenci lisansüstünden mezun olabilir","tamam");

        }
        else

        {
            QMessageBox::information(this,"mezuniyet biilgileri","öğrenci lisansüstünden mezun olamaz","tamam");

        }
    }

}

void Dialog::on_btnOgrencidurum_clicked()
{
    QString ad,soyad,bolum,seviye;
    ad=ui->edtad->text();
    soyad=ui->edtsoyad->text();
    bolum=ui->edtbolum->text();



    if(ui->radioButton->isChecked())
    {
        seviye=ui->radioButton->text();
    }
    if(ui->radioButton_2->isChecked())
    {
        seviye=ui->radioButton_2->text();
    }

    bool durum=mezuniyetsorgula();
    if(seviye=="lisans")
    {
       if(durum)
       {
           if(ui->rd_4snf->isChecked() && ui->ch_aiit->isChecked() && ui->ch_ingilizce->isChecked() && ui->ch_td->isCheckable())
           {
               QMessageBox::information(this,"öğrenci biilgileri","öğrenci lisans seviyesinde mezun durumundaki bir öğrencidir","tamam");

           }


       }
       else

       {
           QMessageBox::information(this,"öğrenci biilgileri","öğrenci lisans seviyesinde bir öğrencidir","tamam");

       }
    }

    if(seviye=="lisansüstü")
    {
        if(durum)
        {
            if(ui->rd_tez->isChecked() && ui->ch_secmeli->isChecked() && ui->ch_secmeli->isChecked() && ui->ch_seminer->isChecked())
            {
                QMessageBox::information(this,"öğrenci biilgileri","öğrenci lisansüstü seviyesinde mezun durumundaki bir öğrencidir","tamam");

            }


        }
        else
        {
            QMessageBox::information(this,"öğrenci biilgileri","öğrenci lisansüstü seviyesinde bir öğrencidir","tamam");

        }
    }


}

bool Dialog::mezuniyetsorgula()
{
    QString ad,soyad,bolum,seviye;
    ad=ui->edtad->text();
    soyad=ui->edtsoyad->text();
    bolum=ui->edtbolum->text();



    if(ui->radioButton->isChecked())
    {
        seviye=ui->radioButton->text();
    }
    if(ui->radioButton_2->isChecked())
    {
        seviye=ui->radioButton_2->text();
    }


    if(ui->radioButton->isChecked())
    {
        if(ui->rd_4snf->isChecked() && ui->ch_aiit->isChecked() && ui->ch_ingilizce->isChecked() && ui->ch_td->isCheckable())
        {
            //QMessageBox::information(this,"mezuniyet biilgileri","öğrenci lisanstan mezun olabilir","tamam");
            return true;
        }
        else
        {
            //QMessageBox::information(this,"mezuniyet biilgileri","öğrenci lisanstan mezun olamaz","tamam");
            return false;

        }



    }

    if(ui->radioButton_2->isChecked()){


        if(ui->rd_tez->isChecked() && ui->ch_secmeli->isChecked() && ui->ch_secmeli->isChecked() && ui->ch_seminer->isChecked())
        {
            //QMessageBox::information(this,"mezuniyet biilgileri","öğrenci lisansüstünden mezun olabilir","tamam");
            return true;

        }
        else

        {
           // QMessageBox::information(this,"mezuniyet biilgileri","öğrenci lisansüstünden mezun olamaz","tamam");
            return false;

        }
    }







}
