
#include"vector_test.h"

VectorTest::VectorTest(){
}

void VectorTest::testsum(){
    Vector3 v(0,0,0);
    v=v+Vector3(0,0,0);
    QVERIFY(v.getX()==0);
    QVERIFY(v.getY()==0);
    QVERIFY(v.getZ()==0);
    v=v+Vector3(1,2,3);
    QVERIFY(v.getX()==1);
    QVERIFY(v.getY()==2);
    QVERIFY(v.getZ()==3);
    v=v+Vector3(-1,-2,-3);
    QVERIFY(v.getX()==0);
    QVERIFY(v.getY()==0);
    QVERIFY(v.getZ()==0);
}

void VectorTest::testsub(){
    Vector3 v(0,0,0);
    v=v-Vector3(0,0,0);
    QVERIFY(v.getX()==0);
    QVERIFY(v.getY()==0);
    QVERIFY(v.getZ()==0);
    v=v-Vector3(1,2,3);
    QVERIFY(v.getX()==-1);
    QVERIFY(v.getY()==-2);
    QVERIFY(v.getZ()==-3);
    v=v-Vector3(-1,-2,-3);
    QVERIFY(v.getX()==0);
    QVERIFY(v.getY()==0);
    QVERIFY(v.getZ()==0);
}

void VectorTest::testmul(){
    Vector3 v(0,0,0);
    v=v*5;
    QVERIFY(v.getX()==0);
    QVERIFY(v.getY()==0);
    QVERIFY(v.getZ()==0);
    v=Vector3(1,2,3);
    v=v*1;
    QVERIFY(v.getX()==1);
    QVERIFY(v.getY()==2);
    QVERIFY(v.getZ()==3);
    v=v*2;
    QVERIFY(v.getX()==2);
    QVERIFY(v.getY()==4);
    QVERIFY(v.getZ()==6);
}

void VectorTest::testdiv(){
    Vector3 v(1,1,1);
    v=v/0.5;
    QVERIFY(v.getX()==2);
    QVERIFY(v.getY()==2);
    QVERIFY(v.getZ()==2);
    v=v/0;
}

void VectorTest::testattr(){
    Vector3 v(1,1,1);
    Vector3 c(2,2,2);
    v=c;
    QVERIFY(v.getX()==2);
    QVERIFY(v.getY()==2);
    QVERIFY(v.getZ()==2);
}

void VectorTest::testequal(){
    Vector3 v(1,1,1);
    QVERIFY(v==v);
    Vector3 w=v;
    QVERIFY(v==w);
}

void VectorTest::testdot(){
    Vector3 v(1,1,1);
    Vector3 w(1,1,1);
    double k=v.dot(w);
    QVERIFY(k==3);

}

void VectorTest::testcross(){
    Vector3 v(2,1,2);
    Vector3 w(3,1,1);
    w =v.cross(w);

    QVERIFY(w.getX()==-1);
    QVERIFY(w.getY()==4);
    QVERIFY(w.getZ()==-1);

}

void VectorTest::testlen(){
    Vector3 v(1,0,0);
    QVERIFY(v.get_length()==1);
    v=Vector3(0,2,0);
    QVERIFY(v.get_length()==2);
}

void VectorTest::testlensq(){
    Vector3 v(1,0,0);
    QVERIFY(v.get_length_sq()==1);
    v=Vector3(2,2,2);
    QVERIFY(v.get_length_sq()==12);
}

void VectorTest::testnorm(){
    Vector3 v(5,5,5);
    v=v.normalized();
    QVERIFY(v.get_length()==1);
}
