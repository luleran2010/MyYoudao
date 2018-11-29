#ifndef DICTCONFIG_H
#define DICTCONFIG_H

#include <QObject>
#include <QUrl>

class DictConfig : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QUrl link READ link WRITE setLink NOTIFY linkChanged)
    Q_PROPERTY(QString appKey READ appKey WRITE setAppKey NOTIFY appKeyChanged)
    Q_PROPERTY(QString secretKey READ secretKey WRITE setSecretKey NOTIFY secretKeyChanged)
    Q_PROPERTY(QString ext READ ext WRITE setExt NOTIFY extChanged)
public:
    static const QUrl HTTP_LINK;
    static const QUrl HTTPS_LINK;

    explicit DictConfig(QObject *parent = nullptr);
    ~DictConfig();
    void readFromFile(const QString &filename);

    enum Voice {Female = 0, Male};
    Q_ENUM(Voice)
    Q_PROPERTY(Voice voice READ voice WRITE setVoice NOTIFY voiceChanged)

    QString appKey() const;
    void setAppKey(const QString &appKey);

    QString ext() const;
    void setExt(const QString &ext);

    Voice voice() const;
    void setVoice(const Voice &voice);

    QUrl link() const;
    void setLink(const QUrl &link);

    QString secretKey() const;
    void setSecretKey(const QString &secretKey);

signals:

    void linkChanged(QUrl link);

    void appKeyChanged(QString appKey);

    void extChanged(QString ext);

    void voiceChanged(Voice voice);

    void secretKeyChanged(QString secretKey);

public slots:

private:
    QUrl m_link;
    QString m_appKey;
    QString m_secretKey;
    QString m_ext;
    Voice m_voice;
};

#endif // DICTCONFIG_H
