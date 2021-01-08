#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iterator>
#include <set>


namespace cook {
    class Sotrudnic;

    class Algoritms {
    public:
        void Algoritm1();
        std::list<Sotrudnic>::iterator Algoritm2(std::list<Sotrudnic>::iterator begin_1, std::list<Sotrudnic>::iterator end_1,
            std::list<Sotrudnic>::iterator begin_2, std::list<Sotrudnic>::iterator end_2);
        void Algoritm3(std::list<Sotrudnic>::iterator begin_1, std::list<Sotrudnic>::iterator end_1,
            std::list<Sotrudnic>::iterator begin_2, std::list<Sotrudnic>::iterator end_2);
        void Print(std::list<Sotrudnic>::iterator begin, std::list<Sotrudnic>::iterator end);

    };

    class Sotrudnic {
    public:
        Sotrudnic(int id = 0, std::string name = "", int salary = 0) :
            m_id(id), m_name(name), m_salary(salary) {}

        friend Algoritms;

        friend std::ostream& operator<< (std::ostream& out, const Sotrudnic& Sotrudnic) {
            out << "Id: " << Sotrudnic.m_id << std::endl;
            out << "Name: " << Sotrudnic.m_name << std::endl;
            out << "Salary: " << Sotrudnic.m_salary << std::endl;
            return out;
        }

    private:
        int m_id;
       std::string m_name;
        int m_salary;
    };

    class Exception {
    public:
        Exception() {
            this->errorIndex = 0;
        }
        Exception(int errorIndex) {
            this->errorIndex = errorIndex;
        }
        void what() {
            if (errorIndex == 0) 
            {
                std::cout << "Input error! Enter int!" << std::endl;
            }
            else if (errorIndex == 1) {
                std::cout << "Opening error!" << std::endl;
            }
            else if (errorIndex == 2) {
                std::cout << "Stack is empty!" << std::endl;
            }
            else {
                std::cout << "EXCEPTION, BLAT" << std::endl;
            }
        }

    private:
        int errorIndex;
    };
}

int main() 

{
    setlocale(LC_ALL, "Russian");
    cook::Algoritms alg;
    std::list<cook::Sotrudnic> test;
    std::list<cook::Sotrudnic> test_new;
    

    test.push_back(cook::Sotrudnic(1, "Ivanov", 11));
    test.push_back(cook::Sotrudnic(2, "Petrov", 13));
    test.push_back(cook::Sotrudnic(3, "Sidorov", 10));

    test_new.push_back(cook::Sotrudnic(1, "Ivanov", 11));
    test_new.push_back(cook::Sotrudnic(2, "Petrov", 13));
    test_new.push_back(cook::Sotrudnic(3, "Sidorov", 10));

    std::cout << "Алгоритм 1\n" << "------------------------------------\n";
    alg.Algoritm1();
    std::cout << std::endl;

    std::cout << "Пример 1\n" << "------------------------------------\n";
    alg.Print(test.begin(), test.end());


    std::cout << "Алгоритм 2\n" << "------------------------------------\n";
    auto it = alg.Algoritm2(test.begin(), test.end(), test_new.begin(), test_new.end());
    if (it == test.end()) {
        std::cout << "Элементы идентичны" << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Пример 2\n" << "------------------------------------\n";

    alg.Print(test.begin(), test.end());
    alg.Print(test_new.begin(), test_new.end());

    std::cout << "Алгоритм 3\n" << "------------------------------------\n";

    alg.Algoritm3(test.begin(), test.end(), test_new.begin(), test_new.end());

    alg.Print(test.begin(), test.end());
    alg.Print(test_new.begin(), test_new.end());

    return 0;
}


void cook::Algoritms::Print(std::list<Sotrudnic>::iterator begin,
    std::list<Sotrudnic>::iterator end) {
    auto it = begin;
    while (it != end) 
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << std::endl;
}

void cook::Algoritms::Algoritm3(std::list<Sotrudnic>::iterator begin_1, std::list<Sotrudnic>::iterator end_1,// ПРИСВАИВАНИЕ
    std::list<Sotrudnic>::iterator begin_2, std::list<Sotrudnic>::iterator end_2) {
    auto it_1 = begin_1;
    auto it_2 = begin_2;
    while (it_1 != end_1 && it_2 != end_2) 
    {
        if ((it_1->m_id == it_2->m_id) && (it_1->m_salary == it_2->m_salary) && (it_1->m_name == it_2->m_name)) {
            it_1->m_id = it_2->m_id = 1;
            it_1->m_name = it_2->m_name = "2";
            it_1->m_salary = it_2->m_salary = 3;
        }
        ++it_1;
        ++it_2;
    }
}

std::list<cook::Sotrudnic>::iterator cook::Algoritms::Algoritm2(std::list<Sotrudnic>::iterator begin_1, std::list<Sotrudnic>::iterator end_1,
    std::list<Sotrudnic>::iterator begin_2, std::list<Sotrudnic>::iterator end_2) {
    auto it_1 = begin_1;
    auto it_2 = begin_2;
    while (it_1 != end_1 && it_2 != end_2) {
        if (it_1->m_id != it_2->m_id || it_1->m_salary != it_2->m_salary || it_1->m_name != it_2->m_name) {
            return it_1;
        }
        ++it_1;
        ++it_2;
    }
    return it_1;
}

void cook::Algoritms::Algoritm1() {
    std::cout << "Начат алгоритм 1" << std::endl;
    std::fstream outFile;
    outFile.open("srting.txt");
    try {
        if (!outFile.is_open()) {
            throw 1;
        }
        std::cout << "Файл открыт" << std::endl;
    }
    catch (int index) {
        Exception ex(index);
        ex.what();
        return;
    }

    std::string buffer;
    std::list<std::string> strList;
    int i = 0, amount_received_symbol = 0;
    char received_symbol; char* mass = new char[10];
    std::cout << "Печатаемый символ: ";
    std::cin >> received_symbol;

    while (!outFile.eof()) {
        std::getline(outFile, buffer);
        std::cout << buffer << std::endl;
        while (i < buffer.length()) {
            if (buffer[i] == received_symbol) {
                amount_received_symbol++;
            }
            i++;
        }
        _itoa_s(amount_received_symbol, mass, 10, 10);
        strList.push_back(buffer + " Число полученных сомволов имвол: " + mass);
        amount_received_symbol = 0; i = 0;
    }

    std::cout << "Aлгоритм окончен" << std::endl;
    outFile.close();
    std::cout << "Файл закрыт" << std::endl;

    std::ofstream inFile("string2.txt");

    try {
        if (!inFile.is_open()) {
            throw 1;
        }
        std::cout << "Первый файл файл открыт" << std::endl << std::endl;
    }
    catch (int index) {
        Exception ex(index);
        ex.what();
        return;
    }

    std::list<std::string>::const_iterator it = strList.begin();
    while (it != strList.end()) {
        inFile << *it << "\n";
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << std::endl << "Данные были введены" << std::endl;
    inFile.close();
    std::cout << "Второй файл закрыт" << std::endl;
}
