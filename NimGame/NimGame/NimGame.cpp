#include <iostream>

using namespace std;

int AITurn(int matchesLeft){
    switch (matchesLeft){
    case 1:
        return 0;
    case 2:
        return 1;
    case 3:
        return 2;
    default:
        return rand() % 3 + 1;
    }
}

bool PlayerInputIsValid(int input){
    return input > 0 && input < 4;
}

int PlayerInput(){
    while (true){
        int playerInput;
        cin >> playerInput;
        if (PlayerInputIsValid(playerInput))
            return playerInput;
    }
}

void DisplayMatches(int matchesLeft){
    for (int i = 0; i < matchesLeft; i++){
        cout << "|";
    }
    cout << "" << endl;
}

int main(int argc, char* argv[]){
    int matches = 24;
    while (matches > 0){
        DisplayMatches(matches);
        matches -= PlayerInput();
        if (matches <= 0){
            cout << "You lose!" << endl;
            break;
        }

        matches -= AITurn(matches);
        if (matches <= 0){
            cout << "You win!" << endl;
            break;
        }
    }

    return 0;
}
