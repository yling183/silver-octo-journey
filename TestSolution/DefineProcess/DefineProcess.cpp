#include <iostream>

using namespace std;

#define PI 3.14 // ��

#define MIN(a, b) (((a) > (b)) ? (b) : (a)) // ������

#define DEBUG

/*
    #  �����������Ĳ���תΪΪ���������������ַ���
    ## ������������
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
    /* ����ע�Ͳ��� */
    cout << "������ʾ" << endl;
#endif

#ifdef DEBUG
    cerr << "Trace: Second" << endl;
#endif

    // define��ƴ�ӹ���
    cout << TRANS(���) << endl;
    string ab = "byebye";

    cout << CONN(a, b) << endl;

    cout << "_LINE_ : " << __LINE__ << endl;
    cout << "_FILE_ : " << __FILE__ << endl;
    cout << "_DATE_ : " << __DATE__ << endl;
    cout << "_TIME_ : " << __TIME__ << endl;
    return;

}