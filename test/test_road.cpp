#include <gtest/gtest.h>
#include "road.h"


TEST(test, road_done) {
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    for (int i = 0; i < 50; i++, x2 = i, y2 = i) {
        char* r = road(x1, y1, x2, y2);
        int k = 1;
        while (r[k - 1] != 0) {
            if (r[k - 1] == 'N') y1 += k;
            if (r[k - 1] == 'S') y1 -= k;
            if (r[k - 1] == 'E') x1 -= k;
            if (r[k - 1] == 'W') x1 += k;
            k++;
        }
        if (x1 != x2 || y1 != y2) {
            EXPECT_EQ(1, 2);
        }
        x1 = 0;
        y1 = 0;
    }
}
