#include <iostream>
#include <fstream>
#include <chrono>
#include <fmt/core.h>
#include <fmt/color.h>

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

#include "randomizer.h"

unsigned Size_calc(ifstream*);
void Arr_in(ifstream*, unsigned, int*);
void printArr(ofstream*, int*, unsigned);

int main() {
    int alg, rand, target, result;
    
    while (rand != 2){
        fmt::print(fg(fmt::color::orange_red), "      Выберите желаемое действие\n");
        fmt::print(fg(fmt::color::orange_red), "--------------------------------------");
        fmt::print(fg(fmt::color::orange_red), "\n1 - открыть генератор случайных чисел\n2 - открыть окно выбора Алгоритмов\n\n");
        fmt::print(fg(fmt::color::orange_red), "Введите число(1 или 2): ");
        cin >> rand;
        
        if (rand == 1){
            randomizer();
        }
    }

    ifstream filein(USarr);
    ifstream filein_bs(Sarr);
    ofstream fileout;
    
    if (!filein.is_open()){
        cerr << "Ошибка: входной файл не открывается.\n";
        return 0;
    }
    
    cout << "\n-------------------------------------------------------------------------\n";
    fmt::print("\nВыберите желаемый алгоритм поиска или сортировки: \n\n");
    fmt::print(fg(fmt::color::orange_red) ,"                SORT\n");
    fmt::print(fg(fmt::color::orange_red) ,"     ---------------------------\n");
    
    fmt::print("     1.  Selection sort Max\n");
    fmt::print("     2.  Selection sort Min\n");
    fmt::print("     3.  Selection sort Min Max\n");
    fmt::print("     4.  Insertion sort\n");
    fmt::print("     5.  Bubble sort\n");
    fmt::print("     6.  Shaker sort\n");
    fmt::print("     7.  Binary Insertion sort\n\n");

    fmt::print(fg(fmt::color::orange_red) ,"                SEARCH\n");
    fmt::print(fg(fmt::color::orange_red) ,"     ---------------------------\n");

    fmt::print("     8.  Linear search\n");
    fmt::print("     9.  Binary search (Нужен отсортированный массив)\n\n");

    fmt::print("Введите номер алгоритма: ");
    cin >> alg;
    fmt::print("\n\n");
    
    for (int i=0; (i <= 5) && (alg < 1 || alg > 9) ; i++){
        if (i == 5){
            cerr << "Бля ты чё даун";
            return 0;
        }
        if (alg < 1 || alg > 9){
            cerr << "Ошибка: Алгоритма под таким номером не существует\n";
            cerr << "Введите номер алгоритма: ";
            cin >> alg; cerr << endl << endl;
        }
    }
    
    if (alg > 7){
        fmt::print("Введите значение для поиска: ");
        cin >> target;
        fmt::print("\n\n");
    }

    
    //Подсчёт размера массива
    unsigned size = Size_calc(&filein);
    filein.clear();
    filein.seekg(0);
    fmt::print("Размер массива: {} \n", size);
    
    //Динамическое выделение памяти под массив чисел
    int* arr = new int[size];
    
    if (alg == 9){
        Arr_in(&filein_bs, size, arr);
    } 
    else {
        Arr_in(&filein, size, arr);
    }
    
    filein.close();
    filein_bs.close();

    // Начала отсчёта интервала времени
    auto start = chrono::steady_clock::now();

    // Запуск выбранного пользователем алгоритма
    switch (alg){
        case 1:
        selectionSortMax(size, arr);
        break;
        case 2:
        selectionSortMin(size, arr);
        break;
        case 3:
        selectionSortMaxMin(size, arr);
        break;
        case 4:
        insertionSort(size, arr);
        break;
        case 5:
        bubbleSort(size, arr);
        break;
        case 6:
        shakerSort(size, arr);
        break;
        case 7:
        binaryInsertionSort(size, arr);
        break;
        case 8:
        result = linearSearch(size, arr, target);
        break;
        case 9:
        result = binarySearch(size, arr, target);
        break;
    }
    
    // Конец отсчёта интервала времени и вычисление разницы
    auto end = chrono::steady_clock::now();
    chrono::duration<double> diff = end - start;
    
    // Заверешающий вывод работы программы
    if (alg > 7){
        if (result != -1){
            fmt::print("Элемент ({0}) найден под индексом {1}.\n", target, result);
        } else {
            fmt::print("Элемент ({}) не найден.\n", target);
        }
    }
    else {
        fileout.open(Sarr);
        printArr(&fileout, arr, size);
        fmt::print("\rСортировка была завершена за {:.3f} секунд\n", diff.count());
    }

    fmt::print("\n-------------------------------------------------------------------------\n");
    fileout.close();
    delete[] arr;
    return 0;
}


unsigned Size_calc(ifstream* filein){
    unsigned size = 0;
    int num;

    while (*filein >> num) size++;

    return size;
}

void Arr_in(ifstream* filein, unsigned size, int* arr){

    for (unsigned i = 0; i < size; i++){
        *filein >> arr[i];
    }

    return;
}

void printArr(ofstream* fileout, int* arr, unsigned size){
    for(unsigned i = 1; i < size; i++){
        *fileout << arr[i] << " ";

        if (i % 15 == 0) *fileout << endl;
    }
}