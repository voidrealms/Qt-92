#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    LoadSettings();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::SaveSettings()
{
    //Save

    QSettings setting("MyCompany","myapp");
    setting.beginGroup("MainWindow");
    setting.setValue("position",this->geometry());
    setting.endGroup();

    qDebug() << "Saved";
}

void Dialog::LoadSettings()
{
    //Load

    QSettings setting("MyCompany","myapp");
    setting.beginGroup("MainWindow");
    QRect myrect  = setting.value("position").toRect();
    setGeometry(myrect);
    setting.endGroup();

    qDebug() << "Loaded";
}



void Dialog::on_pushButton_clicked()
{
    //Save
    SaveSettings();
}

void Dialog::on_pushButton_2_clicked()
{
    //Load
    LoadSettings();
}
