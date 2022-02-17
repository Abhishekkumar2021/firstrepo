#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int m,n;
        cin>>m>>n;
        if(m<=n/3){
            cout<<n;
        }
        else if(n<=m/3){
            cout<<n;
        }
        else{
            long long h=(m+n)/4;
            cout<<h;
        }
    }
}