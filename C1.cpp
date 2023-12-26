#include <iostream>
#include <vector>

#include <ap_fixed.h> //class template from the Vivado-HLS library
typedef ap_fixed<16,7,AP_RND> FixedPoint;  //total:16 , fractional:7 , rounding to the nearest representable value
using namespace std;

const int INPUT_SIZE = 227;
const int INPUT_CHANNELS = 3;
const int FILTER_SIZE = 11;
const int STRIDE = 4;
const int NUM_FILTERS = 96;



//using FixedPoint = int16_t;  // 16 bits for integer part
//const int SCALE_FACTOR = 16;  // 16 bits for fractional part


// Function to perform fixed-point 3D convolution
vector<vector<vector<FixedPoint>>> convolution3D(
    const vector<vector<vector<FixedPoint>>>& input,
    const vector<vector<vector<FixedPoint>>>& filters,
    const vector<FixedPoint>& biases
) {
    int input_size = input.size();
    int filter_size = filters[0].size();
    int output_size = (input_size - filter_size) / STRIDE + 1;

    // Output initialization
    vector<vector<vector<FixedPoint>>> output(
        NUM_FILTERS,
        vector<vector<FixedPoint>>(output_size, vector<FixedPoint>(output_size, 0))
    );

    // Convolution implementation
    for (int f = 0; f < NUM_FILTERS; ++f) {
        for (int i = 0; i < output_size; ++i) {    //output rows
            for (int j = 0; j < output_size; ++j) {  //output columns
                FixedPoint sum = 0;

                for (int c = 0; c < INPUT_CHANNELS; ++c) {
                    for (int fi = 0; fi < filter_size; ++fi) {    //rows
                        for (int fj = 0; fj < filter_size; ++fj) {  //columns 
                            sum += input[c][i * STRIDE + fi][j * STRIDE + fj] *
                                   filters[f][c][fi][fj];
                        }
                    }
                }

                // Add bias
                sum += biases[f];

                // Apply activation function (ReLU)
                output[f][i][j] = (sum > 0) ? sum : 0;
            }
        }
    }

    return output;
}

int main() {
    // Sample input, filters, and biases
    vector<vector<vector<FixedPoint>>> input(INPUT_CHANNELS,
                                             vector<vector<FixedPoint>>(INPUT_SIZE,
                                                                      vector<FixedPoint>(INPUT_SIZE, 1)));

    vector<vector<vector<FixedPoint>>> filters(NUM_FILTERS,
                                               vector<vector<FixedPoint>>(INPUT_CHANNELS,
                                                                        vector<FixedPoint>(FILTER_SIZE,
                                                                                         vector<FixedPoint>(FILTER_SIZE, 1))));

    vector<FixedPoint> biases(NUM_FILTERS, 1);  //default=1 //we should write all the biaes --------------------

    // Convolution
    vector<vector<vector<FixedPoint>>> result = convolution3D(input, filters, biases);

    // Display result (for illustration)
    for (int f = 0; f < NUM_FILTERS; ++f) {
        for (int i = 0; i < result[0].size(); ++i) {
            for (int j = 0; j < result[0][0].size(); ++j) {
                cout << result[f][i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
