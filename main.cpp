#include <iostream>
#include <iomanip>
#include "Class.h"

using namespace std;

int sum_by_value(int value);
int sum_by_reference(int &reference);
int sum_by_pointer(int *ptrvalue);

int main()
{
    {
        ///////////////////////////
        // Указатели
        ///////////////////////////
        // Oбъявление указателя
        // [тип данных] * [имя указателя];

        int var = 123; // инициализация переменной var числом 123
        int *ptrvar = &var; // указатель на переменную var (присвоили адрес переменной указателю)
        cout << "&var    = " << &var
             << endl;// адрес переменной var содержащийся в памяти, извлечённый операцией взятия адреса
        cout << "ptrvar  = " << ptrvar << endl;// адрес переменной var, является значением указателя ptrvar
        cout << "var     = " << var << endl; // значение в переменной var
        cout << "*ptrvar = " << *ptrvar
             << endl; // вывод значения содержащегося в переменной var через указатель, операцией разименования указателя

        int *ptrvar2;        // объявление указателя
        ptrvar2 = &var;     // инициализация указателя

        cout << "ptrvar  = " << ptrvar << endl;
        cout << "ptrvar2  = " << ptrvar2 << endl;

        cout << "--------------------------------------" << endl;
    }


    {
        ///////////////////////////
        // Указатели на указатели
        ///////////////////////////
        int v = 123; // инициализация переменной var числом 123
        int *pv = &v; // указатель на переменную var
        int **p_pv = &pv; // указатель на указатель на переменную var
        int ***p_p_pv = &p_pv;
        cout << " var        = " << v << endl;
        cout << " *pv        = " << *pv << endl;
        cout << " **p_pv     = " << **p_pv << endl; // два раза разименовываем указатель, так как он второго порядка
        cout << " ***p_p_pv  = " << ***p_p_pv << endl; // указатель третьего порядка
        cout << "\n ***p_p_pv \t\t-> **p_pv \t\t\t-> *pv \t\t\t\t->  v " << endl;
        cout << p_p_pv << " \t-> " << p_pv << " \t->" << pv << " \t-> " << v << endl;

        cout << "--------------------------------------" << endl;
    }

    {
        ///////////////////////////
        // Ссылки
        ///////////////////////////
        // структура объявления ссылок
        // [тип] &[имя ссылки] = [имя переменной];
        int value = 15;
        int &reference = value; // объявление и инициализация ссылки значением переменной value
        cout << "value     = " << value << endl;
        cout << "reference = " << reference << endl;
        reference += 15; // изменяем значение переменной value посредством изменения значения в ссылке
        cout << "value     = " << value
             << endl; // смотрим, что получилось, как будет видно дальше значение поменялось как в ссылке,
        cout << "reference = " << reference << endl; //  так и в ссылочной переменной


        int vv = 10;
        cout << "sum_by_value     = " << sum_by_value(vv) << endl;
        cout << "value = " << value << endl; // значение переменной осталось неизменным
        cout << "sum_by_reference = " << sum_by_reference(vv) << endl;
        cout << "value = " << value << endl; // значение переменной изменилось
        cout << "sum_by_pointer   = " << sum_by_pointer(&vv) << endl;
        cout << "value = " << value << endl; // значение переменной изменилось ещё раз


        cout << "--------------------------------------" << endl;
    }


    {
        ///////////////////////////
        // Динамический массив
        ///////////////////////////
        // пример использования операции new
        int *ptrvalue = new int;
        //где ptrvalue – указатель на выделенный участок памяти типа int
        //new – операция выделения свободной памяти под создаваемый объект.

        // пример использования операции delete:
        delete ptrvalue;
        // где ptrvalue – указатель на выделенный участок памяти типа int
        // delete – операция высвобождения памяти

        int *ptr_value = new int; // динамическое выделение памяти под объект типа int
        *ptr_value = 9; // инициализация объекта через указатель
        //int *ptr_value = new int (9); инициализация может выполнятся сразу при объявлении динамического объекта
        cout << "ptr_value = " << *ptr_value << endl;
        delete ptr_value; // высвобождение памяти

        ///////////
        // объявление одномерного динамического массива на 10 элементов:
        float *ptrarray = new float[10];
        //  где ptrarray  – указатель на выделенный участок памяти под массив вещественных чисел  типа float
        //           в квадратных скобочках указываем размер массива
        // высвобождение памяти отводимой под одномерный динамический массив:
        delete[] ptrarray;


        srand(time(0)); // генерация случайных чисел
        float *ptr_array = new float[10]; // создание динамического массива вещественных чисел на десять элементов
        for (int count = 0; count < 10; count++)
            ptr_array[count] = (rand() % 10 + 1) / float((rand() % 10 +
                                                          1)); //заполнение массива случайными числами с масштабированием от 1 до 10
        cout << "array = ";
        for (int count = 0; count < 10; count++)
            cout << setprecision(2) << ptr_array[count] << "    ";
        delete[] ptr_array; // высвобождение памяти
        cout << endl;

        cout << "--------------------------------------" << endl;
    }


    {
        ///////////////////////////
        // Массивы в классах
        ///////////////////////////
        Class c(10);
        for (int i = 0; i < 10; ++i)
            c.get_arr()[i] = i;

        cout << c.get_arr()[9] << endl;
    }



    return 0;
}

int sum_by_value(int value)// функция принимающая аргумент по значению
{
    value += value;
    return value;
}

int sum_by_reference(int &reference) // функция принимающая аргумент по ссылке
{
    reference += reference;
    return reference;
}

int sum_by_pointer(int *ptrvalue)// функция принимающая аргумент через указатель
{
    *ptrvalue += *ptrvalue;// арифметика с указателем
    return *ptrvalue;
}