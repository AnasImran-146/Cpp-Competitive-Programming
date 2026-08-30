#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        if(i%2!=0){
            for(int j=1; j<=m; j++){
                cout<<'#';
            }
        }else if(i%4==0){ //multiple of 4 will have # on left
            cout<<'#';
            for(int j=1; j<=m-1; j++){
                cout<<'.';
            }
        }else{ //other even like 2, 6, 10 will have # on right
            for(int j=1; j<=m-1; j++){
                cout<<'.';
            }
            cout<<'#';
        }
        cout<<endl;
    }

}