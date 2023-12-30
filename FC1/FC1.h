#include <iostream>
#include <ap_fixed.h> //class template from the Vivado-HLS library
typedef ap_fixed<16,7,AP_RND> FixedPoint;  //total:16 , fractional:7 , rounding to the nearest representable value
using namespace std;


void fullyConnected(FixedPoint input [9216],FixedPoint output [4096],FixedPoint weights [9216][4096],FixedPoint bias [4096]);