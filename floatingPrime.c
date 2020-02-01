#include<stdio.h>

//function prototype!
int getPrime(int n);

int main(){
    float n;
    int temp;
    int state = 0;
    while(state != 1){
        //input float number!
        scanf("%f", &n);
        int mul = 10;
        //0.0 = 0 is the same! or ctrl + c
        if(n == 0.0){
            state = 1;
        }
        else{
            int i = 1;
            //can remove state != 1 and n != 0.0
            while(state != 1 && i != 4 && n != 0.0){
                temp = n*mul;
                mul*=10;
                if(getPrime(temp)){
                    printf("TRUE\n");
                    break;
                }
                else if(i == 3){
                    printf("FALSE\n");
                    break;
                }
                i++;
            }
        }
    }
    // printf("Floating number is %f, %d", n, temp);
    return 0;
}

int getPrime(int n){
    int i = 1;
    int status = 0;
    int state = 0;
    while(i <= n){
        if(n % i == 0){
            state++;
        }
        i++;
    }
    if(state == 2){
        status = 1;
    }
    return status;
}