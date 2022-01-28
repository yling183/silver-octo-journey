#pragma once
#ifndef CLASSAPPLY_H_INCLUDE
#define CLASSAPPLY_H_INCLUDE

#include "iostream"

using namespace std;

/*
// ��ķ������η�
// public: ���г�Ա��������ⲿ���ɷ��ʣ����Բ�ʹ���κγ�Ա���������úͻ�ȡ���б�����֮
// private: ˽�г�Ա�������ߺ���������ⲿ�ǲ��ɷ��ʵģ��������ɲ鿴��ֻ�������Ե�������Է���˽�г�Ա��Ĭ�������������г�Ա����˽�е�
// protected: �ܱ�����Ա������˽�г�Ա���ƣ����ܱ�����Ա�����������ǿɷ��ʵ�

// �̳У�
                            ����
                          (public)     (protected)   (private)
    ������public�̳У�      public       protected     private
    ������protected�̳У�   protected    protected     private
    ������private�̳У�     private      private       private
    private��Աֻ�ܱ������Ա�����ڣ�����Ԫ���ʣ����ܱ������ɷ���
    protected��Ա���Ա����������

    ��Ĺ��캯��������������
    ���캯����һ������ĳ�Ա��������ÿ�δ�������¶���ʱִ�У����������������ͬ���������κ����ͣ�������ΪĳЩ��Ա�������ó�ʼֵ
    ������������ÿ��ɾ���������Ķ���ʱִ�У����������������ȫ��ͬ��ǰ��ӣ�~���������κ�ֵ�������в����������������򣨹ر��ļ����ͷ��ڴ棩ǰ�ͷ���Դ

    //����������inline����
      ���һ�������������ģ���ô�ڱ���ʱ����������Ѹú����Ĵ��븱��������ÿ�����øú����ĵط�
      ���ඨ���ж���ĺ����������������������Ƿ���˹ؼ���inline

    // thisָ��
       ÿһ��������ͨ��thisָ���������Լ��ĵ�ַ��thisָ�������г�Ա�����������������ڳ�Ա�������ڲ��������������ö���
       ��Ԫ����û��thisָ�룬��Ϊ��Ԫ������ĳ�Ա��ֻ�г�Ա��������thisָ��


        ��Ԫ��
            ��Ԫ�����������Ԫ�����Ƕ���������ⲿ������Ȩ�������˽�г�Ա�ͱ�����Ա����Ԫ����������ĳ�Ա����
            ��Ԫ�ࣺ������������г�Ա������Ԫ


        ��ľ�̬��Ա��ʹ��static�ؼ������Σ����۴������ٸ���Ķ��󣬾�̬��Ա��ֻ��һ������
                     ��̬��Ա��������ж������ǹ���ģ���������������ĳ�ʼ����䣬�ڴ�����һ������ʱ�����еľ�̬���ݶ��ᱻ��ʼ��Ϊ0�����ܽ���̬��Ա�ĳ�ʼ��������Ķ����У�������������ⲿͨ��ʹ�÷�Χ���������::������������̬�����Ӷ��������г�ʼ��

        ��̬��Ա��������̬��Ա������ʹ������󲻴��ڵ������Ҳ�ܱ����ã���̬����ֻ��ʹ�������ӷ�Χ���������::�Ϳɷ���
        ��̬��Ա����ֻ�ܷ��ʾ�̬��Ա���ݡ�������̬��Ա���������ⲿ����������
        ��̬��Ա������һ���෶Χ�����ǲ��ܷ������ this ָ�롣������ʹ�þ�̬��Ա�������ж����ĳЩ�����Ƿ��ѱ�������

        ��̬��Ա��������ͨ��Ա����������
            ��1����̬��Ա����û�� this ָ�룬ֻ�ܷ��ʾ�̬��Ա��������̬��Ա�����;�̬��Ա��������
            ��2����ͨ��Ա������ this ָ�룬���Է������е������Ա������̬��Ա����û�� this ָ�롣


 */



class Box {

private:
    double height;
protected:
    double breadth;
public:
    double length;
    static int objectCount;
    Box() : height(0), breadth(0), length(0) { // ���캯����ʹ�ó�ʼ���б���г�ʼ��
        cout << "box is been created!" << endl;
        objectCount++;
    }

    ~Box() { // ��������
        cout << "box is been deleted!" << endl;
    }

    // ��Ա����,���������ڲ��ĺ���Ĭ��Ϊ�������������Ƿ���inline���
    double get(void) {
        return length * breadth * height;
    }

    int compare(Box box)
    {
        return this->get() > box.get();
    }

    void set(double len, double bre, double hei);
    double getHeight(void); 
    friend double getWidth(Box box);  // ��Ԫ�������������κ���ĳ�Ա����
    friend class BigBox; // ��Ԫ��

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
        // // BigBox��Box����Ԫ�࣬������ֱ�ӷ���Box����κγ�Ա
        box.set(1, 2, 3);
        cout << "length: " << box.length << " breadth: " << box.breadth << " height: " << box.height << endl;
    }
};


/*

    �������캯����һ������Ĺ��캯�����ڴ�������ʱ��ʹ��ͬһ����֮ǰ�����Ķ�������ʼ���´����Ķ���ͨ�����ڣ�
    ��1��ͨ��ʹ����һ��ͬ���͵Ķ�������ʼ���´����Ķ���
    ��2�����ƶ��������Ϊ�������ݸ�����
    ��3�����ƶ��󣬲��Ӻ��������������
    ��δ���忽�����캯���������������ж��塣��������ָ����������ɶ�̬�ڴ���䣬�������һ���������캯�� classname (const classname &obj){}

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
   ���� & ������
   ���̳е���Ϊ���࣬�̳е���Ϊ�����࣬һ����������Լ̳ж������
   ��������Է��ʻ��������еķ�˽�г�Ա����˻����Ա������뱻������ĳ�Ա�������ʣ���Ӧ�ڻ���������Ϊ private��
   ��̳У�class derived-class: access-specifier base-class1�� access-specifier base-class2

    ����	       public	protected	private
    ͬһ���� 	yes	    yes	         yes
    ������	    yes	    yes	          no
    �ⲿ����	    yes  	no	          no
    ���м̳е�������Ķ���ֻ�ܷ��ʻ���Ĺ��г�Ա�����ܷ��ʱ�����Ա��˽�г�Ա
*/

// ���� Shape
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
// ���� PaintCost
class PaintCost
{
    public:
        int getCost(int area)
        {
            return area * 70;
        }
};

//������
class Rectangle : public Shape, public PaintCost {
    public:
        int getWidth() {
            return width; // ���Է��ʻ����е�protected��Ա
        }
        int getHeight_0() {
            return getHeight();
            //return height; // ERR : �����Է��ʻ����е�private��Ա
        }
        int getArea() {
            return width * getHeight_0();
        }
};


/*
    �������أ���ͬһ���������ڣ������������������Ƶ�ͬ������������Щͬ����������ʽ������ͬ
    ��������أ����ص�������Ǵ����������Ƶĺ��������������ɹؼ��� operator �����Ҫ���ص���������Ź��ɵġ�����������һ���������������һ���������ͺ�һ�������б�
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
        // ��ʾʱ��ķ���
        void displayTime()
        {
            cout << "H: " << hours << " M:" << minutes << endl;
        }

        // ����ǰ׺���������++
        Time operator ++() {
            ++minutes;
            if (minutes >= 60) {
                ++hours;
                minutes -= 60;
            }
            return Time(hours, minutes);
        }

        // ���غ�׺����������� ++ ��
        Time operator++(int)
        {
            // ����ԭʼֵ
            Time T(hours, minutes);
            // ����� 1
            ++minutes;
            if (minutes >= 60)
            {
                ++hours;
                minutes -= 60;
            }
            // ���ؾɵ�ԭʼֵ
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

        // �����в��� int ��ʾ��׺
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
    ��̬��
        ����֮����ڲ�νṹ������֮��ʱͨ���̳й���ʱ���õ���̬
        �ڵ��ó�Ա����ʱ������ݵ��ú����Ķ���������ִ�в�ͬ�ĺ���
    �麯����
        �ڻ�����ʹ�ùؼ���virtual�����ĺ������������������¶�������ж�����麯��ʱ����߱�������Ҫ��̬���ӵ��ú���
        ��Ҫ�ڳ������������������õĶ���������ѡ����õĺ�����������̬���ӻ���ڰ�
    ���麯����
        ��Ҫ�ڻ����ж����麯�����Ա��������������¶���ú������õ������ڶ��󣬵������ڻ������ֲ��ܶ��麯�������������ʵ�֣����ʱ��ͻ��õ����麯����
        ���д��麯���������������(ABC)����������ʵ��������,ֻ����Ϊ�ӿ�ʹ�ã����һ��ABC��������Ҫ��ʵ�����������ʵ��ÿһ���麯����
        ���û��������������д�麯���ͳ���ʵ����������࣬�ᵼ�±������

*/
class animal {
    
    public:
        int leg;
        animal() {
            leg = 0;
        }
        ~animal() {};
        virtual void setLegs() = 0; // ֻ�ṩ�ӿڿ�ܵĴ��麯����
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
    explict�ؼ��֣�
        ָ������һ���������߳���һ��������������������Ĭ��ֵ���๹�캯��������Ϊ����ת����������������ʹ�ã���ֹ����Ķ���ֱ�ӱ���Ӧ����������ʽת����ֵ��
        �Ӷ��涨������캯�����뱻��ȷ����

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
