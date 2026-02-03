#include <iostream>
#include <fstream>

using namespace std;

#include "ArrPrep.cpp"

const char USarr[] = "UnsortedArr.txt"; 
const char Sarr[] = "SortedArr.txt"; 

int linearSerach(unsigned, int*, int);

int main(){
    int target, result;
    fstream filein(USarr, ios_base::in);
    fstream fileout(Sarr, ios_base::out);

    if (!filein.is_open()){
        cout << "Ошибка: входной файл не открывается.\n";
        return 0;
    }

    cout << "Алгоритм линейного поиска.\n\n";
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

    //Вызов функции линейного поиска и проверка на принадлежность
    result = linearSerach(size, arr, target);
    if (result != -1){
        cout << "Элемент (" << target << ") найден под индексом " << result << ".\n";
    } else {
        cout << "Элемент (" << target << ") не найден." << endl;
    }

    delete[] arr;
    return 0;
}



int linearSerach(unsigned size, int* arr, int target){
    for(unsigned i=0; i<size; i++){
        if (arr[i] == target) return i;
    }
    return -1;
}