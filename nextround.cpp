#include<iostream>
using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int kth_place = arr[k-1];
    int count = 0;

    for(int i=0; i<n; i++){
        if(arr[i]>0 && arr[i]>=kth_place) count++;
        else break;
    }
    cout<<count<<endl;
}

int main(){
    solve();
    return 0;
}