#ifndef TRANSLATIONRESULT_H
#define TRANSLATIONRESULT_H

#include <QObject>
#include <basicmeaning.h>

class TranslationResult : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int errorCode READ errorCode WRITE setErrorCode)
    Q_PROPERTY(QString query READ query WRITE setQuery)
    Q_PROPERTY(QStringList translation READ translation WRITE setTranslation)
    Q_PROPERTY(BasicMeaning basic READ basic WRITE setBasic)
    Q_PROPERTY(QMap<QString, QStringList> web READ web WRITE setWeb)
    Q_PROPERTY(QString l READ l WRITE setL)
    Q_PROPERTY(QUrl dict READ dict WRITE setDict)
    Q_PROPERTY(QUrl webdict READ webdict WRITE setWebdict)
    Q_PROPERTY(QUrl tSpeakUrl READ tSpeakUrl WRITE setTSpeakUrl)
    Q_PROPERTY(QUrl speakUrl READ speakUrl WRITE setSpeakUrl)
public:
    explicit TranslationResult(QObject *parent = nullptr);
    ~TranslationResult();

    void fromJson(const QByteArray &json);
    Q_INVOKABLE QString toHtml() const;

    int errorCode() const;
    void setErrorCode(int errorCode);

    QString query() const;
    void setQuery(const QString &query);

    QStringList translation() const;
    void setTranslation(const QStringList &translation);

    QMap<QString, QStringList> web() const;
    void setWeb(const QMap<QString, QStringList> &web);

    QString l() const;
    void setL(const QString &l);

    QUrl dict() const;
    void setDict(const QUrl &dict);

    QUrl webdict() const;
    void setWebdict(const QUrl &webdict);

    QUrl tSpeakUrl() const;
    void setTSpeakUrl(const QUrl &tSpeakUrl);

    QUrl speakUrl() const;
    void setSpeakUrl(const QUrl &speakUrl);

    BasicMeaning basic() const;
    void setBasic(BasicMeaning basic);

signals:
    void finished();
public slots:
private:
    int m_errorCode;
    QString m_query;
    QStringList m_translation;
    BasicMeaning m_basic;
    QMap<QString, QStringList> m_web;
    QString m_l;
    QUrl m_dict;
    QUrl m_webdict;
    QUrl m_tSpeakUrl;
    QUrl m_speakUrl;
};

#endif // TRANSLATIONRESULT_H
