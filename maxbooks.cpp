#include<iostream>
using namespace std;

int main(){
    long long n, t;
    cin>>n>>t;

    int books[n];
    for(int i=0; i<n; i++){
        cin>>books[i];
    }

    int start = 0;
    int end = n-1;
    int max = 0;

    while(start<=end && t>0){
        if(books[start]<books[end]){
            t -= books[start];
            start++;
        }else if(books[start]>books[end]){
            t -= books[end];
            end--;
        }else{
            t -= books[start];
            start++;
        }
        if(t<=0) break;
        max++;
    }

    cout<<max<<endl;

    return 0;
}