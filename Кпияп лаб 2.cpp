#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <string>
using namespace std;

int input_check(char s[]) // проверка правильного ввода
{
	int i = 0, n = 0;
	while (s[i])
	{
		if (int(s[i]) >= 48 && int(s[i]) <= 57) // если введен символ в необъодимом диапазоне
			n = n * 10 + int(s[i] - 48); // увеличили число десятков и добавили к нам введенный символ
		else
		{
			cout << "Введен неизвестный символ, пожалуйста введите корректный символ\n";
			cin >> s;
			return input_check(s);
		}
		i++;
	}
	return n;
}

class Sotrudnic
{
	friend class Buxgalter;
	friend void get(Sotrudnic& Sot);
private:
	int number;
	string FIO;
	int salary;
public:
	Sotrudnic()
	{
		number = 0;
		salary = 0;
		FIO = " ";
	}
	Sotrudnic(int id, int price, string name) {
		number = id;
		FIO = name;
		salary = price;
	}
	~Sotrudnic() {
		cout << this << endl; // следим за адресом удаляемого объекта
		cout << "Вызван деструктор" << endl;
	}

};

void get(Sotrudnic& Sot) 
{
	cout << Sot.number << "    " << Sot.FIO<< "    " << Sot.salary << endl;
}

class Buxgalter {
public:
	Buxgalter() {

	}
	~Buxgalter() {

	}
	void set(Sotrudnic& Sot, int data) 
	{
		Sot.salary = data;
	}
};

int main() {
  setlocale(LC_ALL, "Russian");
	int kol, ID = 0, set_salary = 0;
	string set_FIO;
	char data[20];
	Sotrudnic ptr[2];
	Buxgalter Bux;
	kol = 2;
	for (int i = 0; i < kol; i++) 
	{
		cout << "Соотрудник номер " << i + 1<<endl;
		cout << "Введите идентификационный номер : ";
		cin >> data;
		ID = input_check(data);
		cout << "Введите ФИО сотрудника ";
		cin >> set_FIO;
		cout << endl;
		ptr[i] = { ID, 0, set_FIO };
		
		cout << "________________________________________________________" << endl;;
		cout << endl;
	}

	for (int i = 0; i < kol; i++)
	{
		
			get(ptr[i]);
	}
	cout << endl;
	for (int i = 0; i < kol; i++)
	{
		cout << "Введите оклад  " << i + 1 << " сотрудника :";
		cin >> data;
		set_salary = input_check(data);
		Bux.set(ptr[i], set_salary);
	}
	cout << endl;
	for (int i = 0; i < kol; i++)
	{
		get(ptr[i]);
	}
	return 0;
}