//maxPooling(convolutionOutput, poolingResult);

#include "MP1.h"

// 55x55x96 values will be extracted from input_img.txt
// this is an alternative to feature map comming from convolution layers
void readInput(FPType input[55][55][96])
{
    ifstream file("input_img.txt");
    string line;
    if (file.is_open()){
        for (int c = 0; c < 96; ++c) {
            for (int i = 0; i < 55; ++i) {
                for (int j = 0; j < 55; ++j) {
                    getline(file, line);
                    input[i][j][c] = stof(line);
                }
            }
        }
        file.close();
    }
}

int main()
{
    // declare input and output arrays
    FPType input[55][55][96];
    FPType output[27][27][96];
    // call maxPooling function
    readInput(input);
    maxPooling(input, output);
    // print the results
    cout << output[0][0][0] << endl;

    return 0;
}