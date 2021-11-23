// newVector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

template<typename T>
class Vector {
private:
    T* array;
    int trueSize = 0;
    int size = 0;
    void size1() {
        T* newArray = new T[trueSize];
        for (int i = 0; i < trueSize; i++)
            newArray[i] = array[i];
        delete[] array;
        array = new T[trueSize * 2];
        for (int i = 0; i < trueSize; i++)
            array[i] = newArray[i];
        delete[] newArray;
        trueSize = 2 * trueSize;
    }
public:
    Vector(int n)
    {
        trueSize = n;
        array = new T[trueSize];
    }

    void print_Vector() {
        for (int i = 0; i < size; i++)
            std::cout << array[i] << " ";
        std::cout << std::endl;
    }
    void pop_back() {
        if (size > 0)
            size--;
    }
    void push_back(T x) {
        if (trueSize <= size)
            size1();
        array[size] = x;
        size++;
    }
    void resize(int n) {
        T* newArray = new T[trueSize];
        for (int i = 0; i < trueSize; i++)
            newArray[i] = array[i];
        delete[] array;
        array = new T[n];
        for (int i = 0; i < std::min(n, trueSize); i++)
            array[i] = newArray[i];
        delete[] newArray;
        trueSize = n;
    }
    int getElement(int n) {
        return array[n - 1];
    }

    ~Vector() {
        delete[] array;
    }
};

int main()
{
    Vector<std::string> v(3);
    v.push_back("QWE");
    v.push_back("Dcv");
    v.print_Vector();


}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
