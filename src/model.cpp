#include <string.h>
#include "model.h"

void score(double * input, double * output) {
    double var0[3];
    if (input[2] <= 24.5) {
        memcpy(var0, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if (input[1] <= 69.5) {
            if (input[1] <= 49.5) {
                if (input[1] <= 39.5) {
                    if (input[1] <= 30.5) {
                        memcpy(var0, (double[]){0.0, 0.9993932038834952, 0.0006067961165048543}, 3 * sizeof(double));
                    } else {
                        memcpy(var0, (double[]){0.0, 0.9559748427672956, 0.0440251572327044}, 3 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 2.5) {
                        memcpy(var0, (double[]){0.060324825986078884, 0.8491879350348028, 0.09048723897911833}, 3 * sizeof(double));
                    } else {
                        memcpy(var0, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 59.5) {
                    if (input[0] <= 2.5) {
                        memcpy(var0, (double[]){0.14769975786924938, 0.7360774818401937, 0.1162227602905569}, 3 * sizeof(double));
                    } else {
                        memcpy(var0, (double[]){0.0, 0.7131147540983607, 0.28688524590163933}, 3 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 33.5) {
                        memcpy(var0, (double[]){0.16906474820143885, 0.4460431654676259, 0.38489208633093525}, 3 * sizeof(double));
                    } else {
                        memcpy(var0, (double[]){0.27472527472527475, 0.5054945054945055, 0.21978021978021978}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[1] <= 80.5) {
                if (input[1] <= 70.5) {
                    if (input[3] <= 25.850000381469727) {
                        memcpy(var0, (double[]){0.5, 0.25, 0.25}, 3 * sizeof(double));
                    } else {
                        memcpy(var0, (double[]){0.2037037037037037, 0.12962962962962962, 0.6666666666666666}, 3 * sizeof(double));
                    }
                } else {
                    if (input[3] <= 53.5) {
                        memcpy(var0, (double[]){0.5668449197860963, 0.08288770053475936, 0.3502673796791444}, 3 * sizeof(double));
                    } else {
                        memcpy(var0, (double[]){0.43169398907103823, 0.1366120218579235, 0.43169398907103823}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 90.5) {
                    if (input[0] <= 0.5) {
                        memcpy(var0, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var0, (double[]){0.8636363636363636, 0.0, 0.13636363636363635}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var0, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                }
            }
        }
    }
    memcpy(output, var0, 3 * sizeof(double));
}

