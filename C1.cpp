#include <iostream>
#include <ap_fixed.h>

typedef ap_fixed<16, 7, AP_RND> FixedPoint;
using namespace std;

/*const int INPUT_SIZE = 227;
const int INPUT_CHANNELS = 3;
const int FILTER_SIZE = 11;
const int STRIDE = 4;
const int NUM_FILTERS = 96;*/


#define INPUT_SIZE 227
#define INPUT_CHANNELS 3
#define FILTER_SIZE 11
#define STRIDE 4
#define NUM_FILTERS 96
#define OUTPUT_SIZE 55


// Function to perform fixed-point 3D convolution
void convolution3D(
    const FixedPoint input[INPUT_CHANNELS][INPUT_SIZE][INPUT_SIZE],
    const FixedPoint filters[NUM_FILTERS][INPUT_CHANNELS][FILTER_SIZE][FILTER_SIZE],
    const FixedPoint biases[NUM_FILTERS],
    int output_size
) {
    FixedPoint output[NUM_FILTERS][55][55]; // Assuming fixed output size, change accordingly

    // Convolution implementation
    for (int f = 0; f < NUM_FILTERS; ++f) {
        for (int i = 0; i < output_size; ++i) {
            for (int j = 0; j < output_size; ++j) {
                output[f][i][j] = 0;
                for (int c = 0; c < INPUT_CHANNELS; ++c) {
                    for (int k = 0; k < FILTER_SIZE; ++k) {
                        for (int l = 0; l < FILTER_SIZE; ++l) {
                            output[f][i][j] += input[c][STRIDE * i + k][STRIDE * j + l] * filters[f][c][k][l];
                        }
                    }
                }
                output[f][i][j] += biases[f];
                // ReLU activation
                output[f][i][j] = output[f][i][j] > FixedPoint(0) ? output[f][i][j] : FixedPoint(0);
            }
        }
    }
}

int main() {
    FixedPoint input[INPUT_CHANNELS][INPUT_SIZE][INPUT_SIZE];
    FixedPoint filters[NUM_FILTERS][INPUT_CHANNELS][FILTER_SIZE][FILTER_SIZE];
    FixedPoint biases[NUM_FILTERS];
    convolution3D(input, filters, biases, OUTPUT_SIZE);
    return 0;
}

