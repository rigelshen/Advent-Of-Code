#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    int inputNumbers [200];
    ifstream file("./input.txt");
    if(file.is_open()){
        for (int i = 0; i < 200; i++){
            file >> inputNumbers[i];
        }
    }
    else{
        cout << "Failed to open file" << endl;
        return 0;
    }

    int n = sizeof(inputNumbers)/sizeof(inputNumbers[0]);
    sort(inputNumbers, inputNumbers+n);
    cout << "n = " << n << endl; 

    for (int i = 0; i < 200; i++){
        for (int j = i + 1; j < 200; j++){
            int targetNum = 2020 - inputNumbers[i] - inputNumbers[j];
            for (int k = j + 1; k < 200; k++){
                if(inputNumbers[i] > 674){
                    break;
                }
                if (inputNumbers[k] == targetNum){
                    int product = inputNumbers[i] * inputNumbers[j] * inputNumbers[k];
                    cout << "Answer found: " << product << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Answer can't be found" << endl;
    return 0;
}