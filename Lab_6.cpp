#include <iostream>

using namespace std;

template <class X, class Y> int perevorot(X& length, Y& mas)
{
	cout << "Здесь работает шаблон" << endl;
	int i = 0;
	int j = length-1;
	char c;
	while (i < length/2 || j > length/2)
	{
		c = mas[i];
		mas[i] = mas[j];
		mas[j] = c;
		i++;
		j--;
	}
	return length;
}

int perevorot(int length, char* mas, char element)
{
	cout << "Здесь работает функция" << endl;
	int i = 0;
	int j = length-1;
	char c;
	while (i < length / 2 || j > length / 2)
	{
		c = mas[i];
		mas[i] = mas[j];
		mas[j] = c;
		i++;
		j--;
	}
	return length;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int x, i;
	char* y;
	cout << "Введите длину" << endl;
	cin >> x;
	y = new char[x];
	cout << "Введите массив" << endl;
	for (i = 0; i < x; i++)
	{
		cin >> y[i];
	}
	cout << endl;
	x = perevorot(x, y);
	cout << "массив после переворота" << endl;
	for (i = 0; i < x; i++)
		cout << y[i] << " ";
	return 0;
}
