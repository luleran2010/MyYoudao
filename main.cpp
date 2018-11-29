#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "dictconfig.h"
#include "basicmeaning.h"
#include "translationrequest.h"
#include "translationresult.h"
#include "youdaodict.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<DictConfig>("org.leran.myyoudao", 1, 0, "DictConfig");
    qRegisterMetaType<BasicMeaning>("BasicMeaning");
    qmlRegisterType<TranslationRequest>("org.leran.myyoudao", 1, 0, "TranslationRequest");
    qmlRegisterType<TranslationResult>("org.leran.myyoudao", 1, 0, "TranslationResult");
    qmlRegisterType<YoudaoDict>("org.leran.myyoudao", 1, 0, "YoudaoDict");

    YoudaoDict dict;
    engine.rootContext()->setContextProperty("dict", &dict);
    DictConfig *config = new DictConfig();
    dict.setConfig(config);
    engine.rootContext()->setContextProperty("config", config);

    TranslationRequest request;
    request.setFrom("EN");
    request.setTo("zh-CHS");
    engine.rootContext()->setContextProperty("request", &request);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
