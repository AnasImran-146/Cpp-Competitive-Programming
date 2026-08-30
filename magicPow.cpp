#include<iostream>
using namespace std;

bool canMake(int mid, int n, int k, int a[], int b[]){
    int pr = 0; //powder required to make the max number of cookies
    for(int i=0; i<n; i++){
        if(mid*a[i]>b[i]){
            pr += (mid*a[i]-b[i]);
        }
        if(pr>k) return false;
    }
    return pr<=k;
}

int main(){
    int n, k;
    cin>>n>>k;

    int a[n];
    int b[n];

    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }

    int start = 0;
    int end = 2100; //max(b[i]/min(a[i])+k

    int maxcookies = 0;

    while(start<=end){
        int mid = start + (-start+end)/2;

        if(canMake(mid, n, k, a, b)){
            maxcookies = mid;
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    cout<<maxcookies<<endl;
    return 0;
}