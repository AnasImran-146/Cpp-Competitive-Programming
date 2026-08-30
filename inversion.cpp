#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int i=0;
        int maxNum = 0;
        int operations = 0;

        for(int i=0; i<n; i++){
            if(arr[i]<maxNum){
                operations++;
            }else{
                maxNum = arr[i];
            }
        }

        cout<<operations<<endl;
    }

    return 0;
}