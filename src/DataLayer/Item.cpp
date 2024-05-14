#include "Item.h"

Item::Item(QObject *parent):
    QObject(parent),
    _id(0),
    _color("white")
{
}

bool Item::init(int id, QString color, QObject *parent)
{
    setParent(parent);
    _id = id;
    _color = color;

    return true;
}

void Item::setId(int value)
{
    _id = value;
    emit idChanged();
}
void Item::setColor(QString value)
{
    _color = value;
    emit colorChanged();
}

void Item::update(int id, QString color)
{
    setId(id);
    setColor(color);
}
