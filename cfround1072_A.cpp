#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        if(n<=3) cout<<n<<endl;
        else if(n%2==0) cout<<0<<endl;
        else cout<<1<<endl;
    }
}