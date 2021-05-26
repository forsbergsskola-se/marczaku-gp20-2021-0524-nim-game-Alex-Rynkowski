#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
    signed int userInput;
    cin >> userInput;

    string result;
    int remainder;
    while (userInput > 0){
        remainder = userInput % 2;
        userInput /=2;
        result = std::to_string(remainder) + result;
    }

    cout << result << endl;
    return 0;
}
