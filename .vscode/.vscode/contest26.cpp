#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,l,r,k,num=0;
        cin>>n>>l>>r>>k;
        int arr[n];
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        sort(arr,arr+n);
        for(int k=0;k<n;k++){
            if(arr[k]>=l&&arr[k]<=r){
                num=arr[k];
                break;
            }
        }
        if(num==0){
           cout<<"0"<<endl;}
        else{
            num=k/num;
            cout<<num<<endl;
        }
    }
}