#include "stdafx.h"
#include "Matrix.h"
#define INF 9000000

Matrix::Matrix()
{

}


int Matrix::Read(char* filename)
{
	n = 0;// выходной файл будет чист при ошибке
	ifstream anfile("animals");
	if (anfile.is_open()){
		queue<double> tmp;
		double i;
		int count = 0;
		animnum = std::count(std::istreambuf_iterator<char>(anfile),
			std::istreambuf_iterator<char>(), '\n') + 1;
		//int max = animnum * 3;//ожидаемое количество чисел
		anfile.seekg(0, std::ios::end);
		int size = anfile.tellg();
		anfile.seekg(0, 0);
		while (!anfile.eof() && count <= size){
			anfile >> i;
			tmp.push(i);
			++count;
		}
		
		if (count > size) return 6;//Введенное количество превышает ожидаемое
		double num;
		animnum = num = (double)count / 3;
		if (num != (double)animnum){
			return 9;//Для животного есть больше 3х параметров
		}
		animals = new Animal[animnum];
		double a = -1, b = -1, c = -1;
		for (int i = 0; i < animnum; i++){
			a = tmp.front();
			tmp.pop();
			b = tmp.front();
			tmp.pop();
			c = tmp.front();
			tmp.pop();
			if (animals[i].setNumber(i) || animals[i].setChance(a) || animals[i].setPresence(b) || animals[i].setscores(c)){
				return 7;//Некорректные параметры животного
			}
			a = b = c = -1;
		}
		cout << "animals's properties:\n";
		for (int i = 0; i < animnum; i++){
			cout << animals[i].getNumber() << " " << animals[i].getChance() << " " << animals[i].getPresence() << " " << animals[i].getscores() << "\n";
		}
	}
	anfile.close();
	ifstream infile(filename);
	if (infile.is_open()){
		cout << filename << ":\n";
		int count = 0;
		int size = 0;
		infile.seekg(0, std::ios::end);
		size = infile.tellg();
		queue<double> tmp;
		double i;
		infile.clear();
		infile.seekg(0, 0);
		while (!infile.eof() && count <= size){
			infile >> i;
			tmp.push(i);
			++count;
			i = -1;
		}
		if (count > size) return 8;//Неверное количество чисел
		int str = 1;//После м-цы однозначно будет одна строка
		double nd = (pow(pow((double)str,2) + 4 * (double)count, 0.5) - (double)str) / 2.0;
		n = (int)nd;
		
		if (nd != (double)n){
			n = 0;
			return 1;//Количество параметров животных не соответствует количеству животных
		}

		cout << "n=" << n << "\n";
		arr = new int*[n];
		names = new int[n];
		double cur;
		for (int i = 0; i < n; i++) arr[i] = new int[n];
		for (int i = 0; i < n + str; i++){
			for (int j = 0; j < n; j++){
				cur = 0;
				cur = tmp.front();
				if (cur < 0){
					n = 0;
					return 2;//Параметр <0
				}

				if (cur == 0 && i < n && i != j){
					n = 0;
					return 3;//Путь между животными =0
				}

				if (i == j && cur != 0){
					n = 0;
					return 4;//На главной диагонали присутствует число, отличное от 0 (путь от животного к самому себе !=0)
				}
				else{
					if (i < n) arr[i][j] = (int)cur;
					}

				if (i == n && (cur < 0 || cur >= animnum)){
					n = 0;
					return 5;//Кол-во животных в animals и input не совпадает
				}
				else{
					if (i == n) names[j] = (int)cur;
				}

				//cout << cur << " ";
				tmp.pop();
			}
			//cout << "\n";
		}
	}
	infile.close();
	return 0;
}

int Matrix::Write(char* filename)
{
	ofstream outfile(filename, ios_base::trunc);
	int* test;
	if (n > 0 && path != 0){//n==0, файл очищается
		test = new int[animnum];
		for (int i = 0; i < animnum; i++){
			test[i] = 0;
		}
		for (int i = 0; i < n; i++){
			test[path[i]]++;
			if (test[path[i]]>1){
				outfile.close();
				return 0;// Некорректный путь(*)
			}
		}
		if (outfile.is_open()){
			outfile << path[0];
			for (int i = 1; i < n; i++){
				outfile << " -> " << path[i];
			}
		}
		outfile.close();
		return 1;// закрыто
	}
	outfile.close();
	return 0;// закрыто с ошибкой
}
int Matrix::Rebuilder(){
	MP = new int*[n];
	for (int i = 0; i < n; i++) MP[i] = new int[n];
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j){
		MP[i][j] = j;
	}
	for (int k = 0; k < n; ++k)
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j)
	if (arr[i][k] < INF && arr[k][j] < INF)
	if (arr[i][k] + arr[k][j] < arr[i][j]){ arr[i][j] = arr[i][k] + arr[k][j]; MP[i][j] = MP[i][k]; }
	cout << "\n";
	for (int i = 0; i < n; ++i){
		for (int j=0; j < n; ++j){ std::cout << arr[i][j] << " "; }
		std::cout << "\n";

	}std::cout << "\n";
	for (int i=0; i < n; ++i){
		for (int j=0; j < n; ++j){ std::cout << MP[i][j] << " "; }
		std::cout << "\n";
	}
	return 1;
}

int Matrix::Greedy(){
	path = new int[n];
	path[0] = 0;
	int  i, j, k, m, temp, ans;
	int f, q = n, v, w, e;
	m = 1 << n; w = m;
	int** t = new int*[m];
	for (int i = 0; i < m; i++){ t[i] = new int[n];
}
	t[1][0] = 0; 
	for (i = 1; i<m; i += 2)
	for (j = (i == 1) ? 1 : 0; j<n; ++j)
	{
		t[i][j] = inf;
		if (j>0 && get(j, i))
		{
			temp = i ^ (1 << j);
			for (k = 0; k<n; ++k)
			if (get(k, i) && arr[k][j]>0){
				t[i][j] = min(t[i][j], t[temp][k] + arr[k][j]);
			}
		}
	}
	for (j = 1, ans = inf; j<n; ++j)
	if (arr[j][0]>0){
		if (ans > t[m - 1][j] + arr[j][0]) {
			ans = t[m - 1][j] + arr[j][0];
			e = j; path[q] = j; f = t[m - 1][j];
		}
	}
	while (w>1){
		v = w - pow(2, e);
		f = t[v - 1][e];
		for (k = 0; k < n; ++k){
			if (t[w - 1][e] == t[v - 1][k] + arr[k][e] && t[w - 1][e] < f) {
				f = t[w - 1][e]; path[q - 1] = e; e = k;
			}
		}
		w = v;
		q--;
	}
		for (int j = 0; j < n; ++j){ std::cout << path[j] << "->"; }
		if (ans == inf) return 0;
		else return 1;
}


Matrix::~Matrix()
{
}
