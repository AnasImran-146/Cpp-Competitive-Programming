#include<iostream>
#include<vector>
using namespace std;

bool isJolly(vector<int>& arr, int n){
    vector<int> diff(n, false);

    for(int i=0; i<n-1; i++){
        int d = abs(arr[i]-arr[i+1]);
        if(d==0 || d>n-1 || diff[d]==true){
            return false;
        }
        diff[d] = true;
    }
    return true;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        if(isJolly(arr, n)){
            cout<<"Jolly"<<endl;
        }else{
            cout<<"Not jolly"<<endl;
        }
    }
    return 0;
}