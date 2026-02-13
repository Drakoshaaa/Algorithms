#include <iostream>
#include <fstream>
#include <chrono>
#include <cassert>
#include <fmt/core.h>
#include <fmt/color.h>

using namespace std;

const char USarr[] = "assets/UnsortedArr.txt"; 
const char Sarr[] = "assets/SortedArr.txt"; 

#include "sortAlgos.h"
#include "searchAlgos.h"
#include "randomizer.h"

unsigned Size_calc(ifstream*);
void Arr_in(ifstream*, unsigned, int*);
void printArr(ofstream*, int*, unsigned);

enum AlgoKind {
    ALGO_SORT,
    ALGO_SEARCH
};

typedef int (*algo_search_fn)(unsigned size, int *arr, int target);
typedef void (*algo_sort_fn)(unsigned size, int *arr);

struct Algo {
    const char *desc;
    AlgoKind kind;
    union {
        algo_search_fn search;
        algo_sort_fn   sort;
    };

    Algo(algo_search_fn fn, const char *desc)
        : desc(desc)
        , kind(ALGO_SEARCH)
        , search(fn)
    {}

    Algo(algo_sort_fn fn, const char *desc)
        : desc(desc)
        , kind(ALGO_SORT)
        , sort(fn)
    {}

    void operator()(unsigned size, int *arr) {
        assert(kind == ALGO_SORT);
        return sort(size, arr);
    }

    int operator()(unsigned size, int *arr, int target) {
        assert(kind == ALGO_SEARCH);
        return search(size, arr, target);
    }
};

int main() {
    int alg, rand, target, result, *arr;
    unsigned size;
    
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

    Algo algos[] = {
        {selectionSortMax, "Selection sort Max"},
        {selectionSortMin, "Selection sort Min"},
        {selectionSortMaxMin, "Selection sort Min Max"},
        {insertionSort, "Insertion sort"},
        {bubbleSort, "Bubble sort"},
        {shakerSort, "Shaker sort"},
        {binaryInsertionSort, "Binary Insertion sort"},
        {linearSearch, "Linear search"},
        {binarySearch, "Binary search (Нужен отсортированный массив)"},
    };

    ifstream filein(USarr);
    ifstream filein_bs(Sarr);
    ofstream fileout;
    
    if (!filein.is_open()){
        cerr << "Ошибка: входной файл не открывается.\n";
        return 0;
    }

    cout << "\n-------------------------------------------------------------------------\n";
    fmt::print("\nВыберите желаемый алгоритм поиска или сортировки: \n\n");

    for (size_t i = 0; i < std::size(algos); ++i) {
        auto &algo = algos[i];
        if (i == 0 || algo.kind != algos[i-1].kind) {
            switch (algo.kind) {
                case ALGO_SORT:
                    fmt::print(fg(fmt::color::orange_red) ,"                SORT\n");
                    break;
                case ALGO_SEARCH:
                    fmt::print(fg(fmt::color::orange_red) ,"                SEARCH\n");
                    break;
            }
            fmt::print(fg(fmt::color::orange_red) ,"     ---------------------------\n");
        }
        fmt::print("     {}.  {}\n", i + 1, algo.desc);
    }
    
    fmt::print("Введите номер алгоритма: ");
    cin >> alg;
    fmt::print("\n\n");
    
    for (int i=0; (i <= 5) && (alg < 1 || alg > std::size(algos)) ; i++){
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
    
    alg -= 1;

    if (algos[alg].kind == ALGO_SEARCH){
        fmt::print("Введите значение для поиска: ");
        cin >> target;
        fmt::print("\n\n");
    }
    
    //Подсчёт размера массива
    size = Size_calc(&filein);
    filein.clear();
    filein.seekg(0);
    fmt::print("Размер массива: {} \n", size);
    
    //Динамическое выделение памяти под массив чисел
    arr = new int[size];
    
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
    switch (algos[alg].kind) {
        case ALGO_SORT: algos[alg](size, arr); break;
        case ALGO_SEARCH: result = algos[alg](size, arr, target); break;
    }
    
    // Конец отсчёта интервала времени и вычисление разницы
    auto end = chrono::steady_clock::now();
    chrono::duration<double> diff = end - start;
    
    // Заверешающий вывод работы программы
    switch (algos[alg].kind) {
        case ALGO_SEARCH:
            if (result != -1){
                fmt::print("Элемент ({0}) найден под индексом {1}.\n", target, result);
            } else {
                fmt::print("Элемент ({}) не найден.\n", target);
            }
            break;
        case ALGO_SORT:
            fileout.open(Sarr);
            printArr(&fileout, arr, size);
            fmt::print("\rСортировка была завершена за {:.3f} секунд\n", diff.count());
            break;
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
