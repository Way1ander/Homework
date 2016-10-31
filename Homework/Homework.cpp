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
		return 0;
	}
	matrix.Pathfinder();
	if (!matrix.Write("output.txt")){
		cout << "Uncorrect output!\n";
	}

	return 0;
}

