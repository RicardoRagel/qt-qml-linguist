# Qt-QML Linguist

Simple Qt Application project with front-end developed using QML. The aim of this app is to be used as example of how to use the Linguist framework in Qt to support multi-language applications.

Key points:

* The translations are specified in TS files. They should be in the .pro file added to TRANSLATIONS
* Code refers to them using the tr() method from C++ and the qsTr() method from QML. 
* Running QtCreator->Tools->External->Linguist->lupdate, the TS files are generated.
* They can be updated manually or using the Qt Linguist application
* Once the translations are set, running QtCreator->Tools->External->Linguist->lrelease will generate the necessary QM files.
* These QM files must added to our QRC resources file and this file to the project in RESOURCES
* To execute the translation, it is necessary:
    * A QTranslator object where load the current language (QM file)
    * QTranslator object must be installed once in the application. It is not necessary to do eveytime we load another language.
* To retranslate:
    * The C++ entries must be re-set. In other words, the tr() method must be called again in all the strings we want to translate again.
    * The QML entries (qsTr) are retranslate calling to the QML engine retranslate method.



