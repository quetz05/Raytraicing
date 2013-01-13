#include <QString>
#include <QtTest>
#include"vector_test.h"
//przykladowy test
class TestsTest : public QObject
{
    Q_OBJECT
    
public:
    TestsTest();
    
private Q_SLOTS:
    void testCase1();
};

TestsTest::TestsTest()
{
}

void TestsTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

int main(int argc, char** argv)
{
   int status = 0;
   {
      TestsTest tc;
      status |= QTest::qExec(&tc, argc, argv);
   }
   {
      VectorTest tc;
      status |= QTest::qExec(&tc, argc, argv);
   }

   return status;
}

#include "tst_teststest.moc"

