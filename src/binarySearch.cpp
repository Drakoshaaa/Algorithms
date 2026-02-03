#include <iostream>
#include <fstream>

using namespace std;

#include "ArrPrep.cpp"

const char USarr[] = "UnsortedArr.txt"; 
const char Sarr[] = "SortedArr.txt"; 

int  binarySearch(unsigned, int*, int);

int main(){
    int target, result;
    fstream filein(Sarr, ios_base::in);

    if (!filein.is_open()){
        cout << "Ошибка: входной файл не открывается.\n";
        return 0;
    }

    cout << "Алгоритм бинарного поиска\n\n";
    cout << "Введите число для Поиска: ";
    cin >> target; cout << endl;

    //Подсчёт размера массива
    unsigned size = Size_calc(&filein);
    filein.clear();
    filein.seekg(0);
    cout << "Размер массива: " << size << endl;

    //Динамическое выделение памяти под массив чисел
    int* arr = new int[size];
    Arr_in(&filein, size, arr);

    //Вызоа функции бинарного поиска и проверка и проверка на принадлежность
    result = binarySearch(size, arr, target);
    if (result != -1){
        cout << "Элемент (" << target << ") найден под индексом " << result << ".\n";
    } else {
        cout << "Элемент (" << target << ") не найден." << endl;
    }

    delete[] arr;
    return 0;
}



int binarySearch(unsigned size, int* arr, int target){
    int left = 0;
    int right = size - 1;

    while (left <= right){
        int mid = (left + right) / 2;

        if (arr[mid] == target){
            return mid;
        }
        else if (arr[mid] < target){
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}