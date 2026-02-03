#include <iostream>
#include <fstream>

using namespace std;

#include "ArrPrep.cpp"

const char USarr[] = "UnsortedArr.txt"; 
const char Sarr[] = "SortedArr.txt"; 

int main(){
    int target, result;
    fstream filein(USarr, ios_base::in);
    fstream fileout(Sarr, ios_base::out);

    if (!filein.is_open()){
        cout << "Ошибка: входной файл не открывается.\n";
        return 0;
    }

    cout << "Алгоритм сортировки с помощью вектора индексов\n\n";

    //Подсчёт размера массива
    unsigned size = Size_calc(&filein);
    filein.clear();
    filein.seekg(0);
    cout << "Размер массива: " << size << endl;

    //Динамическое выделение памяти под массив чисел и массив индексов
    int* arr = new int[size];
    int* idx = new int[size];
    Arr_in(&filein, size, arr);

    //Вызов функции сортировки



    delete[] idx;
    delete[] arr;
    return 0;
}
