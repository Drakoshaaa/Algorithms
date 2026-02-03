#include <iostream>
#include <fstream>

using namespace std;

const char USarr[] = "assets/UnsortedArr.txt"; 
const char Sarr[] = "assets/SortedArr.txt"; 

#include "binaryInsertionSort.h"
#include "binarySearch.h"
#include "bubbleSort.h"
#include "insertionSort.h"
#include "linearSearch.h"
#include "selectionSortMax.h"
#include "selectionSortMaxMin.h"
#include "selectionSortMin.h"
#include "shakerSort.h"

unsigned Size_calc(fstream*);
void Arr_in(fstream*, unsigned, int*);
void printArr(fstream*, int*, unsigned);

int main() {
    int alg, target, result;

    fstream filein(USarr, ios_base::in);
    fstream fileout(Sarr, ios_base::out);

    if (!filein.is_open()){
        cout << "Ошибка: входной файл не открывается.\n";
        return 0;
    }

    cout << "Выберите желаемый алгоритм поиска или сортировки: \n\n"
         << "           SORT\n"
         << "---------------------------\n"
         << "1.  Selection sort Max\n"
         << "2.  Selection sort Min\n"
         << "3.  Selection sort Min Max\n"
         << "4.  Insertion sort\n"
         << "5.  Bubble sort\n"
         << "6.  Shaker sort\n"
         << "7.  Binary Insertion sort\n\n"
         << "           SEARCH\n"
         << "---------------------------\n"
         << "8.  Linear search\n"
         << "9.  Binary search\n\n";

    cout << "Введите номер алгоритма: ";
    cin >> alg;
    cout << endl << endl;

    for (int i=0; (i <= 5) && (alg < 1 || alg > 9) ; i++){
        if (i == 5){
            cout << "Бля ты чё даун";
            return 0;
        }
        if (alg < 1 || alg > 9){
            cout << "Ошибка: Алгоритма под таким номером не существует\n";
            cout << "Введите номер алгоритма: ";
            cin >> alg; cout << endl << endl;
        }
    }

    if (alg > 7){
        cout << "Введите значение для поиска: ";
        cin >> target;
        cout << endl << endl;
    }

    //Подсчёт размера массива
    unsigned size = Size_calc(&filein);
    filein.clear();
    filein.seekg(0);
    cout << "Размер массива: " << size << endl;

    //Динамическое выделение памяти под массив чисел
    int* arr = new int[size];
    Arr_in(&filein, size, arr);

    switch (alg){
        case 1:
            cout << "Идёт сортировка...\n";
            selectionSortMax(size, arr);
            break;
        case 2:
            cout << "Идёт сортировка...\n";
            selectionSortMin(size, arr);
            break;
        case 3:
            cout << "Идёт сортировка...\n";
            selectionSortMaxMin(size, arr);
            break;
        case 4:
            cout << "Идёт сортировка...\n";
            insertionSort(size, arr);
            break;
        case 5:
            cout << "Идёт сортировка...\n";
            bubbleSort(size, arr);
            break;
        case 6:
            cout << "Идёт сортировка...\n";
            shakerSort(size, arr);
            break;
        case 7:
            cout << "Идёт сортировка...\n";
            binaryInsertionSort(size, arr);
            break;
        case 8:
            result = linearSearch(size, arr, target);
            break;
        case 9:
            selectionSortMaxMin(size, arr);
            result = binarySearch(size, arr, target);
            break;
    }

    if (alg > 7){
        if (result != -1){
            cout << "Элемент (" << target << ") найден под индексом " << result << ".\n";
        } else {
            cout << "Элемент (" << target << ") не найден." << endl;
        }
    }
    else {
        printArr(&fileout, arr, size);
        cout << "Сортировка завершена.\n";
    }

    delete[] arr;
    return 0;
}


unsigned Size_calc(fstream* filein){
    unsigned size = 0;
    int num;

    while (*filein >> num) size++;

    return size;
}

void Arr_in(fstream* filein, unsigned size, int* arr){

    for (unsigned i = 0; i < size; i++){
        *filein >> arr[i];
    }

    return;
}

void printArr(fstream* fileout, int* arr, unsigned size){
    for(unsigned i = 1; i < size; i++){
        *fileout << arr[i] << " ";

        if (i % 15 == 0) *fileout << endl;
    }
}