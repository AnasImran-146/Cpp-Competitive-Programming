#include<iostream>
using namespace std;

void solution(){
    int n;
    cin>>n;

    if(n%4==0){
        cout<<"YES"<<endl;

        for(int i=2; i<=n; i+=2){
            cout<<i<<" ";
        }

        for(int i=1; i<n-1; i+=2){
            cout<<i<<" ";
        }

        cout<<3*n/2-1<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

int main(){
    int t;
    cin>>t;

    while(t--){
        solution();
    }

    return 0;
}