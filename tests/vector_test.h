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
    void testCase1();
};
#endif // VECTOR_TEST_H
