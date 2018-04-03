#include <QString>
#include <QtTest>
#include "../src/cascade.h"
#include "plaingadget.h"

class TestTest : public QObject
{
    Q_OBJECT

public:
    TestTest() {}

private Q_SLOTS:
    void plainTest();
    void warnTest();
};

void TestTest::plainTest()
{
    auto json = QJsonObject {
        {"propInt", 1},
        {"propString", "qwerty"},
        {"propBool", true},
    };
    auto result = Cascade::from<PlainGadget>(json);
    QVERIFY(result.propInt == 1);
    QVERIFY(result.propString == "qwerty");
    QVERIFY(result.propBool == true);
}

void TestTest::warnTest()
{
    QList<int> intList = {1, 2, 3, 4, 5};
    auto json = QJsonObject {
        {"intList", QJsonValue::fromVariant(QVariant::fromValue(intList))},
    };
    auto result = Cascade::from<PlainGadget>(json);
    QVERIFY(result.intList.isEmpty());
}

QTEST_APPLESS_MAIN(TestTest)

#include "tst_testtest.moc"
