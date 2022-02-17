#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str;
        cin>>str;
        int l=str.length();
        if(str[l-1]%2==0){
            cout<<"0"<<"\n";
            continue;;
        }
        else if(str[0]%2==0){
            cout<<"1"<<"\n";
            continue;
        }
        else{
            for(int j=0;j<l;j++){
                if(str[j]%2==0){
                    cout<<"2"<<"\n";
                    break;
                }
                if(j==l-1){
                    cout<<"-1"<<"\n";
                }
            }
        }
    }
}