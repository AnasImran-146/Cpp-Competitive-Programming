#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];

        for(int i=0;i <n; i++){
            cin>>arr[i];
        }

        int tr = 0, fl = 1;
        while(tr<fl && fl<n){
            if(arr[tr]==1 && arr[fl]==1){
                tr++;
                fl++;
            }else if(arr[tr]==1 && arr[fl]==0){
                cout<<"OUTPUT "<<tr<<endl;
                break;
            }else{
                tr++;
                fl++;
            }
        }
    }
    

    return 0;
}