#include<iostream>
#include<string>
using namespace std;

void solution(){
    int n, k;
    cin>>n>>k;

    string s;
    cin>>s;

    int maxClassCount = 0;
    int kCount = 0;


    for(int i=0; i<n; i++){
        if(s[i]=='1'){
            maxClassCount++;
            kCount = k;
        }else if(s[i]=='0' && kCount>0){
            maxClassCount++;
            kCount--;
        }
    }

    cout<<n-maxClassCount<<endl;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        solution();
    }
    return 0;
}