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

void freq(int* arr, int n){
    bool visited[n] = {false};

    for(int i=0; i<n; i++){
        if(visited[i] == true){
            continue;
        }

        int count = 1;
        for(int j=i+1; j<n; j++){
            if(arr[i] == arr[j]){
                visited[i] = true;
                count++;
            }
        }
        cout<<"["<<arr[i]<<", "<<count<<"]"<<endl; 
    }
}

int main(){
    int n = 5;
    int arr[n] = {1, 1, 1, 2, 2};
    sort(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    freq(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}