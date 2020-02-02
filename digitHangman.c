#include<stdio.h>

int main(){
    int n = 12;
    int maxAns = 5;
    //โจทย์
    int prop[n]; // 12 
    int guess[maxAns]; // 5
    int state = 0;
    char res[5][12] = { 
                        {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
                        {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
                        {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
                        {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
                        {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_'}
                      };    
    int answer[5][12] = {{0}};
    int wrongAns[maxAns];
    int point = 0;

    printf("Enter Case Number: \n");
    //input proposition
    int i = 0;
    while(i < n){
        scanf(" %d", &prop[i]);
        if(prop[i] >= 0 && prop[i] <= 9){
            i++;
        }
        else {
            printf("Please enter number between 0 - 9! \n");
            state = 1;
            break;
        }
    }

    //input answer
    int j = 0;
    while(j < maxAns && state != 1){
        scanf(" %d", &guess[j]);
        if(guess[j] >= 0 && guess[j] <= 9){
            j++;
        }
        else {
            printf("Please enter number between 0 - 9! \n");
            state = 1;
            break;
        }
    }

    //check
    // int count = 0;
    int checkGuess = 0;
    int GuessCount = 0;
    if(state == 0){
        printf("_ _ _ _ _ _ _ _ _ _ _ _\n");
        for(int i = 0; i < maxAns; i++){
            checkGuess = 0;
            for(int j = 0; j < n; j++){
                if(guess[i] == prop[j]){
                    for(int k = i; k < maxAns; k++){
                        res[k][j] = guess[i];
                        answer[k][j] = guess[i];
                    }
                }
                //check wrong answer
                if(guess[i] != prop[j]){
                    // wrongAns[i] = guess[i];
                    checkGuess++;
                }
                else{
                    checkGuess--;
                }
                //printf result!
                if(res[i][j] != '_'){
                    printf("%d ", answer[i][j]);
                }
                else{
                    printf("%c ", res[i][j]);
                }
            }
            if(checkGuess == 12){
                wrongAns[GuessCount] = guess[i];
                GuessCount++;
                for(int k = 0; k < GuessCount; k++){
                    printf("%d ", wrongAns[k]);
                }
            }
            else if(wrongAns[i] >= 0 && wrongAns[i] <= 9){
                for(int k = 0; k < GuessCount; k++){
                    printf("%d ", wrongAns[k]);
                }
            }
            printf("\n");
        }
    }

    //check points
    for(int i = maxAns-1; i < maxAns; i++){
        for(int j = 0; j < n; j++){
            if(res[i][j] != '_'){
                point++;
            }
        }
    }
    printf("%d", point);
    // print 
    // if(state == 0){
    //     printf("_ _ _ _ _ _ _ _ _ _ _ _\n");
    //     for(int i = 0; i < maxAns; i++){
    //         for(int j = 0; j < n; j++){
    //             if(res[i][j] != '_'){
    //                 printf("%d ", answer[i][j]);
    //             }
    //             else{
    //                 printf("%c ", res[i][j]);
    //             }
                
    //         }
    //         printf("\n");
    //     }
    // }

    

    // for(int i = 0; i < count;i++){
    //     printf("%d " ,wrongAns[i]);
    // }
    return 0;
}