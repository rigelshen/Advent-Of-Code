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
        if(inputNumbers[i] > 1010){
            break;
        }
        int targetNum = 2020 - inputNumbers[i];
        for (int j = i +1; j < 200; j++){
            if (inputNumbers[j] == targetNum){
                int product = inputNumbers[i] * inputNumbers[j];
                cout << "Answer found: " << product << endl;
                return 0;
            }
        }
    }

    cout << "Answer can't be found" << endl;
    return 0;
}