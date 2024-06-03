#include "HttpClient.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkRequest>

HttpClient::HttpClient(QObject *parent) : QObject(parent)
{
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, &QNetworkAccessManager::finished, this, &HttpClient::onLoginFinished);
}

void HttpClient::loginUser(const QString &username, const QString &password)
{
    QUrl url("http://127.0.0.1:5000/login");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["username"] = username;
    json["password"] = password;

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    networkManager->post(request, data);
}

void HttpClient::registerUser(const QString &username, const QString &password)
{
    QUrl url("http://127.0.0.1:5000/register");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["username"] = username;
    json["password"] = password;

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    connect(networkManager, &QNetworkAccessManager::finished, this, &HttpClient::onRegistrationFinished);
    networkManager->post(request, data);
}

void HttpClient::onLoginFinished(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        QJsonObject json = doc.object();
        if (json["status"] == "success") {
            emit loginSuccess();
        } else {
            emit loginFailure(json["message"].toString());
        }
    } else {
        emit loginFailure(reply->errorString());
    }
    reply->deleteLater();
}

void HttpClient::onRegistrationFinished(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        QJsonObject json = doc.object();
        if (json["status"] == "success") {
            emit registrationSuccess();
        } else {
            emit registrationFailure(json["message"].toString());
        }
    } else {
        emit registrationFailure(reply->errorString());
    }
    reply->deleteLater();
}
