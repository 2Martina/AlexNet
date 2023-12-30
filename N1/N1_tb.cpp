#include "N1.h"

// 27x27x96 values are extracted from input_img.txt
// this is an alternative to the output of the convolutional layer
void read_input(FPType input[27][27][96])
{
    ifstream file("input_img.txt");
    string line;
    if (file.is_open()) {
        for (int i = 0; i < 27; i++)
            for (int j = 0; j < 27; j++)
                for (int k = 0; k < 96; k++) {
                    file >> line;
                    input[i][j][k] = stof(line);
                }
        file.close();
    }
}

int main()
{
    // input and output arrays
    FPType input[27][27][96];
    FPType output[27][27][96];
    // read input values from file
    read_input(input);
    normalization(input, output);
    return 0;
}