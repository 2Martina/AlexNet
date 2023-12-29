#include <iostream>
#include <ap_fixed.h>

typedef ap_fixed<16, 7, AP_RND> FixedPoint;

// Function to perform fixed-point fully connected layer
void fullyConnected(FixedPoint input[9216], FixedPoint output[4096], FixedPoint weights[9216][4096], FixedPoint bias[4096]) {
    // Output initialization
    for (int i = 0; i < 4096; ++i) {
        output[i] = 0;
    }

    // Fully connected implementation
    for (int i = 0; i < 4096; ++i) {
        for (int j = 0; j < 9216; ++j) {
            output[i] += input[j] * weights[j][i];
        }
        output[i] += bias[i];

        // ReLU activation
        output[i] = output[i] > FixedPoint(0) ? output[i] : FixedPoint(0);
    }
}
