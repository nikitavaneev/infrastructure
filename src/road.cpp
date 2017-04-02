#include "road.h"
char* road(int x1, int y1, int x2, int y2) {
    char* road = new char[10000];
    int r = 1;
    while (x1 != x2) {
        if (x1 < x2) {
            x1 += r;
            road[r - 1] = 'W';
        }
        if (x1 > x2) {
            x1 -= r;
            road[r - 1] = 'E';
        }
        r++;
    }
    while (y1 != y2) {
        if (y1 < y2) {
            y1 += r;
            road[r - 1] = 'N';
        }
        if (y1 > y2) {
            y1 -= r;
            road[r - 1] = 'S';
        }
        r++;
    }
    road[r - 1] = 0;
    return road;
}