#include<iostream>
#include "MyNewDelete.h"

using namespace std;

void Test_NewDelete(void) {

	// 一般变量的动态内存分配
	double* pvalue = NULL;
	pvalue = new double;

	*pvalue = 12;
	cout << "Double value is : " << *pvalue << endl;

	delete pvalue;

	return;
}

void Test_NewDelete_ARRAY(void) {
	// 数组的动态内存分配
	/*
		// 一维数组
		int *arr = new int[m];
		delete [] arr;
	*/
	cout << "一维数组：" << endl;

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


	// 二维数组
	/*
		// 二维数组 m * n
		int** arr;
		arr = new int* [m];
		for (int i = 0; i < m; i++) {
			arr[i] = new int[n];
		}

		// 释放
		for (int j = 0; j < m; j++) {
			delete[] arr[i];
		}
		delete[] arr;
	*/
	cout << "二维数组：" << endl;
	int** p = NULL; // 数组大小 3 * 4

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