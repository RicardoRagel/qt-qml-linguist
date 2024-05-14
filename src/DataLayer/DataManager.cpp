#include "DataManager.h"
#include <QRandomGenerator>

/** *********************************
 *  DataManager Initizalization
 ** ********************************/

DataManager::DataManager(QTranslator* translator, QQmlApplicationEngine* qml_engine):
    _translator(translator),
    _qml_engine(qml_engine),
    _label("None")
{
  qDebug() << "(DataManager) Initialization ...";

  setLanguage("English");
}

DataManager::~DataManager()
{

}

void DataManager::setLabel(QString value)
{
    _label = value;
    emit lableChanged();
}

void DataManager::setLanguage(QString lang)
{
    QString translationsPath = "";

    if (lang == "English")
    {
        qDebug() << "Setting language to English";
        translationsPath = ":/translations/app_en.qm";
    }
    else if (lang == "Spanish")
    {
        qDebug() << "Setting language to Spanish";
        translationsPath = ":/translations/app_es.qm";
    }
    else if (lang == "German")
    {
        qDebug() << "Setting language to German";
        translationsPath = ":/translations/app_de.qm";
    }
    else
    {
        qDebug() << "(DataManager) Language not valid";
    }

    if (_translator->load(translationsPath))
    {
        retranslate();
    }
    else
    {
        qDebug() << "(DataManager) Error loading translations: " << translationsPath;
    }
}

void DataManager::retranslate()
{
    setLabel(tr("greetings"));
    _qml_engine->retranslate();
}
