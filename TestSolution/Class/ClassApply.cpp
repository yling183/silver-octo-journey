#include <iostream>
#include "ClassApply.h"

using namespace std;



void Box::set(double len, double bre, double hei) {
    length = len;
    breadth = bre;
    height = hei;
}

double Box::getHeight(void) {
    return height;
}

double getWidth(Box box) {
    return box.breadth;
}

int Box::objectCount = 0;
void Test_Class(void) {
    Box box1;
    cout << "box1�ĳ��ȣ�" << box1.length << endl;
    Box box2;
    Box box3;
    myBox mybox1;
    BigBox bigbox;
    Box* pbox1 = &box1;
    cout << "box1�ĳ��ȣ�" << pbox1->length << endl;
    cout << "box1�������" << pbox1->get() << endl;

    box1.set(1, 2, 3);
    box2.set(4, 5, 6);
    box3.set(1.6, 2.7, 3.9);
    mybox1.set(5, 6, 9); // ��������Է��ʻ����еĹ��г�Ա���ܱ�����ĳ�Ա

    cout << "Total objects:�� " << Box::objectCount << endl;
    cout << "box3�ĸ߶ȣ� " << box3.getHeight() << endl;
    // cout << "box3�ĸ߶ȣ� " << box3.height << endl;  // �������˽�г�Ա������ⲿ����ֱ�ӷ��ʣ����ù����к���getHeight������
    cout << "box1 �������" << box1.get() << endl;
    cout << "box2 �������" << box2.get() << endl;
    cout << "box3 �������" << box3.get() << endl;

    cout << "myBox1�Ŀ�ȣ� " << mybox1.getBreadth() << endl;
    // cout << "myBox1�Ŀ�ȣ� " << mybox1.breadth << endl; // �����ܱ�����Ա���������пɷ��ʣ��������ⲿ���ܷ���

    bigbox.Print(box1);
    if (box1.compare(box2)) {
        cout << "box1 is bigger!" << endl;
    }
    else {
        cout << "box2 is bigger!" << endl;
    }

}




// ��Ա�������壬�������캯��
Line::Line(int len)
{
    cout << "���ù��캯��" << endl;
    // Ϊָ������ڴ�
    ptr = new int;
    *ptr = len;
}

Line::Line(const Line& obj)
{
    cout << "���ÿ������캯����Ϊָ�� ptr �����ڴ�" << endl;
    ptr = new int;
    *ptr = *obj.ptr; // ����ֵ
}

Line::~Line(void)
{
    cout << "�ͷ��ڴ�" << endl;
    delete ptr;
}
int Line::getLength(void)
{
    return *ptr;
}

void display(Line obj)
{
    cout << "line ��С : " << obj.getLength() << endl;
}

void TestClassCopy(void) {
    Line line1(10);
    Line line2 = line1;
    display(line1);
    display(line2);
}

void Test_Derive(void) {
    Rectangle rec;
    rec.setWidth(3);
    rec.setHeight(4);
    cout << "The height of rec is: " << rec.getHeight_0() << endl;
    cout << "The Area of rec is: " << rec.getArea() << endl;
    cout << "The Cost of rec is: " << rec.getCost(rec.getArea()) << endl;
}

void Test_Time(void) {
    Time T1(11, 59);
    Time T2(10, 40);

    ++T1;                    // T1 �� 1
    T1.displayTime();        // ��ʾ T1
    ++T1;                    // T1 �ټ� 1
    T1.displayTime();        // ��ʾ T1

    T2++;                    // T2 �� 1
    T2.displayTime();        // ��ʾ T2
    T2++;                    // T2 �ټ� 1
    T2.displayTime();        // ��ʾ T2

    Check obj, obj1;
    obj.Display();
    obj1.Display();

    // ���������������Ȼ�� obj ��ֵ���� obj1
    obj1 = ++obj;
    obj.Display();
    obj1.Display();

    // �� obj ��ֵ�� obj1, Ȼ���ٵ������������
    obj1 = obj++;
    obj.Display();
    obj1.Display();
}

void Test_Virtual(void) {
    // animal ani; // Error��animal���д��麯����Ϊ�����࣬��������ʵ��������
    rabbit rab;
    chick chi;

    rab.setLegs();
    chi.setLegs();

    cout << "A rabbit has " << rab.GetNumOfLegs() << " legs" << endl;
    cout << "A chick has " << chi.GetNumOfLegs() << " legs" << endl;
}

void Test_EXPLICIT(void) {
    Test1 t1 = 12; // ����OK,�๹�캯������explict�ؼ��ӣ��ɽ�����ʽת��,n = 12
    Test2 t2(13);  // ����OK����ʾת�� n = 13
   // Test2 t3 = 14; // Error���������, ��ʾ�޷���int����ת��ΪTest2���ͣ� ��ΪTest2���캯�����explict�ؼ�����ֹ����ʽת��

    system("pause");
}

