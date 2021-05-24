#include <iostream>

using namespace std;

bool VisualisePlayerOne(int playerOne[], int i){
    return playerOne[i] > 0;
}

bool VisualisePlayerTwo(int playerTwo[], int i){
    return playerTwo[i] > 0;
}

void Visualise(int playerOne[], int playerTwo[]){
    for (int i = 0; i < 9; i++){
        if (VisualisePlayerOne(playerOne, i)){
            cout << " " << "x" << " ";
        }

        else if (VisualisePlayerTwo(playerTwo, i)){
            cout << " " << "o" << " ";
        }
        else{
            cout << " " << i << " ";
        }

        if (i == 2 || i == 5 || i == 8){
            cout << "" << endl;
            continue;
        }
        cout << "|";
    }
}

bool IsValidInput(int input){
    return input >= 0 && input < 9;
}

bool IsAvailableSlot(int playerOne[], int playerTwo[], int playerInput){
    return playerOne[playerInput] == 0 && playerTwo[playerInput] == 0 && IsValidInput(playerInput);
}

void ReadPlayerOneInput(int playerOne[], int playerTwo[]){
    while (true){
        int inputOne;
        cin >> inputOne;
        if (IsAvailableSlot(playerOne, playerTwo, inputOne)){
            playerOne[inputOne] = 1;
            break;
        }
        cout << "Invalid input, try again" << endl;
    }

}

void ReadPlayerTwoInput(int playerOne[], int playerTwo[]){
    while (true){
        int inputTwo;;
        cin >> inputTwo;
        if (IsAvailableSlot(playerOne, playerTwo, inputTwo)){
            playerTwo[inputTwo] = 2;
            break;
        }
        cout << "Invalid input, try again" << endl;
    }

}

int main(int argc, char* argv[]){
    int playerOne[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int playerTwo[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    while (true){
        
        cout << "Player one, it's your turn" << endl;
        ReadPlayerOneInput(playerOne, playerTwo);
        Visualise(playerOne, playerTwo);
        
        cout << "Player two, it's your turn" << endl;
        ReadPlayerTwoInput(playerOne, playerTwo);
        Visualise(playerOne, playerTwo);
    }
    return 0;
}
