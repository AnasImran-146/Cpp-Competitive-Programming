#include<iostream>
using namespace std;

void subarrays(int arr[], int n){
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            for(int k=i; k<=j; k++){
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        }
    }
}
int main(){
    int arr[3] = {1, 2, 3};
    subarrays(arr, 3);
    return 0;
}