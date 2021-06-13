#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

void RemainderBinaryConverter(){
    unsigned int userInput;
    cin >> userInput;
    string result;
    while (userInput > 0){
        int remainder = userInput % 2;
        userInput /=2;
        result = std::to_string(remainder) + result;
    }
    
    cout << result << endl;
}

void BinaryOperationsBinaryConverter(){
    signed int userInput;
    list<int> num;
    cin >> userInput;
    
    while (userInput){
        num.push_front(userInput & 1);
        userInput >>= 1;
    }

    for (int x : num){
        cout << x;
    }
}

int main(int argc, char* argv[]){
    BinaryOperationsBinaryConverter();
    return 0;
}
