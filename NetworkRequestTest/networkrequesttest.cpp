#include "networkrequesttest.h"
#include "ui_networkrequesttest.h"

const QUrl REQUEST_URL(QUrl("https://api.github.com/repos/Zalafina/QKeyMapper/releases/latest"));
const char *UPDATER_USER_AGENT_X64 = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0";

NetworkRequestTest::NetworkRequestTest(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NetworkRequestTest)
    , m_RequestNetworkAccessMgr(Q_NULLPTR)
{
    ui->setupUi(this);

    m_RequestNetworkAccessMgr = new QNetworkAccessManager();
    initNetworkAccessMgr();
}

NetworkRequestTest::~NetworkRequestTest()
{
    delete ui;
}

void NetworkRequestTest::initNetworkAccessMgr(void)
{
    Q_ASSERT(m_RequestNetworkAccessMgr != NULL);

    if (m_RequestNetworkAccessMgr != NULL){
        QObject::connect(m_RequestNetworkAccessMgr, &QNetworkAccessManager::finished, this, &NetworkRequestTest::requestGetReplyFinished);
    }
}

void NetworkRequestTest::requestGetReplyFinished(QNetworkReply *reply)
{
    QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    qDebug() << "[requestGetReplyFinished] RequestGet Reply HttpStatusCode:" << status_code.toInt();

    ui->textBrowser->clear();
    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();

        ui->textBrowser->setText(QString(bytes));
    }
    else{
        QByteArray bytes = reply->readAll();

        ui->textBrowser->setText(QString(bytes));

        qDebug() << "[requestGetReplyFinished] reply error :" << reply->error() << ", HttpStatusCode:" << status_code.toInt() << ", ErrorString :" << reply->errorString();
        m_RequestNetworkAccessMgr->clearAccessCache();
    }

    reply->deleteLater();
}

void NetworkRequestTest::on_pushButton_clicked()
{
    QString user_agent = UPDATER_USER_AGENT_X64;

    QNetworkRequest request;
    request.setUrl(REQUEST_URL);
    request.setRawHeader("User-Agent", user_agent.toLatin1());

    m_RequestNetworkAccessMgr->get(request);
}

