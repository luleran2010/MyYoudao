#ifndef TRANSLATIONREQUEST_H
#define TRANSLATIONREQUEST_H

#include <QObject>

class TranslationRequest : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString q READ q WRITE setQ NOTIFY qChanged)
    Q_PROPERTY(QString from READ from WRITE setFrom NOTIFY fromChanged)
    Q_PROPERTY(QString to READ to WRITE setTo NOTIFY toChanged)
public:
    explicit TranslationRequest(QObject *parent = nullptr);

    QString q() const;
    void setQ(const QString &q);

    QString from() const;
    void setFrom(const QString &from);

    QString to() const;
    void setTo(const QString &to);

signals:
    void qChanged(const QString &q);

    void fromChanged(const QString &from);

    void toChanged(const QString &to);

public slots:
private:
    QString m_q;
    QString m_from;
    QString m_to;
};

#endif // TRANSLATIONREQUEST_H
