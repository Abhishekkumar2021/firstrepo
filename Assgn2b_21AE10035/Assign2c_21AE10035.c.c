#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//roll no-21AE10035
//assignment-no-Assgn2a
int main(){
    float x,y;
    scanf("%f",&x);
    if(x<=10&&x>=0){
        y=x;
    }
    else if(x>=30&&x<=50){
        y=0.5*(50-x);
    }
    else if(x>10&&x<30){
        y=20-sqrt(200-pow(x-20,2.0))*1.0;
    }
    else{
        printf("function not defined in this range");
    }
    printf("%f",y);
    return 0;
}
