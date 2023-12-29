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
        for (int i = 0; i < output_size; ++i) {  // Output rows
            for (int j = 0; j < output_size; ++j) {  // Output columns
                FixedPoint sum = 0;

                for (int c = 0; c < INPUT_CHANNELS; ++c) {
                    for (int fi = 0; fi < FILTER_SIZE; ++fi) {  // Rows
                        for (int fj = 0; fj < FILTER_SIZE; ++fj) {  // Columns
                            sum += input[c][i * STRIDE + fi][j * STRIDE + fj] *
                                   filters[f][c][fi][fj];
                        }
                    }
                }

                // Add bias
                sum += biases[f];

            }
        }
    }
}

int main() {
    // Sample input, filters, and biases
    FixedPoint input[INPUT_CHANNELS][INPUT_SIZE][INPUT_SIZE] = {{{1}}};  // Initialize with your actual data
    FixedPoint filters[NUM_FILTERS][INPUT_CHANNELS][FILTER_SIZE][FILTER_SIZE] = {{{{1}}}};  // Initialize with your actual data
    FixedPoint biases[NUM_FILTERS] = {1};  // Initialize with your actual data


    FixedPoint output[NUM_FILTERS][OUTPUT_SIZE][OUTPUT_SIZE];


    // Convolution
    convolution3D(input, filters, biases, OUTPUT_SIZE);


    for (int f = 0; f < NUM_FILTERS; ++f) {
        for (int i = 0; i < OUTPUT_SIZE; ++i) {
            for (int j = 0; j < OUTPUT_SIZE; ++j) {
                int output_index = f * OUTPUT_SIZE * OUTPUT_SIZE + i * OUTPUT_SIZE + j;

                // Apply ReLU activation
                output[f][i][j] = (output[f][i][j] > 0) ? output[f][i][j] : FixedPoint(0);
            }
        }
    }

    // Display result (for illustration)
   /* for (int f = 0; f < NUM_FILTERS; ++f) {
        for (int i = 0; i < output_size; ++i) {
            for (int j = 0; j < output_size; ++j) {
                cout << output[f][i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }*/

    return 0;
}
