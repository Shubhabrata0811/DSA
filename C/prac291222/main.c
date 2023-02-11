#include<stdio.h>
#include<math.h>

int main(){
    for(int x = 1; x <= 100; x++){
        for(int y = 1; y <= 100; y++){
            if(x != y && pow(x, y) == pow(y, x)){
                printf("x = %d, y = %d\n", x, y);
            }
        }
    }
    return 0;
}
