#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class HttpClient : public QObject
{
    Q_OBJECT
public:
    explicit HttpClient(QObject *parent = nullptr);
    void loginUser(const QString &username, const QString &password);
    void registerUser(const QString &username, const QString &password, const QString &email);

signals:
    void loginSuccess();
    void loginFailure(const QString &message);
    void registrationSuccess();
    void registrationFailure(const QString &message);

private slots:
    void onLoginFinished(QNetworkReply *reply);
    void onRegisterFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager *networkManager;
};

#endif // HTTPCLIENT_H
