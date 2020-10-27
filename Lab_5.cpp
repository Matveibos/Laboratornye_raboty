#include <iostream>
#include <locale.h>

using namespace std;
class Kniga {
protected:

	int str;
	string Kname;

public:

	virtual void Str() = 0;

	virtual void Print() = 0;

	Kniga()
	{
		this->str = 0;
		this->Kname = ' ';
	}

	Kniga(int K_str, string K_name) :str(K_str), Kname(K_name)
	{

	}

	void setStr(int K_str) 
	{
		str = K_str;
	}

	void setKname(string K_name)
	{
		Kname = K_name;
	}

	virtual ~Kniga()
	{
		cout << "dectr" << endl;
	}
};

class Janr : public Kniga {

protected:

	string Jname;

public:

	Janr() : Kniga()
	{
		this->Jname = ' ';
	}

	Janr( string J_name, int K_str, string K_name) : Kniga(str, Kname), Jname(J_name) 
	{

	}

	~Janr()
	{

	}
	void Str() 
	{
		int STR = str / 100;
		cout << " Число преобразованных страниц = " << STR;
	}
	
	void setJname(string J_name) {
		Jname = J_name;
	}

	void Print() 
	{
		cout << endl;
		cout << " Название жанра : " << this->Jname << endl;
		cout << "Число страниц :" << str << endl;
		cout << "Название книги :" << this->Kname<< endl;
	}
};

class Tema : public Kniga {

protected:

	string Tname;
	
public:

	Tema() : Kniga() {
		this->Tname = ' ';
	}

	Tema(string T_name, int str, string Kname) : Kniga(str, Kname), Tname(T_name)
	{}

	~Tema()
	{

	}
	void Str()
	{
		int STR = str / 100;
		cout << " Число преобразованных страниц = " << STR;
	}

	void setTname(string T_name) {
		Tname = T_name;
	}

	void Print()
	{
		cout << endl;
		cout << " Название темы : " << this->Tname << endl;
		cout << "Число страниц :" << str << endl;
		cout << "Название книги :" << this->Kname << endl;
	}
};

class Autor : public Tema {
protected:

	string Aname;

public:

	Autor() : Tema()
	{
		this->Aname = ' ';
	}
	Autor(int str, string Kname, string Tname) 
	{

	}

	~Autor()
	{

	}
	void Str()
	{
		int STR = str / 100;
		cout << " Число преобразованных страниц = " << STR;
	}

	void setAname(string T_name) {
		Tname = T_name;
	}

	void print() {
		cout << endl;
		cout << "Имя автора" <<Aname << endl;
		cout << "число строк" << str << endl;
		cout << "название книги" << Kname << endl;
		cout << "название темы " <<Tname << endl;
		
	}
};

int check_int()
{
	while (true)
	{
		int a;
		std::cin >> a;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "ВВедите заново: ";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return a;
		}
	}
}

string check_string(string s)
{
	int i = 0;
	string str;
	while (s[i])
	{
		if ((s[i] >= 97) && (s[i] <= 122))
			str = str + s[i];
		else
		{
			cout << "Введите заново: ";
			cin >> s;
			return check_string(s);
		}
		i++;
	}
	return str;
}
void setKniga(Kniga& Kniga1) {
	int str;
	cout << "";
	str = check_int();
	Kniga1.setStr(str);
	string Kname;
	cout << " ";
	cin >> Kname;
	check_string(Kname);
	Kniga1.setKname(Kname);
}


void setJanr(Janr& Janr1) {
	setKniga(Janr1);
	string J_name;
	cout << ": ";
	cin >> J_name;
	check_string(J_name);
	Janr1.setJname(J_name);
}

void setTema(Tema& Tema1)
{
	setKniga(Tema1);
	string T_name;
	cout << ": ";
	cin >> T_name;
	check_string(T_name);
	Tema1.setTname(T_name);
}


void setAutor(Autor& Autor1)
{
	setTema(Autor1);
	string A_name;
	cout << ": ";
	cin >> A_name;
	check_string(A_name);
	Autor1.setAname(A_name);
}


int main()
{
	setlocale(LC_ALL, "Russian");

	string Kname; int str = 0; string Jname; string Tname; string Aname;
	Janr* ptrJanr = new Janr[2];
	Autor* ptrAutor = new Autor[2];
	Tema* ptrTema = new Tema[2];
	Kniga* kniga;

	for (int i = 0; i < 2; i++)
	{
		cout << endl << "-----" << endl;
		setJanr(ptrJanr[i]);
		kniga = &ptrJanr[i];
		kniga->Print();
		kniga->Str();
	}
	cout << endl << "----------------------" << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << endl << "-----" << endl;
		setTema(ptrTema[i]);
		kniga = &ptrTema[i];
		kniga->Print();
		kniga->Str();
	}
	cout << endl << "----------------------" << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << endl << "-----" << endl;
		setAutor(ptrAutor[i]);
		kniga = &ptrAutor[i];
		kniga->Print();
		kniga->Str();
	}
	cout << endl << "----------------------" << endl;
	cout << endl;

	system("pause");

}