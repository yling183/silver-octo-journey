#include<iostream>
#include "MyNewDelete.h"

using namespace std;

void Test_NewDelete(void) {

	// һ������Ķ�̬�ڴ����
	double* pvalue = NULL;
	pvalue = new double;

	*pvalue = 12;
	cout << "Double value is : " << *pvalue << endl;

	delete pvalue;

	return;
}

void Test_NewDelete_ARRAY(void) {
	// ����Ķ�̬�ڴ����
	/*
		// һά����
		int *arr = new int[m];
		delete [] arr;
	*/
	cout << "һά���飺" << endl;

	char * pvalue_char = NULL;
	pvalue_char = new char[20];
	int i, j;
	for (i = 0; i < 20; i++) {
		pvalue_char[i] = 'A' + i;
	}
	for (i = 0; i < 20; i++) {
		cout << pvalue_char[i] << " ";
	}
	cout << endl;
	delete [] pvalue_char;


	// ��ά����
	/*
		// ��ά���� m * n
		int** arr;
		arr = new int* [m];
		for (int i = 0; i < m; i++) {
			arr[i] = new int[n];
		}

		// �ͷ�
		for (int j = 0; j < m; j++) {
			delete[] arr[i];
		}
		delete[] arr;
	*/
	cout << "��ά���飺" << endl;
	int** p = NULL; // �����С 3 * 4

	p = new int * [3];
	for (i = 0; i < 3; i++) {
		p[i] = new int [4];
	}

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			p[i][j] = i * j;
		}
	}
	
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			cout << p[i][j] << " ";
		}
		cout << endl;
	}

	for (i = 0; i < 3; i++) {
		delete [] p[i];
	}
	delete [] p;

	return;
}