#include<stdio.h>
#include<string.h>

int main(){
    int n;
    //max lenght of string is 50!!
    int maxLengthStr = 50;
    printf("Enter number of messages : ");
    //input number!
    scanf("%d%*c", &n);

    char arr[n][maxLengthStr];
    char word[n][maxLengthStr];
    int countArr[n];

    //input string from keyboard
    for(int i = 0; i < n; i++){
        fgets(arr[i], maxLengthStr, stdin);
    }

    //keep uppercase character!
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < maxLengthStr - 1 && arr[i][j] != '\0'; j++){
            if(arr[i][j] >= 'A' && arr[i][j] <= 'Z'){
                word[i][count] = arr[i][j];
                count++;
            }
        }
        //add null character!
        word[i][count] = '\0';
        for(int j = 0; j < count; j++){
            countArr[i] = count;
        }

    }

    // for(int i = 0; i < n; i++){
    //     printf("%d \n",countArr[i]);
    // }

    //string check
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < countArr[i]; j++){
    //         // check buffer by strlen
    //         printf("%d", strlen(word[i]));

    //         //print string
    //         // printf("%c", word[i][j]);
    //     }
    //     printf("\n");
    // }

    // printf("%d\n", strlen(word[i]));

    char temp[maxLengthStr];
    //Descending order!
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(strlen(word[i]) < strlen(word[j])){
                //Alpabatical Order
                strcpy(temp,word[i]);
                strcpy(word[i],word[j]);
                strcpy(word[j],temp);
             }
        }
    }

    //Alpabatical Order!
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(strlen(word[i]) == strlen(word[j])){
                // printf("test : %s\n", word[i]);
                if(word[i][0] > word[j][0]){
                //Alpabatical Order
                strcpy(temp,word[i]);
                strcpy(word[i],word[j]);
                strcpy(word[j],temp);
             }
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("%s\n", word[i]);
    }

    return 0;
}