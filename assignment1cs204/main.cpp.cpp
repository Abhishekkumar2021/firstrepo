#include <iostream>

using namespace std;

void reverseElements(int*stackADT,int p)
{
    for(int countn=0;countn<p/2+1;countn++){
            int s=stackADT[p-countn];
            stackADT[p-countn]=stackADT[countn];
            stackADT[countn]=s;
         }
}

int countvalue=0;
void pushElement(int*ptr,int f)
{
     reverseElements(ptr,countvalue-1);
     ptr[countvalue]=f;
     countvalue++;
}

int getelement(int*ourstack,int l)
{
    int value=ourstack[l];
    return value;
}

void printstack(int*mystack,int v){
             cout<<v<<" elements ";
            for(int g=0;g<v;g++)
            {
                cout<<getelement(mystack,g)<<" ";
            }
            cout<<endl;
      }

void popElement(int*mystack,int &f)
{
    mystack[f]=0;
    reverseElements(mystack,f-1);
    f--;
}


int main()
{
    int t,p;
    cin>>t>>p;
    int newStackADT[p];
    int v=0;
    while(v<19)
       {
           int line,element;
            cin>>line;

            if(line==2){
                cin>>element;
                pushElement(newStackADT,element);
                v++;
            }
            else if(line==7){
                printstack(newStackADT,v);
            }
            else if(line==3)
            {
                popElement(newStackADT,p);
                v--;
            }
            else v++;
       }
    return 0;
}
