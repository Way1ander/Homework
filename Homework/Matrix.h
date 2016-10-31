#pragma once

class Matrix
{
private:
	int** arr;
	int* names;
	double* chances;
	int* exist;
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
	~Matrix();
};
