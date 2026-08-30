#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, q;
    cin>>n>>q;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    vector<long long> prefix(n+1);
    for(int i=1; i<n+1; i++){
        prefix[i] = prefix[i-1] + arr[i-1];
    }

    for(int i=1; i<=q; i++){
        int a, b;
        cin>>a>>b;

        cout<<prefix[b]-prefix[a-1]<<endl;
    }

    return 0;
}