#include <iostream>
#include <fstream>
#include "Myfstream1.h"

using namespace std;

void TestFstream(void)
{
	// ��ʱ�洢д�������
	char data[100];

	// ��Ҫ�������ļ�
	ofstream outfile;

	// дģʽ���ļ�
	outfile.open("Testfstream.txt");

	cout << "Write data to the file:\n" << endl;
	cout << "Enter your name : ";
	cin.getline(data, 100);

	// д���û����������
	outfile << data << "\t";

	cout << "Enter you age : ";
	cin >> data;
	cin.ignore();

	outfile << data << endl;

	outfile.close();

	// ��ģʽ���ļ�
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