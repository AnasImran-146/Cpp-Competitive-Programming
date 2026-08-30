#include<iostream>
using namespace std;

#define ll long long
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    
    while(t--){
        ll s, k, m;
        cin>>s>>k>>m;

        ll start;

        if(s<=k){
            start = s;
        }else{
            if((m/k)%2==0){
                start = s;
            }else{
                start = k;
            }
        }

        cout<<max(0LL, start-(m%k))<<endl;;
    }
}