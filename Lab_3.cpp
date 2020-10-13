#include <iostream>
using namespace std;


	class matrix
	{
		int Str, Stb;
		double** MTX;

	 public:
		matrix()// конструктор по умолчанию
		{
			Str = 0;
			Stb = 0;
			MTX = new double* [Str];
			for (int i = 0; i < Str; i++)
				MTX[i] = new double[Stb];
			for (int i = 0; i < Str; i++)
				for (int j = 0; j < Stb; j++)
					MTX[i][j] = 0; // закрыли всю матрицу нулями
		}
		matrix(int str, int stb)
		{
			Str = str;
			Stb = stb;
			MTX = new double* [str];
			for (int i = 0; i < str; i++) MTX[i] = new double[str];
		}

		matrix(int str, int stb, double** mas)//конструктор инициализации
		{
			Str = str;
			Stb = stb;
			MTX = new double* [str];
			for (int i = 0; i < str; i++) MTX[i] = new double[stb];
			for (int i = 0; i < str; i++)
				for (int j = 0; j < stb; j++)
					MTX[i][j] = mas[i][j];
		} 
	
		matrix(const matrix& m) //конструктор копирования
			: Str(m.Str), Stb(m.Stb) // инициализация строк и столбцов
		{
			MTX = new double* [Str];
			for (int i = 0; i < Str; i++)
				MTX[i] = new double[Stb];
			for (int i = 0; i < Str; i++)
			{
				for (int j = 0; j < Stb; j++)
					MTX[i][j] = m.MTX[i][j];
			}
		}


		friend ostream& operator << (ostream& out, matrix& m)
		{
			for (int i = 0; i < m.GetStr(); i++)
			{
				for (int j = 0; j < m.GetStb(); j++)
					out << m.MTX[i][j] << "\t";
				out << endl;
			}
			return out;
		}

		friend istream& operator>>(istream& in, matrix& m)//перегрузка оператора ввода матрицы
		{
			for (int i = 0; i < m.GetStr(); i++)
				for (int j = 0; j < m.GetStb(); j++)
					in >> m.MTX[i][j];
			return in;
		}

		friend matrix operator + (matrix& m1, matrix& m2) //перегрузка сложения
		{
			matrix temp1(m1.GetStr(), m1.GetStb());
			for (int i = 0; i < m1.GetStr(); i++)
				for (int j = 0; j < m1.GetStb(); j++)
					temp1.MTX[i][j] = m1.MTX[i][j] + m2.MTX[i][j];
			return(temp1);
		}

		void Print_element(int i, int j)
		{
			cout << MTX[i][j] << "\n";
		}

		void Set_element(int i, int j, double num)
		{
			MTX[i][j] = num;
		}

		int GetStr()//число строк
		{
			return Str;
		} 
		
		int GetStb() //число столбцов
		{
			return Stb;
		} 
		
		~matrix()
		{
			for (int i = 0; i < Str; i++)
				delete[] MTX[i];
			delete[] MTX;
		}


		matrix& operator = (const matrix& m)
		{
			matrix tmp(m);
			swap(tmp);
			return *this;
		}

	private:
		void swap(matrix& m)
		{
			{
				int tmp = Str; Str = m.Str; m.Str = tmp;
				tmp = Stb; Stb = m.Stb; m.Stb = tmp;
			}
			double** tmp = MTX; MTX = m.MTX; m.MTX = tmp;
		}

	};

	int main()
	{
		setlocale(LC_ALL, "Russian");

		matrix a, b, c, d;
		matrix mas[3];
		double** el;
		int i, j, str, stb, k;
		double num;
		for (k = 0; k < 3; k++)
		{
			cout << "Введите кол-во столбцов \n";
			cin >> str;
			cout << "Введите кол-во строк\n";
			cin >> stb;
			el = new double* [str];
			for (int i = 0; i < str; i++)
				el[i] = new double[stb];
			for (int i = 0; i < str; i++)
				for (int j = 0; j < stb; j++)
				{
					cin >> el[i][j];
				}
			mas[k] = { str, stb, el };
		}

		cout << "--------------------------------\n";
		cout << "mas[1]\n";
		cout << mas[0];

		cout << "--------------------------------\n";
		cout << "mas[2]\n";
		cout << mas[1];

		cout << "--------------------------------\n";
		cout << "mas[3]\n";
		cout << mas[2];
		cout << "--------------------------------\n";
		cout << "Процесс выведения на экран заданного пользователем элемента"<<endl;
		cout << "Введите строку\n";
		cin >> str;
		cout << "Введите столбец\n";
		cin >> stb;
		cout << "Введите номер матрицы\n";
		cin >> k;
		cout << "Ваш элемент : ";
		mas[k - 1].Print_element(str - 1, stb - 1);

		cout << "Процесс замены элемента выбранной матрицы" << endl;
		cout << "Введите строку\n";
		cin >> str;
		cout << "Введите столбец\n";
		cin >> stb;
		cout << "Введите число\n";
		cin >> num;
		cout << "Введите индекс\n";
		cin >> k;
		mas[k - 1].Set_element(str - 1, stb - 1, num);
		cout << mas[k - 1] << "\n";
		matrix raz;

		cout << "Процесс сложения элементов 1 и 2 матриц" << endl;
		raz = mas[0] + mas[1];
		cout << "=======================\n" << "mas[0]+mas[1]\n" << raz;
		return 0;
	}
