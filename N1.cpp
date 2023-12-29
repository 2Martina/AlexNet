//____________Normalization1_____________
#include <iostream>
#include <ap_fixed.h> //class template from the Vivado-HLS library
typedef ap_fixed<16,7,AP_RND> FixedPoint;  //total:16 , fractional:7 , rounding to the nearest representable value
using namespace std;

// Function to perform fixed-point normalization

void normalization(FixedPoint input [27][27][96], FixedPoint output [27][27][96], FixedPoint gamma [96], FixedPoint beta [96]) {

    FixedPoint mean[96];
    FixedPoint std[96];

    // mean and std initialization
    for (int i = 0; i < 96; ++i) { 
        mean[i] = 0;
        std[i] = 0;
    }

    // calculate the mean for 27*27 elements
    for (int i = 0; i < 96; ++i) { // number of channels
        for (int j = 0; j < 27; ++j) { // number of rows
            for (int k = 0; k < 27; ++k) { // number of columns
                mean[i] += input[j][k][i];
            }
        }
        mean[i] = (FixedPoint) (mean[i] / (27 * 27));
    }

    // calculate the standard deviation for 27*27 elements
    for (int i = 0; i < 96; ++i) { // number of channels
        for (int j = 0; j < 27; ++j) { // number of rows
            for (int k = 0; k < 27; ++k) { // number of columns
                std += (input[j][k][i] - mean[i]) * (input[j][k][i] - mean[i]);
            }
        }
        std[i] = (FixedPoint) (std[i] / (27 * 27));
    }

    // Normalization implementation
    // LayerNorm(x) = alpha * (x - mean) / std + beta
    // x: The input features at a particular spatial location
    // mean: The mean of the input features
    // std: The standard deviation of the input features
    // alpha: The first scaling parameter
    // beta: The second scaling parameter
    for (int i = 0; i < 96; ++i) { // number of channels
        for (int j = 0; j < 27; ++j) { // number of rows
            for (int k = 0; k < 27; ++k) { // number of columns
                output[j][k][i] = (FixedPoint) (gamma[i]*(input[j][k][i] - mean[i]) / std[i] + beta[i]);
            }
        }
    }
}

// call function and print values for illustration
int main()
{
    FixedPoint input[27][27][96];
    FixedPoint output[27][27][96];
    FixedPoint gamma[96];
    FixedPoint beta[96];

    // input initialization

    // gamma initialization

    // beta initialization

    // call normalization function
    normalization(input, output, gamma, beta);

    return 0;
}