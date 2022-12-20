#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std; 

int arrayLocation, input, counter, sequenceSize;
string import; 
vector<int> numberSequence;

void InputNumbers(vector<int> v);
void Iteration(int size, vector<int> v);
void SwapNumbers(int vectorLocation, vector<int> v);
void PrintArray();
void ReadFile(vector <int> v);
//void ChangeDynArrDT(vector<int> v, vector<string> v2);

int main()
{
    cout << "Would you like to 'import' number sequence from file or 'manually' enter the number sequence? ";
    cin >> import; 
    if (import == "import") {
        //import numbers from file
        ReadFile(numberSequence);
        //sort numbers from file
        while (counter < numberSequence.size()) {
            Iteration(numberSequence.size(), numberSequence);
        }
    }
    else if (import == "manually") {
        //to manually input numbers
        InputNumbers(numberSequence);
        cout << "Your sequence is " << numberSequence.size() << " numbers long. \n";
        PrintArray();

        //sort numbers
        while (counter < numberSequence.size()) {
            Iteration(numberSequence.size(), numberSequence);
        }
    }
    else {
        cout << "Invalid selection... \n";
    }
}

void InputNumbers(vector<int> v) {
    //store numbers in vector and store vector size
    cout << "How long will your sequence be? ";
    cin >> sequenceSize;

    int i = 0;

    cout << "Enter your numbers: \n";
    while (i < sequenceSize) {
        cin >> input;
        numberSequence.push_back(input);
        i++;
    }
}

void PrintArray() {
    //prints array
    for (int i = 0; i < numberSequence.size(); i++) {
        cout << numberSequence.at(i) << " ";
    }
    cout << "\n";
}

void Iteration(int arrayLocation, vector<int> v) {
    //checks if each sequence in the array is bigger or smaller than last
    for (int i = 0; i < (numberSequence.size() - 1); i++) {
        if (numberSequence.at(i) > numberSequence.at(i + 1)) {
            //if number > than it's next number numbers get swapped
            SwapNumbers(i, numberSequence);

            counter = 0;
        }
        else if (numberSequence.at(i) <= numberSequence.at(i + 1)) {
            //if number < than it's next number then counter goes up to check if vector is in order
            counter++;
        }
    }
    if (counter >= numberSequence.size()) {
        cout << "YOUR NUMBERS HAVE BEEN SORTED\n\n";
    }
    else {
        PrintArray();
    }
}

void SwapNumbers(int i, vector<int> v){
    //swap numbers that are next to eachother
    int tempSwapOne, tempSwapTwo;
    //store each number
    tempSwapOne = numberSequence[i];
    tempSwapTwo = numberSequence[i+1];

    //assign number to new location
    numberSequence[i] = tempSwapTwo;
    numberSequence[i + 1] = tempSwapOne;
}

void ReadFile(vector<int> v) {
    string filePath;
    fstream file;
    string line;

    //open file
    cout << "Input path to text file: ";
    cin >> filePath;
    file.open(filePath, std::ios::in);

    //inputs each line into string array
    if (file.is_open()) {
        while (getline(file, line)) {
            numberSequence.push_back(stoi(line));
        }
        //print string array
        for (int i = 0; i < numberSequence.size(); i++) {
            cout << numberSequence[i] << " ";
        }
    }
    else {
        cout << "Invalid path to file... ";
        return;
    }

    cout << "\n";
}
