#include <stdio.h>
#include <stdlib.h>

struct ArrayADT{
int* element;
int capacity;
};
void createNewArray(struct ArrayADT* arrayname,int arraysize)
{
    arrayname->capacity=arraysize;
    arrayname->element=(int*)malloc(arraysize*sizeof(int));
}
void insertelement(struct ArrayADT* arrayname,int index,int value)
{
    arrayname->element[index]=value;
}
int valueAt(struct ArrayADT* arrayname,int index)
{
    return arrayname->element[index];
}

int main()
{
    struct ArrayADT a={NULL,0};
    int i;
    createNewArray(&a,5);
    for(i=0;i<5;i++)
    {
        insertelement(&a,i,i*4);
        printf("the value of array at index %d is %d \n",i,valueAt(&a,i));
    }
    return 0;
}
