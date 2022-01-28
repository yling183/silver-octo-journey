#pragma once
#ifndef CLASSAPPLY_H_INCLUDE
#define CLASSAPPLY_H_INCLUDE

#include "iostream"

using namespace std;

/*
// 类的访问修饰符
// public: 共有成员在类的内外部均可访问，可以不使用任何成员函数来设置和获取公有变量的之
// private: 私有成员变量或者函数在类的外部是不可访问的，甚至不可查看，只有类和有缘函数可以访问私有成员；默认情况下类的所有成员都是私有的
// protected: 受保护成员或函数与私有成员相似，但受保护成员在派生类中是可访问的

// 继承：
                            基类
                          (public)     (protected)   (private)
    派生类public继承：      public       protected     private
    派生类protected继承：   protected    protected     private
    派生类private继承：     private      private       private
    private成员只能被本类成员（类内）和友元访问，不能被派生成访问
    protected成员可以被派生类访问

    类的构造函数和析构函数：
    构造函数：一类特殊的成员函数，在每次创建类的新对象时执行，名称与类的名称相同，不返回任何类型，可用于为某些成员变量设置初始值
    析构函数：在每次删除所创建的对象时执行，名称与类的名称完全相同，前面加（~）不返回任何值，不带有参数。用于跳出程序（关闭文件、释放内存）前释放资源

    //内联函数（inline）：
      如果一个函数是内联的，那么在编译时，编译器会把该函数的代码副本放置在每个调用该函数的地方
      在类定义中定义的函数都是内联函数，不论是否加了关键字inline

    // this指针
       每一个对象都能通过this指针来访问自己的地址，this指针是所有成员函数的隐含参数。在成员函数的内部，可以用来调用对象；
       友元函数没有this指针，因为友元不是类的成员，只有成员函数才有this指针


        友元：
            友元函数：类的友元函数是定义在类的外部，但有权访问类的私有成员和保护成员；友元函数不是类的成员函数
            友元类：整个类机器所有成员都是友元


        类的静态成员：使用static关键字修饰，无论创建多少个类的对象，静态成员都只有一个副本
                     静态成员在类的所有对象中是共享的，如果不存在其他的初始化语句，在创建第一个对象时，所有的静态数据都会被初始化为0，不能将静态成员的初始化放在类的定义中，但可以在类的外部通过使用范围解析运算符::来重新声明静态变量从而对他进行初始化

        静态成员函数：静态成员函数即使在类对象不存在的情况下也能被调用，静态函数只需使用类名加范围解析运算符::就可访问
        静态成员函数只能访问静态成员数据、其他静态成员函数和类外部的其他函数
        静态成员函数有一个类范围，他们不能访问类的 this 指针。您可以使用静态成员函数来判断类的某些对象是否已被创建。

        静态成员函数与普通成员函数的区别：
            （1）静态成员函数没有 this 指针，只能访问静态成员（包括静态成员变量和静态成员函数）。
            （2）普通成员函数有 this 指针，可以访问类中的任意成员；而静态成员函数没有 this 指针。


 */



class Box {

private:
    double height;
protected:
    double breadth;
public:
    double length;
    static int objectCount;
    Box() : height(0), breadth(0), length(0) { // 构造函数，使用初始化列表进行初始化
        cout << "box is been created!" << endl;
        objectCount++;
    }

    ~Box() { // 析构函数
        cout << "box is been deleted!" << endl;
    }

    // 成员函数,定义在类内部的函数默认为内联函数不论是否有inline与否
    double get(void) {
        return length * breadth * height;
    }

    int compare(Box box)
    {
        return this->get() > box.get();
    }

    void set(double len, double bre, double hei);
    double getHeight(void); 
    friend double getWidth(Box box);  // 友元函数，他不是任何类的成员函数
    friend class BigBox; // 友元类

};


class myBox : public Box {
public:
    double getBreadth(void) {
        return breadth;
    }
    myBox() {
        cout << "myBox is been created!" << endl;
    }
    ~myBox() {
        cout << "myBox is been deleted!" << endl;
    }
};
class BigBox {
public:
    void Print(Box& box) {
        // // BigBox是Box的友元类，它可以直接访问Box类的任何成员
        box.set(1, 2, 3);
        cout << "length: " << box.length << " breadth: " << box.breadth << " height: " << box.height << endl;
    }
};


/*

    拷贝构造函数：一种特殊的构造函数，在创建对象时，使用同一类中之前创建的对象来初始化新创建的对象。通常用于：
    （1）通过使用另一个同类型的对象来初始化新创建的对象
    （2）复制对象把它作为参数传递给函数
    （3）复制对象，并从函数返回这个对象
    若未定义拷贝构造函数，编译器会自行定义。如果类带有指针变量，并由动态内存分配，则必须有一个拷贝构造函数 classname (const classname &obj){}

*/
class Line {
public:
    int getLength(void);
    Line(int len);
    Line(const Line& obj);
    ~Line();

private:
    int* ptr;
};


/* 
   基类 & 派生类
   被继承的类为基类，继承的类为派生类，一个派生类可以继承多个基类
   派生类可以访问基类中所有的非私有成员。因此基类成员如果不想被派生类的成员函数访问，则应在基类中声明为 private。
   多继承：class derived-class: access-specifier base-class1， access-specifier base-class2

    访问	       public	protected	private
    同一个类 	yes	    yes	         yes
    派生类	    yes	    yes	          no
    外部的类	    yes  	no	          no
    公有继承的派生类的对象只能访问基类的公有成员，不能访问保护成员和私有成员
*/

// 基类 Shape
class Shape {

    public:
        void setWidth(int w)
        {
            width = w;
        }
        void setHeight(int h)
        {
            height = h;
        }
        int getHeight() {
            return height;
        }
    protected:
        int width;
    private:
        int height;
};
// 基类 PaintCost
class PaintCost
{
    public:
        int getCost(int area)
        {
            return area * 70;
        }
};

//派生类
class Rectangle : public Shape, public PaintCost {
    public:
        int getWidth() {
            return width; // 可以访问基类中的protected成员
        }
        int getHeight_0() {
            return getHeight();
            //return height; // ERR : 不可以访问基类中的private成员
        }
        int getArea() {
            return width * getHeight_0();
        }
};


/*
    函数重载：在同一个作用域内，可声明几个功能类似的同名函数，但这些同名函数的形式参数不同
    运算符重载：重载的运算符是带有特殊名称的函数，函数名是由关键字 operator 和其后要重载的运算符符号构成的。与其他函数一样，重载运算符有一个返回类型和一个参数列表。
    Box operator+(const Box&);
*/

class Time {
    private:
        int hours;
        int minutes;
    public:
        Time() {
            hours = 0;
            minutes = 0;
        }
        Time(int h, int m) {
            hours = h;
            minutes = m;
        }
        // 显示时间的方法
        void displayTime()
        {
            cout << "H: " << hours << " M:" << minutes << endl;
        }

        // 重载前缀递增运算符++
        Time operator ++() {
            ++minutes;
            if (minutes >= 60) {
                ++hours;
                minutes -= 60;
            }
            return Time(hours, minutes);
        }

        // 重载后缀递增运算符（ ++ ）
        Time operator++(int)
        {
            // 保存原始值
            Time T(hours, minutes);
            // 对象加 1
            ++minutes;
            if (minutes >= 60)
            {
                ++hours;
                minutes -= 60;
            }
            // 返回旧的原始值
            return T;
        }
};

class Check
{
    private:
        int i;
    public:
        Check() : i(0) {  }
        Check operator ++ ()
        {
            Check temp;
            temp.i = ++i;
            return temp;
        }

        // 括号中插入 int 表示后缀
        Check operator ++ (int)
        {
            Check temp;
            temp.i = i++;
            return temp;
        }

        void Display()
        {
            cout << "i = " << i << endl;
        }
};

/*
    多态：
        当类之间存在层次结构，且类之间时通过继承关联时会用到多态
        在调用成员函数时，会根据调用函数的对象类型来执行不同的函数
    虚函数：
        在基类中使用关键字virtual声明的函数，在派生类中重新定义基类中定义的虚函数时会告诉编译器不要静态链接到该函数
        需要在程序中任意点根据所调用的对象类型类选择调用的函数，称作动态链接或后期绑定
    纯虚函数：
        想要在基类中定义虚函数，以便在派生类中重新定义该函数更好地适用于对象，但是您在基类中又不能对虚函数给出有意义的实现，这个时候就会用到纯虚函数。
        带有纯虚函数的类叫做抽象类(ABC)，不能用来实例化对象,只能作为接口使用；如果一个ABC的子类需要被实例化，则必须实现每一个虚函数；
        如果没有在派生类中重写虚函数就尝试实例化对象的类，会导致编译错误

*/
class animal {
    
    public:
        int leg;
        animal() {
            leg = 0;
        }
        ~animal() {};
        virtual void setLegs() = 0; // 只提供接口框架的纯虚函数；
        int GetNumOfLegs() {
            return leg;
        }
};

class rabbit : public animal {
    public:
        void setLegs() {
            leg = 4;
        }
};

class chick : public animal {
public:
    void setLegs() {
        leg = 2;
    }
};

/*
    explict关键字：
        指定仅有一个参数或者除第一个参数外其他参数均有默认值的类构造函数不能作为类型转化操作符被隐含的使用，防止该类的对象直接被对应内置类型隐式转换后赋值，
        从而规定这个构造函数必须被明确调用

*/
class Test1 {
    public:
        Test1(int num) : n(num) {}
    private:
        int n;
};

class Test2 {
public:
    explicit Test2(int num) : n(num) {}
private:
    int n;
};



void Test_Class(void);
void TestClassCopy(void);
void Test_Derive(void);
void Test_Time(void);
void Test_Virtual(void);
void Test_EXPLICIT(void);

#endif
