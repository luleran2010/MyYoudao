#ifndef BASICMEANING_H
#define BASICMEANING_H

#include <QtCore>

class BasicMeaning
{
    Q_GADGET

    Q_PROPERTY(QString usPhonetic READ usPhonetic WRITE setUsPhonetic)
    Q_PROPERTY(QString phonetic READ phonetic WRITE setPhonetic)
    Q_PROPERTY(QString ukPhonetic READ ukPhonetic WRITE setUkPhonetic)
    Q_PROPERTY(QString ukSpeech READ ukSpeech WRITE setUkSpeech)
    Q_PROPERTY(QString usSpeech READ usSpeech WRITE setUsSpeech)
    Q_PROPERTY(QStringList explains READ explains WRITE setExplains)
public:
    BasicMeaning();

    QString usPhonetic() const;
    void setUsPhonetic(const QString &usPhonetic);

    QString phonetic() const;
    void setPhonetic(const QString &phonetic);

    QString ukPhonetic() const;
    void setUkPhonetic(const QString &ukPhonetic);

    QString ukSpeech() const;
    void setUkSpeech(const QString &ukSpeech);

    QString usSpeech() const;
    void setUsSpeech(const QString &usSpeech);

    QStringList explains() const;
    void setExplains(const QStringList &explains);

private:
    QString m_usPhonetic;
    QString m_phonetic;
    QString m_ukPhonetic;
    QString m_ukSpeech;
    QString m_usSpeech;
    QStringList m_explains;
};

#endif // BASICMEANING_H
