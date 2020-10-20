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
		if ((int(s[i]) >= 48 && (int(s[i]) <= 57)) || ((s[i] >= 97) && (s[i] <= 122)))
			str = str + s[i];
		else
		{
			cout << "Vvedeno ne chislo ili bukva, vvedite chislo ili bukvu\n";
			cin >> s;
			return string_check(s);
		}
		i++;
	}
	return str;
}

class Kniga 
{
protected:
	string* Kniga_name;

public:
	Kniga()
	{
		Kniga_name = new string;
		*Kniga_name = " ";
	}

	Kniga(string Knig_name)
	{
		Kniga_name = new string;
		int i = 0;
		*Kniga_name = Knig_name;
	}

	void Show()
	{
		cout << "Название книги-" << Kniga_name << endl;
	}

	~Kniga()
	{
		delete Kniga_name;
	}
};

class Janr : virtual public Kniga
{
protected:
	string* Janr_name;

public:
	Janr()
	{
		Janr_name = new string;
		*Janr_name = " ";
	}

	Janr(string Jnar_v_name, string Kniga_name = " ")
		: Kniga(Kniga_name)
	{
		Janr_name = new string;
		*Janr_name = Jnar_v_name;
	}

	void Show()
	{
		cout << "Название книги :" << *Kniga_name;
		cout << "Название жанра :" << *Janr_name << endl;
	}

	~Janr()
	{
		delete Janr_name;
	}
};

class Tema : public Janr
{
	protected:
		string* Tema_name;


	public:
		Tema()
		{
			Tema_name = new string;
			*Tema_name = " ";
		}

		Tema(string Tema_v_name, string Kniga_name = " ", string Janr_name = " ")
			:Janr(Janr_name, Kniga_name)
		{
			Tema_name = new string;
			*Tema_name = Tema_v_name;
		}

	void Show()
	{
		cout << "Книга :" << *Kniga_name;
		cout << "Жанр :" << *Janr_name;
		cout << "Тема :" << Tema_name << endl;
	}

	~Tema()
	{
		delete Tema_name;
	}
};

class Autor : virtual public Kniga
{
protected:
	string* Autor_name ;

public:
	Autor()
	{
		Autor_name = new string;
	}

	Autor(string Autor_v_name, string Kniga_name = " ")
		: Kniga(Kniga_name)
	{
		Autor_name = new string;
		int i = 0;
		*Autor_name = Autor_v_name;
	}

	void Show()
	{
		cout << "Книга :" << *Kniga_name;
		cout << "Автор :" << *Autor_name << endl;;
	}

	~Autor()
	{
		delete Autor_name;
	}
};

class AJanr : public Autor
{
protected:
	string* AJ_name;

public:
	AJanr()
	{
		AJ_name = new string;
	}

	AJanr(string AJanr_v_name, string Autor_name = " ",
		string Kniga_v_name = " ")
		:Autor(Autor_name, Kniga_v_name)
	{
		AJ_name = new string;
		*AJ_name = AJanr_v_name;
		*Kniga_name = Kniga_v_name;
	}


	void Show()
	{
		cout << "Книга :" << *Kniga_name;
		cout << "Автор" << *Autor_name;
		cout << " Авторский жанр" << *AJ_name << endl;
	}

	~AJanr()
	{
		delete AJ_name;
	}
};

class GG : public Tema, public AJanr
{
protected:
	string* GG_name;
public:
	GG()
	{
		GG_name = new string;
		*GG_name = " ";
	}

	GG(	string gg_name, string ajanr_name, string autor_name,
		string janr_name, string kniga_name, string tema_name)

		:Tema (tema_name, kniga_name , janr_name  ), AJanr(ajanr_name, autor_name, kniga_name)
	{
		*Kniga_name = kniga_name;

		*Janr_name = janr_name;

		*Autor_name = autor_name;

		*AJ_name = ajanr_name;

		*Tema_name = tema_name;

		GG_name = new string;
		*GG_name = gg_name;
	}

	void Show()
	{
		cout << "Название книги " << *Kniga_name << endl;
		cout << "Жанр " << *Janr_name << endl;
		cout << "Тема " << *Tema_name << endl;
		cout << "Автор " << *Autor_name << endl;
		cout << "Авторский жанр " << *AJ_name << endl;
		cout << "Главный герой " << *GG_name << endl;
		cout << "Главный герой " << *GG_name << endl;
	}

	~GG()
	{
		delete GG_name;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	string data;
	
	string kniga_name, janr_name, tema_name, autor_name, ajanr_name, gg_name;

	cout << "Введите название книги" << endl;
	cin >> data;
	kniga_name = string_check(data);

	cout << "Ведите жанр" << endl;
	cin >> data;
	janr_name = string_check(data);


	cout << "Введите автора" <<  endl;
	cin >> data;
	autor_name = string_check(data);


	cout << "Введите авторский жанр" << endl;
	cin >> data;
	ajanr_name = string_check(data);

	cout << "Введите тему" << endl;
	cin >> data;
	tema_name = string_check(data);


	cout << "Введите имя главного героя" << endl;
	cin >> data;
	gg_name = string_check(data);


	GG actor( gg_name, ajanr_name, autor_name,
		janr_name,  kniga_name,  tema_name);
	cout << "===============================================" << endl;
	actor.Show();
	return 0;
}