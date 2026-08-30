#include<iostream>
using namespace std;

#define ll long long

int main(){
    int t;
    cin>>t;

    while(t--){
        ll x;
        cin>>x;

        int count = 0;

        for(ll y=x; y<=x+100; y++){
            ll num = y;
            int sum = 0;

            while(num>0){
                sum += num % 10;
                num /= 10;
            }

            if(y-sum==x){
                count++;
            }
        }

        cout<<count<<endl;
    }

    return 0;
}
