#ifndef VECTOR_TEST_H
#define VECTOR_TEST_H
#include"../vector.h"
#include<QTest>
class VectorTest : public QObject
{
    Q_OBJECT

public:
    VectorTest();


private Q_SLOTS:
    void testsum();
    void testsub();
    void testmul();
    void testdiv();
    void testattr();
    void testequal();
    void testdot();
    void testcross();
    void testlen();
    void testlensq();
    void testnorm();
};
#endif // VECTOR_TEST_H
