// Homework.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Matrix matrix;
	int err = matrix.Read("input.txt");
	if (err){
		cout << "Wrong input!\nCode: " << err << "\n";
		matrix.Write("output.txt");
		system("pause");
		return 0;
	}
	matrix.Rebuilder();
	matrix.Greedy();
	/*if (!matrix.Write("output.txt")){
		cout << "Uncorrect output!\n";
	}*/
	system("pause");
	return 0;
}

