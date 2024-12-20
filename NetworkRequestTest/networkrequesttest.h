#ifndef NETWORKREQUESTTEST_H
#define NETWORKREQUESTTEST_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>

QT_BEGIN_NAMESPACE
namespace Ui {
class NetworkRequestTest;
}
QT_END_NAMESPACE

class NetworkRequestTest : public QWidget
{
    Q_OBJECT

public:
    NetworkRequestTest(QWidget *parent = nullptr);
    ~NetworkRequestTest();

public:
    void initNetworkAccessMgr(void);

public slots:
    void requestGetReplyFinished(QNetworkReply *reply);

public:
    QNetworkAccessManager *m_RequestNetworkAccessMgr;

private slots:
    void on_pushButton_clicked();

private:
    Ui::NetworkRequestTest *ui;
};
#endif // NETWORKREQUESTTEST_H
