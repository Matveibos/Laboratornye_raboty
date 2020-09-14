// КПИЯП.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


#include <iostream>
#include <iomanip>
using namespace std;

#define SQUARE(A) (A)*(A)

int main()
{ 
	setlocale(LC_ALL,"Russian");
	/*
	cout << SQUARE(3+1) << endl;
    cout << setw(5)<< "1" << endl;
	cout << setw(5) << setfill('!') << 1 << endl;
    cout << setprecision(6) << 2782,464247586;*/

const int n =4;
	int a[n][n];
	int i1, j1, min=999;
	for(int i=0; i<n; i++)
	{ 
		for (int j = 0; j < n; j++)
		{
			cout << "Введите элемент a[" << i << "]" << "[" << j << "]  ";
			a[i][j]=rand()%21+1;
			cout <<a[i][j]<< endl;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j]<< " ";
		}
		cout  << endl;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j % 2 == 1 && i % 2 == 1)
			{
				if (a[i][j] < min)
				{
					min = a[i][j];
					i1 = i; j1 = j;
				}

			}

		}
	}
	cout << "[" <<hex << i1 << "]" << "[" <<hex<< j1 << "]" << endl;
	cout <<hex<<min<<endl; 
	cout << "[" << oct << i1 << "]" << "[" << oct << j1 << "]" << endl;
	cout << hex << min<<endl;
	cout << "[" << oct << i1 << "]" << "[" << oct << j1 << "]" << endl;
	cout << oct << min<<endl;
	cout << "[" << i1 << "]" << "[" << j1 << "]" << endl;
	cout << min << endl;
	return 0;





}








