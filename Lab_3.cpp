#include <iostream>
using namespace std;


	class matrix
	{
		int Row, Col;
		double** Value;

	public:
		matrix()// конструктор по умолчанию
		{
			Row = 0;
			Col = 0;
			Value = new double* [Row];
			for (int i = 0; i < Row; i++)
				Value[i] = new double[Col];
			for (int i = 0; i < Row; i++)
				for (int j = 0; j < Col; j++)
					Value[i][j] = 0; // закрыли всю матрицу нулями
		}
		matrix(int row, int col)
		{
			Row = row;
			Col = col;
			Value = new double* [row];
			for (int i = 0; i < row; i++) Value[i] = new double[col];
		}

		matrix(int row, int col, double** mas)//конструктор инициализации
		{
			Row = row;
			Col = col;
			Value = new double* [row];
			for (int i = 0; i < row; i++) Value[i] = new double[col];
			for (int i = 0; i < row; i++)
				for (int j = 0; j < col; j++)
					Value[i][j] = mas[i][j];
		} 
	
		matrix(const matrix& m) //конструктор копирования
			: Row(m.Row), Col(m.Col) // инициализация строк и столбцов
		{
			Value = new double* [Row];
			for (int i = 0; i < Row; i++)
				Value[i] = new double[Col];
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
					Value[i][j] = m.Value[i][j];
			}
		}


		friend ostream& operator << (ostream& out, matrix& m)
		{
			for (int i = 0; i < m.GetRow(); i++)
			{
				for (int j = 0; j < m.GetCol(); j++)
					out << m.Value[i][j] << "\t";
				out << endl;
			}
			return out;
		}

		friend istream& operator>>(istream& in, matrix& m)//перегрузка оператора ввода матрицы
		{
			for (int i = 0; i < m.GetRow(); i++)
				for (int j = 0; j < m.GetCol(); j++)
					in >> m.Value[i][j];
			return in;
		}

		friend matrix operator + (matrix& m1, matrix& m2) //перегрузка сложения
		{
			matrix temp1(m1.GetRow(), m1.GetCol());
			for (int i = 0; i < m1.GetRow(); i++)
				for (int j = 0; j < m1.GetCol(); j++)
					temp1.Value[i][j] = m1.Value[i][j] + m2.Value[i][j];
			return(temp1);
		}

		void Print_element(int i, int j)
		{
			cout << Value[i][j] << "\n";
		}

		void Set_element(int i, int j, double num)
		{
			Value[i][j] = num;
		}

		int GetRow()//число строк
		{
			return Row; 
		} 
		
		int GetCol() //число столбцов
		{
			return Col; 
		} 
		
		~matrix()
		{
			for (int i = 0; i < Row; i++)
				delete[] Value[i];
			delete[] Value;
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
				int tmp = Row; Row = m.Row; m.Row = tmp;
				tmp = Col; Col = m.Col; m.Col = tmp;
			}
			double** tmp = Value; Value = m.Value; m.Value = tmp;
		}

	};

	int main()
	{
		setlocale(LC_ALL, "Russian");

		matrix a, b, c, d;
		matrix mas[3];
		double** el;
		int i, j, row, col, k;
		double num;
		for (k = 0; k < 3; k++)
		{
			cout << "Введите кол-во столбцов \n";
			cin >> row;
			cout << "Введите кол-во строк\n";
			cin >> col;
			el = new double* [row];
			for (int i = 0; i < row; i++)
				el[i] = new double[col];
			for (int i = 0; i < row; i++)
				for (int j = 0; j < col; j++)
				{
					cin >> el[i][j];
				}
			mas[k] = { row, col, el };
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
		cin >> row;
		cout << "Введите столбец\n";
		cin >> col;
		cout << "Введите номер матрицы\n";
		cin >> k;
		cout << "Ваш элемент : ";
		mas[k - 1].Print_element(row - 1, col - 1);

		cout << "Процесс замены элемента выбранной матрицы" << endl;
		cout << "Введите строку\n";
		cin >> row;
		cout << "Введите столбец\n";
		cin >> col;
		cout << "Введите число\n";
		cin >> num;
		cout << "Введите индекс\n";
		cin >> k;
		mas[k - 1].Set_element(row - 1, col - 1, num);
		cout << mas[k - 1] << "\n";
		matrix raz;

		cout << "Процесс сложения элементов 1 и 2 матриц" << endl;
		raz = mas[0] + mas[1];
		cout << "=======================\n" << "mas[0]+mas[1]\n" << raz;
		return 0;
	}
