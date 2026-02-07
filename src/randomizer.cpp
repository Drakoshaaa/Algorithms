#include <random>
#include <fmt/core.h>
#include <iostream>
#include <fstream>

using namespace std;
using fmt::print;

void randomizer(){
    const char USarr[] = "assets/UnsortedArr.txt";
    long int range_min, range_max, volume;
    ofstream fileout(USarr);

    print("\n-------------------------------------------------------------------------\n");
    print("                 ГЕНЕРАТОР\n");
    print("Выберите диапазон генерации значений (от 'n' до 'm'): ");
    std::cin >> range_min >> range_max;
    print("Выберите количество генерируемых чисел: ");
    std::cin >> volume; cout << endl;


    //Генерация рандомных чисел в диапазоне, заданном пользователем
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> rand(range_min, range_max);
    print("Генерация чисел...");
    for (int i = 1; i <= volume; i++) {
        fileout << rand(gen) << " ";
        
        if (i%15 == 0) fileout << endl;
    }
    print("\rУспешно, было сгенерировано {0} случайных чисел в диапазоне ({1}, {2})\nПроверьте файл {3}", volume, range_min, range_max, USarr);
    print("\n-------------------------------------------------------------------------\n");
    fileout.close();
}
