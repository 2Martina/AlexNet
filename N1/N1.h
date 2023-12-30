#include <iostream>
#include <fstream>
#include <cmath>
#include <ap_fixed.h> //class template from the Vivado-HLS library

typedef ap_fixed<16,7,AP_RND> FixedPoint;  //total:16 , fractional:7 , rounding to the nearest representable value
using namespace std;


void normalization(FixedPoint input[27][27][96], FixedPoint output[27][27][96]);