#include <fmt/core.h>
#include <cstdio>

void progress_bar(unsigned size, int i){
    if (size < 100) return;

    int step = size / 100;
    
    if (i % step == 0){
        fmt::print("\rИдёт сортировка...  {}%", i/step);
        fflush(stdout);
    }
}