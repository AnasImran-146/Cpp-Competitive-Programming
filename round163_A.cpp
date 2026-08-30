#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    string s;
    cin>>s;

    int removedStones = 0;
    for(int i=1; i<n; i++){
        if(s[i-1]==s[i]) removedStones++;
    }

    cout<<removedStones<<endl;
}