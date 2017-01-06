#include "widget.h"
#include "ui_widget.h"
#include <QGridLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QFile file;
    QString settings;
    QStringList Dronebrand;

    file.setFileName("/home/cerbair/Desktop/interview/list.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    settings = file.readAll();
    file.close();

    QJsonDocument sd = QJsonDocument::fromJson(settings.toUtf8());
    QJsonArray tab = sd.array();

   // qDebug() << tab;

    foreach (const QJsonValue & value, tab)
    {
        QJsonObject obj = value.toObject();
        Dronebrand.append(obj["name"].toString());
    }

    qDebug()<< "Dronebrand" << Dronebrand ;

//    qDebug() << tab[0];

    QWidget *widget1 = new QWidget;
    ui->tabWidget->addTab(widget1, "mon tab");
     //insert data

    QJsonObject obj1 = sd.object();

}

Widget::~Widget()
{

    delete ui;
}
