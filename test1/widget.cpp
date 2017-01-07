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


    /*
    ** Open the json file
    */

    file.setFileName("../list.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    settings = file.readAll();
    file.close();

    QJsonDocument sd = QJsonDocument::fromJson(settings.toUtf8());
    QJsonArray tab = sd.array();


    /*
    ** Browse the main array
    */
    QTableWidget *tableWidget = new QTableWidget(this);
        tableWidget->setRowCount(10);
        tableWidget->setColumnCount(3);
        QStringList title;
        title.append("name");
        title.append("price");
        title.append("currency");
        tableWidget->setHorizontalHeaderLabels(title);
        QTableWidgetItem *newItem = new QTableWidgetItem("yo");
            tableWidget->setItem(1, 1, newItem);

    foreach (const QJsonValue &value, tab)
    {
        QJsonObject brand = value.toObject();

        QWidget *widget1 = new QWidget;
        ui->tabWidget->addTab(widget1, brand["name"].toString());


        QJsonArray type = brand["drones"].toArray();
        QListWidget *applicationsListBox = new QListWidget;

    /*
    ** Browse the main array
    */
        foreach (const QJsonValue &value2, type)
        {
            QJsonObject drone = value2.toObject();
            QStringList applications;

            applications.append("name");
            applications.append(drone["name"].toString());

            applications.append("price");
            QString valueAsString = QString::number(drone["price"].toDouble());
            applications.append(valueAsString);

            applications.append("currency");
            applications.append(drone["currency"].toString());
            applicationsListBox->insertItems(0, applications);

        }


        QVBoxLayout *layout = new QVBoxLayout;
//        layout->addWidget(applicationsListBox);
        layout->addWidget(tableWidget);

        widget1->setLayout(layout);

    }

}

Widget::~Widget()
{
    delete ui;
}
