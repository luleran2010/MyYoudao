#include "translationresult.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

TranslationResult::TranslationResult(QObject *parent) : QObject(parent)
{

}

TranslationResult::~TranslationResult()
{
}

void TranslationResult::fromJson(const QByteArray &json)
{
    auto doc = QJsonDocument::fromJson(json);
    auto root = doc.object();

    m_errorCode = root["errorCode"].toString().toInt();
    if (m_errorCode != 0) {
        return;
    }

    m_query = root["query"].toString();

    m_translation.clear();
    for (auto const &trans: root["translation"].toArray()) {
        m_translation << trans.toString();
    }

    if (root.contains("basic")) {
        auto jsonBasic = root["basic"].toObject();
        m_basic.setPhonetic(jsonBasic["phonetic"].toString());
        m_basic.setUsPhonetic(jsonBasic["us-phonetic"].toString());
        m_basic.setUkPhonetic(jsonBasic["uk-phonetic"].toString());
        m_basic.setUsSpeech(jsonBasic["us-speech"].toString());
        m_basic.setUkSpeech(jsonBasic["uk-speech"].toString());
        QStringList explains;
        for (auto const &explain: jsonBasic["explains"].toArray()) {
            explains << explain.toString();
        }
        m_basic.setExplains(explains);
    } else {
        m_basic = BasicMeaning();
    }

    m_web.clear();
    if (root.contains("web")) {
        auto jsonWeb = root["web"].toArray();
        for (auto const &item: jsonWeb) {
            QString key = item.toObject()["key"].toString();
            QStringList values;
            for (auto const &value: item.toObject()["value"].toArray()) {
                values << value.toString();
            }
            m_web[key] = values;
        }
    }

    m_l = root["l"].toString();

    m_dict = QUrl::fromUserInput(root["dict"].toObject()["url"].toString());

    m_webdict = QUrl::fromUserInput(root["webdict"].toObject()["url"].toString());
    if (root.contains("tSpeakUrl")) {
        m_tSpeakUrl = QUrl::fromUserInput(root["tSpeakUrl"].toString());
    }

    if (root.contains("speakUrl")) {
        m_speakUrl = QUrl::fromUserInput(root["speakUrl"].toString());
    }
}

QString TranslationResult::toHtml() const
{
    if (m_errorCode == 100) {
        return QString("<i>Network or program error</i>");
    } else if (m_errorCode != 0) {
        return QString("<i>Request rule error</i>");
    }

    QString html;
    QTextStream out(&html, QIODevice::WriteOnly);
    out << "<b>" << m_query << "</b>" << endl;
    out << "<p>";
    QString phoneticTemplate = "<i>%1</i> <span style=\"color:blue\">[%2]</span> ";
    if (!m_basic.ukPhonetic().isEmpty()) out << phoneticTemplate.arg("uk", m_basic.ukPhonetic());
    if (!m_basic.usPhonetic().isEmpty()) out << phoneticTemplate.arg("us", m_basic.usPhonetic());

    auto itt = m_translation.constBegin();
    out << *(itt++);
    while (itt != m_translation.constEnd()) {
        out << "; " << *(itt++);
    }
    out << "</p>" << endl;

    if (!m_basic.explains().isEmpty()) {
        out << "<div>" << endl;
        out << "<b>Basic Meaning</b>" << endl;
        out << "<ul>" << endl;
        for (auto const &explain: m_basic.explains()) {
            out << "<li><p>" << explain << "</p></li>" << endl;
        }
        out << "</div>" << endl;
    }
    if (!m_web.isEmpty()) {
        out << "<div>" << endl;
        out << "<b>Web Interpretation</b>" << endl;
        out << "<ul>" << endl;
        auto it = m_web.constBegin();
        while (it != m_web.constEnd()) {
            out << "<li><i>" << it.key() << "</i> ";
            auto itv = it.value().constBegin();
            out << *(itv++);
            while (itv != it.value().constEnd()) {
                out << ", " << *(itv++);
            }
            out << "</li>" << endl;
            it++;
        }
        out << "</ul>" << endl;
        out << "</div>" << endl;
    }

    return html;
}

int TranslationResult::errorCode() const
{
    return m_errorCode;
}

void TranslationResult::setErrorCode(int errorCode)
{
    m_errorCode = errorCode;
}

QString TranslationResult::query() const
{
    return m_query;
}

void TranslationResult::setQuery(const QString &query)
{
    m_query = query;
}

QStringList TranslationResult::translation() const
{
    return m_translation;
}

void TranslationResult::setTranslation(const QStringList &translation)
{
    m_translation = translation;
}

QMap<QString, QStringList> TranslationResult::web() const
{
    return m_web;
}

void TranslationResult::setWeb(const QMap<QString, QStringList> &web)
{
    m_web = web;
}

QString TranslationResult::l() const
{
    return m_l;
}

void TranslationResult::setL(const QString &l)
{
    m_l = l;
}

QUrl TranslationResult::dict() const
{
    return m_dict;
}

void TranslationResult::setDict(const QUrl &dict)
{
    m_dict = dict;
}

QUrl TranslationResult::webdict() const
{
    return m_webdict;
}

void TranslationResult::setWebdict(const QUrl &webdict)
{
    m_webdict = webdict;
}

QUrl TranslationResult::tSpeakUrl() const
{
    return m_tSpeakUrl;
}

void TranslationResult::setTSpeakUrl(const QUrl &tSpeakUrl)
{
    m_tSpeakUrl = tSpeakUrl;
}

QUrl TranslationResult::speakUrl() const
{
    return m_speakUrl;
}

void TranslationResult::setSpeakUrl(const QUrl &speakUrl)
{
    m_speakUrl = speakUrl;
}

BasicMeaning TranslationResult::basic() const
{
    return m_basic;
}

void TranslationResult::setBasic(BasicMeaning basic)
{
    m_basic = basic;
}
