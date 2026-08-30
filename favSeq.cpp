#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int b[n];
        for(int i=0; i<n; i++){
            cin>>b[i];
        }
        int ans[n];
        int start = 0, end = n-1;
        for(int i=0; i<n; i++){
            if(i%2==0){
                ans[i] = b[start];
                start++;
            }else{
                ans[i] = b[end];
                end--;
            }
        }
        for(int i=0; i<n; i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}