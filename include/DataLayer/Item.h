#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include <QDebug>
#include <QtQuick/QQuickItem>

#include "set"

class Item : public QObject
{
    Q_OBJECT

public:

    Item(QObject *parent = nullptr);

    bool init(int id, QString color, QObject *parent = nullptr);

    ~Item(){ }

    // QProperties
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)

    // QProperties getters
    int id(void){return _id;}
    QString color(void){return _color;}

    // QProperties setters
    Q_INVOKABLE void setId(int value);
    Q_INVOKABLE void setColor(QString value);

    void update(int id, QString color);

signals:
    void idChanged();
    void colorChanged();

private:

    double _id;
    QString _color;
};

typedef std::map<std::string, Item> ItemMap;

#endif // ITEM_H
