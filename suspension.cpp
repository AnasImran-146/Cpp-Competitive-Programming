#include<iostream>
using namespace std;

#define nl cout<<endl;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n, y, r;
        cin>>n>>y>>r;

        if(r==0 && y==0){
            cout<<0;nl
        }else{
            int sus = n-(r+y/2);
            if(sus<0){
                cout<<n;nl
            }else{
                cout<<n-sus;nl
            }
        }
        
    }
    return 0;
}
 