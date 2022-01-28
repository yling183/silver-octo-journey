#include <iostream>
#include <fstream>
#include "Myfstream1.h"

using namespace std;

void TestFstream(void)
{
	// 临时存储写入的数据
	char data[100];

	// 需要操作的文件
	ofstream outfile;

	// 写模式打开文件
	outfile.open("Testfstream.txt");

	cout << "Write data to the file:\n" << endl;
	cout << "Enter your name : ";
	cin.getline(data, 100);

	// 写入用户输入的数据
	outfile << data << "\t";

	cout << "Enter you age : ";
	cin >> data;
	cin.ignore();

	outfile << data << endl;

	outfile.close();

	// 读模式打开文件
	ifstream infile;
	infile.open("Testfstream.txt");

	cout << "Reading from the file :" << endl;
	infile >> data;


	cout << data << endl;

	infile >> data;

	cout << data << endl;
	infile.close();

	return;
}