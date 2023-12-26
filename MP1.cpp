#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <ap_fixed.h>
// Fixed-point data type and scaling factor
typedef ap_fixed<16, 7, AP_RND> FPType;

const int INPUT_CHANNELS = 96;
const int INPUT_SIZE = 55;
const int POOL_SIZE = 3;
const int STRIDE = 2;



// Function to perform fixed-point max pooling
vector<vector<vector<FPType>>> maxPooling(const vector<vector<vector<FPType>>>& input) {
    int input_size = input[0].size();
    int output_size = (input_size - POOL_SIZE) / STRIDE + 1;

    // Output initialization
    vector<vector<vector<FPType>>> output(
        INPUT_CHANNELS,
        vector<vector<FPType>>(output_size, vector<FPType>(output_size, 0))
    );

    // Max pooling implementation
    for (int c = 0; c < INPUT_CHANNELS; ++c) {
        for (int i = 0; i < output_size; ++i) {   //output rows
            for (int j = 0; j < output_size; ++j) {  //output columns
                // Extract the sub-matrix for max pooling
                vector<FPType> pool_values;
                for (int pi = 0; pi < POOL_SIZE; ++pi) {
                    for (int pj = 0; pj < POOL_SIZE; ++pj) {
                        pool_values.push_back(input[c][i * STRIDE + pi][j * STRIDE + pj]);
                    }
                }

                // Find the maximum value
                //This function returns an iterator pointing to the maximum
                //element in the range. It performs a linear search through the range.
                FPType max_value = *max_element(pool_values.begin(), pool_values.end()); 

                // Assign the maximum value to the output
                output[c][i][j] = max_value;
            }
        }
    }

    return output;
}

int main() {
    // Sample input (output from a convolution layer), using the previous example
    vector<vector<vector<FPType>>> convolutionOutput(
        INPUT_CHANNELS,
        vector<vector<FPType>>(input_size, vector<FPType>(input_size, 1)) //each element is initialized to 1
    );

    // Max pooling
    vector<vector<vector<FPType>>> poolingResult = maxPooling(convolutionOutput);

    // Display result (for illustration)
    for (int c = 0; c < INPUT_CHANNELS; ++c) {
        for (int i = 0; i < poolingResult[0].size(); ++i) {
            for (int j = 0; j < poolingResult[0][0].size(); ++j) {
                cout << poolingResult[c][i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
