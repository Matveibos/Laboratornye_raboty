#include <iostream>
using namespace std;
class Sotrudnic 
{
public:
    
    Sotrudnic(int id = 0, string name = "", int salary = 0) : m_id(id), m_name(name), m_salary(salary) {}
    
    
    ~Sotrudnic() {}

    int getId() 
    {
        return m_id;
    }

    string getName() 
    {
        return m_name;
    }

    int getSalary() 
    {
        return m_salary;
    }

private:
    int m_id;
    string m_name;
    int m_salary;
};


class Exception
{
private:
    int error;

public:
    Exception()
    {
        error = 0;
    }
    Exception(int error)
    {
        this->error = error;
    }
    void what()
    {
        if (error == 0) cout << "exception" << endl;
        if (error == 1) cout << "Cant insert Dublicate!" << endl;
        if (error == 2) cout << "No such value!" << endl;
        if (error == 3) cout << "pointer is empty" << endl;
    }
};

template <class T>
class Iterator;
template <class T>
class List;

template <class T>
class Node 
{
private:
    T data;
    Node* prev;
    Node* next;
    Node* head;

    friend Iterator<T>;
    friend List<T>;
};

template <class T>
class Iterator 
{
public:
   
    Iterator() 
    {
        nodePointer = nullptr;
    }
    
    Iterator(Node<T>* nodePointer) 
    {
        this->nodePointer = nodePointer;
    }
    
    ~Iterator() 
    {
        nodePointer = nullptr;
    }
    bool operator == (Iterator other) 
    {
        if (nodePointer == other.nodePointer)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
    bool operator != (Iterator other) 
    {
        return !operator==(other);
    }

    T GetValue() 
    {
        if (nodePointer == nullptr) 
        {
            throw 3;
        }
        return nodePointer->data;
    }
    
    void Next() 
    {
        if (nodePointer->next != nullptr) 
        {
            nodePointer = nodePointer->next;
        }
    }
    
    void Prev() 
    {
        if (nodePointer->prev != nullptr) 
        {
            nodePointer = nodePointer->prev;
        }
    }
private:
    Node<T>* nodePointer;
};

template <class T>
class List
{
public:
    List() 
    {
        head = nullptr;
        size = 0;
    }

    Iterator<T> Begin() 
    {
        Node<T>* temp = head;
        while (temp->prev) 
        {
            temp = temp->prev;
        }
        return temp;
    }

    Iterator<T> End() 
    {
        Node<T>* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        return temp;
    }

    Node<T>* GetNodeByValue(T value) 
    {
        Node<T>* temp = head;
        while (temp) {
            if (temp->data != value) 
            {
                temp = temp->next;
                continue;
            }
            else 
            {
                return temp;
            }
        }
        throw 2;
    }

    void InNode(T l_data) 
    {
        if (!head) 
        {
            head = GetFreeNode(l_data, nullptr);
            size++;
        }
        else 
        {
            Node<T>* iterator = head;
            while (iterator) 
            {
                if (iterator->next) 
                {
                    iterator = iterator->next;
                    continue;
                } /*else if (iterator->data == l_data){
                     throw 1;
                }*/
                else 
                {
                    iterator->next = GetFreeNode(l_data, iterator);
                    size++;
                    return;
                }
            }
        }
    }

    void DelNodeByValue(T l_value) 
    {
        Node<T>* target = GetNodeByValue(l_value);
        RawEraseNode(target);
    }

    void bubble_sort() 
    {
        Node<T>* ptr;

        for (int i = 0; i < size; i++) 
        {

            Node<T>* elem_1 = head;
            Node<T>* elem_2 = head->next;

            for (int j = 0; j < size - 1; j++) 
            {

                if (elem_1->data > elem_2->data) 
                {

                    if (elem_1->prev) 
                    {
                        ptr = elem_1->prev;
                    }
                    else {
                        ptr = nullptr;
                    }

                    if (elem_1 == head) 
                    {
                        head = elem_2;
                        head->prev = nullptr;
                    }
                    if (elem_1->prev) 
                    {
                        elem_1->prev->next = elem_2;
                    }
                    if (elem_2->next) 
                    {
                        elem_2->next->prev = elem_1;
                        elem_1->next = elem_2->next;
                    }
                    else
                    {
                        elem_1->next = nullptr;
                    }

                    elem_1->prev = elem_2;
                    elem_2->next = elem_1;

                    if (ptr) 
                    {
                        elem_2->prev = ptr;
                    }

                    ptr = elem_1;
                    elem_1 = elem_2;
                    elem_2 = ptr;

                }
                elem_1 = elem_1->next;
                elem_2 = elem_2->next;
            }
        }
    }

    void print() 
    {
        Iterator<T> it = this->Begin();
        while (true) {
            if (it == this->End()) 
            {
                cout << it.GetValue() << "; ";
                break;
            }
            cout << it.GetValue() << "; ";
            try {
                it.Next();
            }
            catch (int exIndex) {
                Exception ex(exIndex);
                ex.what();
            }
        }
        cout << endl;
    }
private:
    Node<T>* head;
    int size;

    void RawEraseNode(Node<T>* target) 
    {
        if (target->prev && target->next) 
        {
            target->prev->next = target->next;
            target->next->prev = target->prev;
        }
        else if (target->next == nullptr) 
        {
            target->prev->next = nullptr;
        }
        else if (target->prev == nullptr) 
        {
            head->next->prev = nullptr;
            head = head->next;
        }
        delete target;
        size--;
    }

    Node<T>* GetFreeNode(T l_data, Node<T>* iterator) 
    {
        Node<T>* temp = new Node<T>;
        temp->data = l_data;
        temp->next = nullptr;
        temp->prev = iterator;
        return temp;
    }
};

int main()
{
    setlocale(LC_ALL,"Russian");
    Sotrudnic Sot_1{ 1,"Ivanov",500 };
    Sotrudnic Sot_2{ 2,"Petrov",1000 };
    Sotrudnic Sot_3{ 3,"Sidorov",700 };

    List<Sotrudnic> list;
    list.InNode(Sot_1); 
    list.InNode(Sot_2);
    list.InNode(Sot_3);

    Iterator<Sotrudnic> it = list.Begin(); //получение значений полей объектов
    while (true)
    {
        if (it == list.End())
        {
            cout << it.GetValue().getId() << ";"; 
            cout << it.GetValue().getSalary() << ";";
            cout << it.GetValue().getName() << ";";
            cout << endl;
            break;
        }
        cout << it.GetValue().getId() << "; ";
        cout << it.GetValue().getSalary() << "; ";
        cout << it.GetValue().getName() << "; ";
        cout << endl;
        try
        {
            it.Next();
        }
        catch (int exIndex)
        {
            Exception ex(exIndex);
            ex.what();
        }
    }
    cout << endl;




    List<int> list_int;

    list_int.InNode(7);
    list_int.InNode(4);
    list_int.InNode(3);
    list_int.InNode(11);

    list_int.bubble_sort();
    list_int.print();

    list_int.DelNodeByValue(4);
    cout << "Удаление"<<endl;
    list_int.print();
    cout << endl;

    List<double> list_double;

    list_double.InNode(11.3);
    list_double.InNode(6.2);
    list_double.InNode(4.3);
    list_double.InNode(15.9);

    list_double.bubble_sort();
    list_double.print();
    cout << "Удаление" << endl;
    list_double.DelNodeByValue(4.3);
    list_double.print();
    cout << endl;

    List<char> list_char;

    list_char.InNode('d');
    list_char.InNode('y');
    list_char.InNode('u');
    list_char.InNode('a');

    list_char.bubble_sort();
    list_char.print();
    cout << "Удаление" << endl;
    list_char.DelNodeByValue('y');
    list_char.print();

    return 0;
}
