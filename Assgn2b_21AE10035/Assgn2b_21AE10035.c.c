#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//roll no-21AE10035
//assignment-no-Assgn2a
void length(float x1,float y1,float x2,float y2,float x3,float y3)
{

   float d1=sqrt(pow(x2 - x1, 2.0) +pow(y2 - y1, 2.0) * 1.0);
   float d2=sqrt(pow(x3 - x2, 2.0) +pow(y3 - y2, 2.0) * 1.0);
   float d3=sqrt(pow(x3 - x1, 2.0) +pow(y3 - y1, 2.0) * 1.0);
   if(d1 >= d2 && d1 >= d3)
        printf("Largest number: %f \n" ,d1);

    if(d2 >= d1 && d2 >= d3)
        printf("Largest number: %f \n" ,d2);

    if(d3 >= d1 && d3 >= d2)
        printf("Largest number: %f \n" ,d3);
}



int main()
{
    float x1,x2,x3,y1,y2,y3;
    scanf("%f %f %f %f %f %f",&x1,&y1,&x2,&y2,&x3,&y3);
    double z= (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2;
    if( z==0){
       printf("formed straight line \n");
       length(x1,y1,x2,y2,x3,y3);
  }
    else{
     printf("Formed Triangle \n");
     printf("area is %f square units \n",abs(z));
  }
    return 0;
}

