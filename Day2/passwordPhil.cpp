#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct PasswordLine {
    int min;
    int max;
    string letter;
    string password;
};

int main()
{
    ifstream file("./input.txt");
    int numOfValid = 0;
    if(file.is_open()){
        string range;
        string inputLetter;
        string inputPswrd;
        while(file >> range >> inputLetter >> inputPswrd){
            PasswordLine currentLine;
            
            currentLine.password = inputPswrd;

            inputLetter.pop_back();
            currentLine.letter = inputLetter;

            int found = range.find('-');
            string minString = "";
            string maxString = "";
            for (int i = 0; i < found; i++){
                minString += range[i];
            }
            for (int i = found + 1; i < range.length(); i++){
                maxString += range[i];
            }
            currentLine.min = stoi(minString);
            currentLine.max = stoi(maxString);

            int count = 0;
            
            for (int i = 0; i < currentLine.password.length(); i++){
                if(currentLine.letter[0] == currentLine.password[i]){
                    count++;
                }
            }
            if(count >= currentLine.min && count <= currentLine.max){
                numOfValid++;
            }
        }

    }
    else {
        cout << "Cannot open file." << endl;
        return 0;
    }

    cout << "Number of Valid Passwords: " << numOfValid << endl;
}