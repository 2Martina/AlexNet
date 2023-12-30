//_______MaxPooling1_______

#include "MP1.h"

const int INPUT_CHANNELS = 96;
const int INPUT_SIZE = 55;
const int POOL_SIZE = 3;
const int STRIDE = 2;

FPType max(FPType a[3][3]) {
    FPType max_value = a[0][0];
    for (int i = 0; i < POOL_SIZE; ++i) {
        for (int j = 0; j < POOL_SIZE; ++j) {
            if (a[i][j] > max_value) {
                max_value = a[i][j];
            }
        }
    }
    return max_value;
}


// Function to perform fixed-point max pooling
void maxPooling(FPType input[96][55][55],FPType output[96][27][27]) {
    int input_size = 55;
    int output_size = 27;

    // Output initialization
    for (int c = 0; c < INPUT_CHANNELS; ++c) {
        for (int i = 0; i < output_size; ++i) {
            for (int j = 0; j < output_size; ++j) {
                output[c][i][j] = 0;
            }
        }
    }

    FPType pool_values[3][3];
    // Max pooling implementation
    for (int c = 0; c < INPUT_CHANNELS; ++c) {
        for (int i = 0; i < output_size; ++i) {   //output rows
            for (int j = 0; j < output_size; ++j) {  //output columns
                // Extract the sub-matrix for max pooling
                for (int pi = 0; pi < POOL_SIZE; ++pi) {
                    for (int pj = 0; pj < POOL_SIZE; ++pj) {
                        pool_values[pi][pj] = input[c][i * STRIDE + pi][j * STRIDE + pj];
                    }
                }

                // Find the maximum value
                //This function returns an iterator pointing to the maximum
                //element in the range. It performs a linear search through the range.
                FPType max_value = max(pool_values); 

                // Assign the maximum value to the output
                output[c][i][j] = max_value;
            }
        }
    }

    //return output;
}