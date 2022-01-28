#include <iostream>

using namespace std;

#define PI 3.14 // 宏

#define MIN(a, b) (((a) > (b)) ? (b) : (a)) // 参数宏

#define DEBUG

/*
    #  运算符将后面的参数转为为用引号引起来的字符串
    ## 连接两个令牌
*/
#define TRANS(x) #x
#define CONN(x, y) x##y

void Test_DefineProcess(void) {
    cout << "PI is : "<< PI << endl;
    int i = 100;
    int j = 10;
    cout << "MIN(i, j) is : " << MIN(i, j) << endl;

#ifdef DEBUG
    cerr << "Trace: First" << endl;
#endif

#if 0
    /* 这是注释部分 */
    cout << "不会显示" << endl;
#endif

#ifdef DEBUG
    cerr << "Trace: Second" << endl;
#endif

    // define的拼接功能
    cout << TRANS(你好) << endl;
    string ab = "byebye";

    cout << CONN(a, b) << endl;

    cout << "_LINE_ : " << __LINE__ << endl;
    cout << "_FILE_ : " << __FILE__ << endl;
    cout << "_DATE_ : " << __DATE__ << endl;
    cout << "_TIME_ : " << __TIME__ << endl;
    return;

}