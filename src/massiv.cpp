#include "massiv.h"
int* mass(int *mas, int size) {
    int *a = new int[size];
    int res = 1;
    if (size == 1) {
        a[0] = mas[0];
        return a;
    }
    for (int i = 0; i < size; i++) {
        a[i] = res;
        res *= mas[i];
    }
    res = 1;
    for (int i = size - 1; i >= 0; i--) {
        a[i] *= res;
        res *= mas[i];
    }
    return a;
}
