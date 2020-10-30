#include <iostream>
#include <locale.h>
#include <string>

using namespace std;



string string_check(string s)
{
	int i = 0;
	string str;
	while (s[i])
	{
		if  ((s[i] >= 97) && (s[i] <= 122))
			str = str + s[i];
		else
		{
			cout << "Неизвестный символ\n";
			cin >> s;
			return string_check(s);
		}
		i++;
	}
	return str;
}

class Kniga {

public:
	Kniga()
	{

	}

	Kniga(string studio_name)
	{
	}

	virtual void Show() = 0;

	virtual ~Kniga()
	{
	}
};

class Janr : public Kniga
{
protected:
	string* J_name;

public:
	Janr()
	{
		J_name = new string;
		*J_name = " ";
	}

	Janr(string Janr_name)
	{
		J_name = new string;
		*J_name = Janr_name;
	}

	virtual void Show()
	{
		cout << " Жанр :" << *J_name << endl;
	}

	~Janr()
	{
		delete J_name;
	}
};

class Tema : public Janr
{
protected:
	string* T_name;


public:
	Tema()
	{

		 T_name = new string;
		*T_name = " ";
	}


	Tema(string Tema_name, string Janr_name):Janr(Janr_name)
	{
		 T_name = new string;
		*T_name = Tema_name;
	}

	virtual void Show()
	{
		cout << "Жанр : " << *J_name;
		cout << "Тема :  " << *T_name << endl;
	}

	~Tema()
	{

	}
};

class Autor : public Kniga
{
protected:
	string* Aname;

public:
	Autor()
	{
		Aname = new string;
	}

	Autor(string autor_name)
	{
		Aname = new string;
	
		*Aname = autor_name;
	}

	virtual void Show()
	{
		cout << " Автор : " << *Aname << endl;;
	}

	~Autor()
	{
		delete Aname;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");
	Kniga* K[3];
	string data;
	
	string K_name, J_name, A_name,T_name;


	cout << "Введите название жанра" << endl;
	cin >> data;
	J_name = string_check(data);


	cout << "Введите имя автора" << endl;
	cin >> data;
	A_name = string_check(data);

	cout << "Введите название темы" << endl;
	cin >> data;
	T_name = string_check(data);


	cout << "===============================================" << endl;
	Janr ser(J_name);
	K[0] = &ser;
	K[0]->Show();

	cout << "===============================================" << endl;
	Tema ses(T_name, K_name);
	K[1] = &ses;
	K[1]->Show();

	cout << "===============================================" << endl;
	Autor mov(A_name);
	K[2] = &mov;
	K[2]->Show();

	cout << "===============================================" << endl;
	return 0;
}