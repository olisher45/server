#include <QtTest>

#include "../server/server.h"
#include <QDebug>

class server_test : public QObject
{
    Q_OBJECT

public:
    server_test();
    ~server_test();

private slots:
    void test_case1();
    void test_case2();
    void test_case3();
};

server_test::server_test()
{

}

server_test::~server_test()
{

}

void server_test::test_case1()
{
    QVERIFY(Server::getInstance()->parse("123") == QByteArray(QString("invalid_arguments").toUtf8()));
}


void server_test::test_case2()
{
    QVERIFY(Server::getInstance()->parse("12345") == QByteArray(QString("invalid_arguments").toUtf8()));
    QVERIFY(Server::getInstance()->parse("12345") == QByteArray(QString("invalid_arguments").toUtf8()));
}

void server_test::test_case3()
{
    qDebug() << Server::getInstance()->parse("task -1 2 4640 ABC+AB+B+C");
    QVERIFY(Server::getInstance()->parse("task -1 2 4640 ABC+AB+B+C") == QByteArray(QString("task_is_done$0").toUtf8()));
}


QTEST_APPLESS_MAIN(server_test)

#include "tst_server_test.moc"
