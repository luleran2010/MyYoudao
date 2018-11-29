#ifndef YOUDAODICT_H
#define YOUDAODICT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "dictconfig.h"
#include "translationrequest.h"
#include "translationresult.h"

class YoudaoDict : public QObject
{
    Q_OBJECT

    Q_PROPERTY(DictConfig *config READ config WRITE setConfig)
    Q_PROPERTY(TranslationResult *result READ result)
public:
    explicit YoudaoDict(QObject *parent = nullptr);
    DictConfig *config() const;
    void setConfig(DictConfig *config);

    TranslationResult *result() const;
signals:

    void lookupFinished();

public slots:
    TranslationResult *translate(TranslationRequest *transreq);
private:
    DictConfig *m_config;
    TranslationResult *m_result;

    QNetworkAccessManager nam;
    QNetworkReply *reply;

    QString makeSign(TranslationRequest *transreq, int salt);
    void replyFinished();
};

#endif // YOUDAODICT_H
