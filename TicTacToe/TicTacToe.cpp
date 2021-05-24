#include <iostream>

using namespace std;

void Visualise(){
    for (int i = 0; i < 9; i++){
        cout << " " << i << " ";
        if (i == 2 || i == 5 || i == 8){
            cout << "" << endl;
            continue;
        }
        cout << "|";
    }
}

int main(int argc, char* argv[]){

    Visualise();
    return 0;
}
