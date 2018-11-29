#include "youdaodict.h"
#include <QNetworkRequest>
#include <QCryptographicHash>
#include <QUrlQuery>

YoudaoDict::YoudaoDict(QObject *parent) : QObject(parent)
  , m_result(nullptr), reply(nullptr)
{
    qsrand(0);
}

DictConfig *YoudaoDict::config() const
{
    return m_config;
}

void YoudaoDict::setConfig(DictConfig *config)
{
    m_config = config;
}

TranslationResult *YoudaoDict::translate(TranslationRequest *transreq)
{
    QUrl url = m_config->link();
    int salt = qrand();
    QString sign = makeSign(transreq, salt);
    QUrlQuery query;
    query.addQueryItem("q", transreq->q());
    query.addQueryItem("from", transreq->from());
    query.addQueryItem("to", transreq->to());
    query.addQueryItem("appKey", m_config->appKey());
    query.addQueryItem("salt", QString::number(salt));
    query.addQueryItem("sign", sign);
    query.addQueryItem("ext", m_config->ext());
    query.addQueryItem("voice", QString::number(m_config->voice()));
    url.setQuery(query);

    QNetworkRequest request(url);
    reply = nam.get(request);
    connect(reply, &QNetworkReply::finished, this, &YoudaoDict::replyFinished);
    if (m_result) {
        delete m_result;
        m_result = nullptr;
    }
    m_result = new TranslationResult();
    return m_result;
}

TranslationResult *YoudaoDict::result() const
{
    return m_result;
}

QString YoudaoDict::makeSign(TranslationRequest *transreq, int salt)
{
    QString params = m_config->appKey() + transreq->q() + QString::number(salt) + m_config->secretKey();
    return QCryptographicHash::hash(params.toLocal8Bit(), QCryptographicHash::Md5).toHex().toUpper();
}

void YoudaoDict::replyFinished()
{
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << reply->errorString();
        m_result->setErrorCode(100);
        reply->deleteLater();
        reply = nullptr;
    }

    m_result->fromJson(reply->readAll());
    emit m_result->finished();
    emit lookupFinished();
}
