#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QTranslator>
#include <QQmlApplicationEngine>

using namespace std;

class DataManager : public QObject
{
  Q_OBJECT

public:

  // Constructor
  DataManager(QTranslator* translator, QQmlApplicationEngine* qml_engine);

  // Destuctor
  ~DataManager();

  Q_PROPERTY(QString label READ label WRITE setLabel NOTIFY lableChanged())
  QString label() {return _label;}
  void setLabel(QString value);

  Q_INVOKABLE void setLanguage(QString lang);

signals:

  void lableChanged();

private:
  void retranslate();

  QTranslator* _translator;
  QQmlApplicationEngine* _qml_engine;
  QString _label;
};

#endif // DATAMANAGER_H
