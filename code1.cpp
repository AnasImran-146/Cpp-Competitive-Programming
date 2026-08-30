#include<iostream>
using namespace std;

void sort(int* arr, int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }
    return;
}

int main(){
    int n = 5;
    int arr[n] = {1, 1, 1, 2, 2};
    sort(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for(int i=0 ;i<n; i++){
        for(int j=i+1; j<n; ){
            if(arr[i]==arr[j]){
                for(int k=j; k<n-1; k++){
                    arr[k]=arr[k+1];
                }
                n--;
            }else{
                j++;
            }
        }
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}