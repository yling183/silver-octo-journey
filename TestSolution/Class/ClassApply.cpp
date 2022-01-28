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
    cout << "box1的长度：" << box1.length << endl;
    Box box2;
    Box box3;
    myBox mybox1;
    BigBox bigbox;
    Box* pbox1 = &box1;
    cout << "box1的长度：" << pbox1->length << endl;
    cout << "box1的体积：" << pbox1->get() << endl;

    box1.set(1, 2, 3);
    box2.set(4, 5, 6);
    box3.set(1.6, 2.7, 3.9);
    mybox1.set(5, 6, 9); // 派生类可以访问基类中的公有成员和受保护类的成员

    cout << "Total objects:： " << Box::objectCount << endl;
    cout << "box3的高度： " << box3.getHeight() << endl;
    // cout << "box3的高度： " << box3.height << endl;  // 错误：类的私有成员在类的外部不可直接访问，可用过共有函数getHeight来访问
    cout << "box1 的体积：" << box1.get() << endl;
    cout << "box2 的体积：" << box2.get() << endl;
    cout << "box3 的体积：" << box3.get() << endl;

    cout << "myBox1的宽度： " << mybox1.getBreadth() << endl;
    // cout << "myBox1的宽度： " << mybox1.breadth << endl; // 错误，受保护成员在派生类中可访问，但在类外部不能访问

    bigbox.Print(box1);
    if (box1.compare(box2)) {
        cout << "box1 is bigger!" << endl;
    }
    else {
        cout << "box2 is bigger!" << endl;
    }

}




// 成员函数定义，包括构造函数
Line::Line(int len)
{
    cout << "调用构造函数" << endl;
    // 为指针分配内存
    ptr = new int;
    *ptr = len;
}

Line::Line(const Line& obj)
{
    cout << "调用拷贝构造函数并为指针 ptr 分配内存" << endl;
    ptr = new int;
    *ptr = *obj.ptr; // 拷贝值
}

Line::~Line(void)
{
    cout << "释放内存" << endl;
    delete ptr;
}
int Line::getLength(void)
{
    return *ptr;
}

void display(Line obj)
{
    cout << "line 大小 : " << obj.getLength() << endl;
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

    ++T1;                    // T1 加 1
    T1.displayTime();        // 显示 T1
    ++T1;                    // T1 再加 1
    T1.displayTime();        // 显示 T1

    T2++;                    // T2 加 1
    T2.displayTime();        // 显示 T2
    T2++;                    // T2 再加 1
    T2.displayTime();        // 显示 T2

    Check obj, obj1;
    obj.Display();
    obj1.Display();

    // 调用运算符函数，然后将 obj 的值赋给 obj1
    obj1 = ++obj;
    obj.Display();
    obj1.Display();

    // 将 obj 赋值给 obj1, 然后再调用运算符函数
    obj1 = obj++;
    obj.Display();
    obj1.Display();
}

void Test_Virtual(void) {
    // animal ani; // Error：animal中有纯虚函数，为抽象类，不能用来实例化对象
    rabbit rab;
    chick chi;

    rab.setLegs();
    chi.setLegs();

    cout << "A rabbit has " << rab.GetNumOfLegs() << " legs" << endl;
    cout << "A chick has " << chi.GetNumOfLegs() << " legs" << endl;
}

void Test_EXPLICIT(void) {
    Test1 t1 = 12; // 编译OK,类构造函数中五explict关键子，可进行隐式转换,n = 12
    Test2 t2(13);  // 编译OK，显示转换 n = 13
   // Test2 t3 = 14; // Error：编译出错, 提示无法将int类型转换为Test2类型， 因为Test2构造函数里的explict关键字阻止了隐式转换

    system("pause");
}

