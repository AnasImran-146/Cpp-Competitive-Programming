#include<iostream>
using namespace std;

int main(){
    int x;
    cin>>x;

    int step = x/5;
    if(x%5!=0){
        step++;
    }
    cout<<step<<endl;
    
    return 0;
}