#ifndef APP_H
#define APP_H

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlEngine>
#include <QtQml>
#include <QIcon>

#include "DataManager.h"

using namespace std;

class App : public QApplication
{
  Q_OBJECT

public:

  App(int& argc, char* argv[]);

  ~App();

  void initCommon(void);

  DataManager* dataManager() { return _dataManager; }
  QQmlApplicationEngine* qmlEngine() { return _qmlAppEngine; }

  bool loadQmlEngine(void);

  static App* _app;

private:

  DataManager* _dataManager;            // Data Manager ((accesible from C++ and QML))
  QQmlApplicationEngine* _qmlAppEngine; // QML Engine Handler
  QObject* _rootQmlObject(void);
  QTranslator* _translator;
};

#endif // APP_H
