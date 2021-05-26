#include <iostream>

int main(int argc, char* argv[]){
    int i = 0, j = 0;
    if (++i || ++j){
        std::cout << "yes!" << std::endl;
    }

    
    return 0;
}
