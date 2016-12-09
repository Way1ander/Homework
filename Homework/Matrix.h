#pragma once

class Matrix
{
private:
	int** arr;
	int** MP;
	int* names;
	double* chances;
	int* scores;
	int n;
	Animal* animals;
	int animnum;
	int* path = 0;
public:
	Matrix();
	int Read(char* file);
	int Write(char* file);
	int Pathfinder();
	int Rebuilder();
	~Matrix();
};
