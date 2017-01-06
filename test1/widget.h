#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFile>
#include <QJsonObject>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QTableWidget>
#include <QTableView>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:

private:
    Ui::Widget *ui;
    QTableWidget* m_pTableWidget;
};

#endif // WIDGET_H
