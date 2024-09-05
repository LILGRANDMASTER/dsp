#include <stdlib.h>
#include <math.h>

float normal_distribution(float mean, float stddev) {
    static int flag = 0;
    static float y2;
    float x1, x2, w, y1;

    if (flag == 0) {
        do {
            x1 = 2.0 * rand() / RAND_MAX - 1;
            x2 = 2.0 * rand() / RAND_MAX - 1;
            w = x1 * x1 + x2 * x2;
        } while (w >= 1.0);

        w = sqrt((-2.0 * log(w)) / w);
        y1 = x1 * w;
        y2 = x2 * w;
        flag = 1;
        return (mean + y1 * stddev);
    } else {
        flag = 0;
        return (mean + y2 * stddev);
    }
}
