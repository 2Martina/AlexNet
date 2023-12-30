#include <iostream>
#include <fstream>
#include <ap_fixed.h>

typedef ap_fixed<16, 7, AP_RND> FixedPoint;
using namespace std;

#define INPUT_SIZE 227
#define INPUT_CHANNELS 3
#define FILTER_SIZE 11
#define STRIDE 4
#define NUM_FILTERS 96
#define OUTPUT_SIZE 55

void convolution3D( FixedPoint input[INPUT_CHANNELS][INPUT_SIZE][INPUT_SIZE],
                    FixedPoint output[NUM_FILTERS][OUTPUT_SIZE][OUTPUT_SIZE],
                    FixedPoint filters[NUM_FILTERS][INPUT_CHANNELS][FILTER_SIZE][FILTER_SIZE],
                    FixedPoint biases[NUM_FILTERS]);