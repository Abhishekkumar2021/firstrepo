#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int a;
        cin>>a;
        int z=a%10;
        if(z%2==0){
            cout<<"0";
            break;
        }
        int g,j=0;
        for(int j;j<11;j++){
            g=a/pow(10,j);
            if(g==0)
            break;
        }
        int n=j,b;
        int s[n];
        for(int k=1;k<=n;k++){
            b=a/pow(10,n-k);
            s[k]=b%10;
        }
        if(s[n-1]%2==0){
            cout<<"0";
        }
        else if(s[0]%2==0){
            cout<<"1";
        }
        else{
            int k=0;
            for(k=0;k<n;k++){
                if(s[k]%2==0){
                    cout<<"2";
                    break;
                }
                if(k==n){
                    cout<<"-1";
                }
            }

        }
    }

}