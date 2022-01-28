#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdexcept>

using namespace std;

// 函数模板
/*
    template <typename type> ret-type func-name(parameter list)
    {
       // 函数的主体
    }
*/
template <typename T>
inline T const& Max(T const& a, T const& b) {
	return (a > b) ? a : b;
}

void Test_TempLate_Func(void) {
    int i = 39;
    int j = 20;
    cout << "Max(i, j): " << Max(i, j) << endl;

    double f1 = 13.5;
    double f2 = 20.7;
    cout << "Max(f1, f2): " << Max(f1, f2) << endl;

    string s1 = "Hello";
    string s2 = "World";
    cout << "Max(s1, s2): " << Max(s1, s2) << endl;
}

// 类模板
/*
    template <class type> class class-name {
    .
    }
*/

template <class T> class Stack {
private:
    vector<T> elems;
public:
    void push(T const&);  // 加入元素
    void pop(); // 弹出元素
    T top() const; // 栈顶元素
    bool empty() const { // 栈是否为空
        return elems.empty();
    }
};

template <class T> void Stack<T>::push(T const& elem) {
    elems.push_back(elem);
}

template <class T> void Stack<T> ::pop() {
    if (elems.empty()) {
        throw out_of_range("Stack<>::pop():empty stack");
    }
    elems.pop_back();
}

template <class T> T Stack<T>::top() const {
    if (elems.empty()) {
        throw out_of_range("Stack<>::top():empty stack");
    }
    return elems.back();
}

void Test_TempLate_Class(void) {
    try {
        Stack<int> intStack; // int类型的栈
        Stack<string> stringStack; // string类型的栈

        intStack.push(7);
        intStack.push(10);
        cout << "intStack's status(empty or not): " << intStack.empty() << endl;
        cout << "intStack's top elem is : " << intStack.top() << endl;
        intStack.pop();
        intStack.pop();
        cout << "intStack's status(empty or not): " << intStack.empty() << endl;
        // cout << "intStack's top elem is : " << intStack.top() << endl;

        stringStack.push("Hello");
        cout << "stringStack's top elem is : " << stringStack.top() << endl;
        cout << "stringStack's status(empty or not): " << stringStack.empty() << endl;
        stringStack.pop();
        cout << "stringStack's status(empty or not): " << stringStack.empty() << endl;
        cout << "stringStack's top elem is : " << stringStack.top() << endl;
    }
    catch (exception const& ex) {
        cerr << "Exception : " << ex.what() << endl;
    }
}





