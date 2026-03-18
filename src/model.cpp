#include <string.h>
#include "model.h"


void score(double * input, double * output) {
    double var0[2];
    if (input[2] <= 24.5) {
        memcpy(var0, (double[]){1.0, 0.0}, 2 * sizeof(double));
    } else {
        if (input[1] <= 69.5) {
            if (input[1] <= 59.5) {
                if (input[1] <= 50.5) {
                    if (input[1] <= 40.5) {
                        memcpy(var0, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    } else {
                        memcpy(var0, (double[]){0.04225352112676056, 0.9577464788732394}, 2 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 2.5) {
                        memcpy(var0, (double[]){0.17302052785923755, 0.8269794721407625}, 2 * sizeof(double));
                    } else {
                        memcpy(var0, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 0.5) {
                    if (input[3] <= 57.5) {
                        memcpy(var0, (double[]){0.42424242424242425, 0.5757575757575758}, 2 * sizeof(double));
                    } else {
                        memcpy(var0, (double[]){0.7333333333333333, 0.26666666666666666}, 2 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 1.5) {
                        memcpy(var0, (double[]){0.2230769230769231, 0.7769230769230769}, 2 * sizeof(double));
                    } else {
                        memcpy(var0, (double[]){0.3431372549019608, 0.6568627450980392}, 2 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[1] <= 79.5) {
                if (input[0] <= 0.5) {
                    memcpy(var0, (double[]){1.0, 0.0}, 2 * sizeof(double));
                } else {
                    if (input[0] <= 1.5) {
                        memcpy(var0, (double[]){0.7052631578947368, 0.29473684210526313}, 2 * sizeof(double));
                    } else {
                        memcpy(var0, (double[]){0.8115183246073299, 0.18848167539267016}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 80.5) {
                    if (input[0] <= 1.5) {
                        memcpy(var0, (double[]){0.8461538461538461, 0.15384615384615385}, 2 * sizeof(double));
                    } else {
                        memcpy(var0, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    }
                } else {
                    memcpy(var0, (double[]){1.0, 0.0}, 2 * sizeof(double));
                }
            }
        }
    }
    memcpy(output, var0, 2 * sizeof(double));
}

