#include<iostream>
using namespace std;

int main(){
    long long n;
    cin>>n;

    int luckyDigitsCount = 0;
    
    while(n>0){
        if(n%10==7 || n%10==4) luckyDigitsCount++;
        n /= 10;
    }

    if(luckyDigitsCount==4 || luckyDigitsCount==7){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    return 0;
}