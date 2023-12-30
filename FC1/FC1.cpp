//____________FullyConnected1_______________
#include "FC1.h"

// fully connected takes a flattened array of FixedPoint as input
// i.e. a 1D array of size n
// and produces a 1D array of size m
// where m is the number of neurons in the layer

// Function to perform fixed-point fully connected layer
void fullyConnected(FixedPoint input [9216],FixedPoint output [4096],FixedPoint weights [9216][4096],FixedPoint bias [4096]) {
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
