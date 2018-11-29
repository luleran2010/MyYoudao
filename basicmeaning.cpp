#include "basicmeaning.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

BasicMeaning::BasicMeaning()
{

}

QString BasicMeaning::usPhonetic() const
{
    return m_usPhonetic;
}

void BasicMeaning::setUsPhonetic(const QString &usPhonetic)
{
    m_usPhonetic = usPhonetic;
}

QString BasicMeaning::phonetic() const
{
    return m_phonetic;
}

void BasicMeaning::setPhonetic(const QString &phonetic)
{
    m_phonetic = phonetic;
}

QString BasicMeaning::ukPhonetic() const
{
    return m_ukPhonetic;
}

void BasicMeaning::setUkPhonetic(const QString &ukPhonetic)
{
    m_ukPhonetic = ukPhonetic;
}

QString BasicMeaning::ukSpeech() const
{
    return m_ukSpeech;
}

void BasicMeaning::setUkSpeech(const QString &ukSpeech)
{
    m_ukSpeech = ukSpeech;
}

QString BasicMeaning::usSpeech() const
{
    return m_usSpeech;
}

void BasicMeaning::setUsSpeech(const QString &usSpeech)
{
    m_usSpeech = usSpeech;
}

QStringList BasicMeaning::explains() const
{
    return m_explains;
}

void BasicMeaning::setExplains(const QStringList &explains)
{
    m_explains = explains;
}
