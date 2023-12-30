#include "C1.h"

// read weights_and_biases/conv1_b.txt and conv1_w.txt and store them in weights and biases
// read from file and store in array
void loadConv1_b( FixedPoint biases[96]) {
    ifstream file("weights_and_biases/conv1_b.txt");
    string valueAsString;
    if (file.is_open()) {
        for (int i = 0; i < 96; ++i) {
            file >> valueAsString;
            biases[i] = stof(valueAsString);
        }
    }
    file.close();
}

void loadConv1_w( FixedPoint filters[96][3][11][11]) {
    ifstream file("weights_and_biases/conv1_w.txt");
    string valueAsString;
    if (file.is_open()) {
        for (int f = 0; f < 96; ++f) {
            for (int c = 0; c < 3; ++c) {
                for (int i = 0; i < 11; ++i) {
                    for (int j = 0; j < 11; ++j) {
                        file >> valueAsString; 
                        filters[f][c][i][j] = stof(valueAsString);
                    }
                }
            }
        }
    }
    file.close();
}

// load input img from file
void loadInputImage( FixedPoint input[3][227][227]) {
    ifstream file("input_img.txt");
    string valueAsString;
    if (file.is_open()) {
        for (int c = 0; c < 3; ++c) {
            for (int i = 0; i < 227; ++i) {
                for (int j = 0; j < 227; ++j) {
                    file >> valueAsString; 
                    input[c][i][j] = stof(valueAsString);
                }
            }
        }
    }
    file.close();
}

int main()
{
    FixedPoint input[3][227][227];
    FixedPoint output[96][55][55];
    FixedPoint filters[96][3][11][11];
    FixedPoint biases[96];
    
    loadConv1_b(biases);
    loadConv1_w(filters);
    loadInputImage(input);
    convolution3D(input,output,filters, biases);

    
    cout << "output[0][0][0] = " << output[0][0][0] << endl;

    return 0;
}