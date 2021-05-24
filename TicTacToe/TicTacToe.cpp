#include <iostream>

using namespace std;

bool VisualisePlayerOne(int* playerOne, int i){
    return playerOne[i] > 0;
}

bool VisualisePlayerTwo(int* playerTwo, int i){
    return playerTwo[i] > 0;
}

void Visualise(int* playerOne, int* playerTwo){
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

void ReadPlayerOneInput(int* playerOne, int* playerTwo){
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

void ReadPlayerTwoInput(int* playerOne, int* playerTwo){
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

bool UpperRow(int* player){
    return player[0] > 0 && player[1] > 0 && player[2] > 0;
}

bool MiddleRow(int* player){
    return player[3] > 0 && player[4] > 0 && player[5] > 0;
}

bool LowerRow(int* player){
    return player[6] > 0 && player[7] > 0 && player[8] > 0;
}

bool LeftRow(int* player){
    return player[0] > 0 && player[3] > 0 && player[6] > 0;
}

bool RightRow(int* player){
    return player[1] > 0 && player[4] > 0 && player[7] > 0;
}

bool VerticalMiddle(int* player){
    return player[2] > 0 && player[5] > 0 && player[8] > 0;
}

bool DiagonalOne(int* player){
    return player[0] > 0 && player[4] > 0 && player[8] > 0;
}

bool DiagonalTwo(int* player){
    return player[2] > 0 && player[4] > 0 && player[6] > 0;
}

bool HorizontalRow(int* player){
    return UpperRow(player) || MiddleRow(player) || LowerRow(player);
}

bool VerticalRow(int* player){
    return LeftRow(player) || VerticalMiddle(player) || RightRow(player);
}

bool Diagonal(int* player){
    return DiagonalOne(player) || DiagonalTwo(player);
}

bool ValidateWinCondition(int* player){
    return HorizontalRow(player) || VerticalRow(player) || Diagonal(player);
}

void AI(int* playerOne, int* playerTwo){
    while (true){
        int inputTwo = rand() % 9;
        if (IsAvailableSlot(playerOne, playerTwo, inputTwo)){
            playerTwo[inputTwo] = 2;
            break;
        }
        //cout << "Invalid input, try again" << endl;
    }
}

int main(int argc, char* argv[]){
    int playerOne[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int playerTwo[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    cout << "Enter 1 if you want to play again AI" << endl;
    int Ai;
    cin >> Ai;
    bool playAgainstAI = Ai == 1;
    Visualise(playerOne, playerTwo);
    while (true){

        cout << "Player one, it's your turn" << endl;
        ReadPlayerOneInput(playerOne, playerTwo);
        Visualise(playerOne, playerTwo);
        if (ValidateWinCondition(playerOne)){
            cout << "Player One is victorious!" << endl;
            break;
        }

        cout << "Player two, it's your turn" << endl;
        if (playAgainstAI){
            AI(playerOne, playerTwo);
        }
        else{
            ReadPlayerTwoInput(playerOne, playerTwo);
        }
        Visualise(playerOne, playerTwo);
        if (ValidateWinCondition(playerTwo)){
            cout << "Player Two is victorious!" << endl;
            break;
        }
    }
    return 0;
}
