#include <QString>
#include <QtTest>
#include "../cascade.h"
#include "plaingadget.h"

class TestTest : public QObject
{
    Q_OBJECT

public:
    TestTest(){}

private Q_SLOTS:
    void plainTest();
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

QTEST_APPLESS_MAIN(TestTest)

#include "tst_testtest.moc"
