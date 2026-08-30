#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int q;
    cin>>q;

    while(q--){
        int n;
        cin>>n;
        char s[n], t[n];
        cin>>s>>t;

        sort(s, s+n);
        sort(t, t+n);

        bool arrange = true;
        for(int i=0; i<n; i++){
            if(s[i]!=t[i]){
                arrange = false;
                break;
            }
        }
        if(arrange){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}