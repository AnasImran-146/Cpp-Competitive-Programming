#include<iostream>
using namespace std;

int main(){
    int n; 
    cin>>n;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;

        if(x==1){
            cout<<"Hard"<<endl;
            return 0;
        }
    }

    cout<<"Easy"<<endl;
    return 0;

    return 0;
}