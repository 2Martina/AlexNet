//____________Normalization1_____________
#include <iostream>
#include <cmath>
#include <ap_fixed.h> //class template from the Vivado-HLS library
typedef ap_fixed<16,7,AP_RND> FixedPoint;  //total:16 , fractional:7 , rounding to the nearest representable value
using namespace std;

// Function to perform fixed-point normalization
void normalization(FixedPoint input[27][27][96], FixedPoint output[27][27][96]) {
    FixedPoint k = 2, alpha = 0.0001, beta = 0.75;
    FixedPoint sum[27][27];

    for (int i = 0; i < 96; i++) {
        for (int j = 0; j < 27; j++) {
            for (int k = 0; k < 27; k++) {
                sum[j][k] = 0;
                for (int m = 0; m <= 2; m++)
                	//it was sum[x][y]
                    sum[j][k] += powf(input[j][k][i], 2);
                output[j][k][i] = (FixedPoint)(input[j][k][i] / (FixedPoint)powf(k + alpha * sum[j][k], beta));
            }
        }
    }
}

// call function and print values for illustration
int main() {
    FixedPoint input[27][27][96];
    FixedPoint output[27][27][96];
    normalization(input, output);
    return 0;
}
