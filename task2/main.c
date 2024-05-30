#include <stdio.h>
#include "my_mat.h"

int main(){

    char user_input;
    scanf("%c", &user_input);
    while(user_input != 'D'){
        if(user_input == 'A'){
            input();
        }
        else if(user_input == 'B'){
            hasPath();
        }
        else if(user_input == 'C'){
            print_shortest();
        }
        scanf("%c", &user_input);
    }
    return 0;
}
