#include "translationrequest.h"

TranslationRequest::TranslationRequest(QObject *parent) : QObject(parent)
{

}

QString TranslationRequest::q() const
{
    return m_q;
}

void TranslationRequest::setQ(const QString &q)
{
    m_q = q;
}

QString TranslationRequest::from() const
{
    return m_from;
}

void TranslationRequest::setFrom(const QString &from)
{
    m_from = from;
}

QString TranslationRequest::to() const
{
    return m_to;
}

void TranslationRequest::setTo(const QString &to)
{
    m_to = to;
}
