#include "dictconfig.h"
#include <QSettings>
#include <QDebug>

const QUrl DictConfig::HTTP_LINK = QUrl::fromUserInput("http://openapi.youdao.com/api");
const QUrl DictConfig::HTTPS_LINK = QUrl::fromUserInput("https://openapi.youdao.com/api");

DictConfig::DictConfig(QObject *parent) : QObject(parent)
  , m_link(HTTPS_LINK), m_appKey(), m_ext("mp3"), m_voice(Female)
{
    QSettings settings("Walkers", "MyYoudao");

    settings.beginGroup("APIConfig");
    m_link = settings.value("link", HTTPS_LINK).toUrl();
    m_appKey = settings.value("appKey", "").toString();
    m_secretKey = settings.value("secretKey", "").toString();
    m_ext = settings.value("ext", "mp3").toString();
    m_voice = Voice(settings.value("voice", 0).toInt());
    settings.endGroup();
}

DictConfig::~DictConfig()
{
    QSettings settings("Leran", "MyYoudao");

    settings.beginGroup("APIConfig");
    settings.setValue("link", m_link);
    settings.setValue("appKey", m_appKey);
    settings.setValue("secretKey", m_secretKey);
    settings.setValue("ext", m_ext);
    settings.setValue("voice", m_voice);
    settings.endGroup();
}

QUrl DictConfig::link() const
{
    return m_link;
}

void DictConfig::setLink(const QUrl &link)
{
    m_link = link;
}

QString DictConfig::secretKey() const
{
    return m_secretKey;
}

void DictConfig::setSecretKey(const QString &secretKey)
{
    m_secretKey = secretKey;
}

QString DictConfig::appKey() const
{
    return m_appKey;
}

void DictConfig::setAppKey(const QString &appKey)
{
    m_appKey = appKey;
}

QString DictConfig::ext() const
{
    return m_ext;
}

void DictConfig::setExt(const QString &ext)
{
    m_ext = ext;
}

DictConfig::Voice DictConfig::voice() const
{
    return m_voice;
}

void DictConfig::setVoice(const Voice &voice)
{
    m_voice = voice;
}
