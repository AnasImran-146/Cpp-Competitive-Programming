#include<iostream>
using namespace std;

#define ll long long

int main(){
    int t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        ll sum = 0;

        while(n>0){
            sum += n;
            n /= 2;
        }
        cout<<sum<<endl;
    }
    
    return 0;
}