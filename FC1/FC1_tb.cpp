#include "FC1.h"

// read weights_and_biases/conv1_b.txt and conv1_w.txt and store them in weights and biases
// read from file and store in array
void fc6_b( FixedPoint biases[4096]) {
    ifstream file("weights_and_biases/fc6_b.txt");
    string line;
    if (file.is_open()) {
        for (int i = 0; i < 4096; ++i) {
            file >> line; 
            biases[i] = stof(line);
        }
        file.close();
    }
}

void fc6_w( FixedPoint weights[9216][4096]) {
    ifstream file("weights_and_biases/fc6_w.txt");
    string line;
    if (file.is_open()) {
        for (int f = 0; f < 4096; ++f) {
            for (int c = 0; c < 9216; ++c) {
                file >> line;
                weights[c][f] = stof(line);
            }
        }
        file.close();
    }
}

// will read from input image 9216 values and store them in input
// this is an alternative to the output of flatten
void loadInput(FixedPoint input[9216]) {
    ifstream file("input_img.txt");
    string line;
    if (file.is_open()) {
        for (int i = 0; i < 9216; ++i) {
            file >> line;
            input[i] = stof(line);
        }
        file.close();
    }
}

int main()
{
    FixedPoint input[9216];
    FixedPoint output[4096];
    FixedPoint weights[9216][4096];
    FixedPoint biases[4096];
    loadConv1_b(biases);
    loadConv1_w(weights);
    loadInput(input);
    fullyConnected(input [9216],output [4096],weights [9216][4096],bias [4096]);

    return 0;
}