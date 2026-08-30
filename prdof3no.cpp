#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        long long n;
        cin>>n;

        int a = -1;
        for(int i=2; i<sqrt(n); i++){
            if(n%i==0){
                a = i;
                break;
            }
        }
        if(a==-1){
            cout<<"NO"<<endl;
            continue;
        }

        int n1 = n/a;

        int b=-1;
        for(int i=2; i<sqrt(n1); i++){
            if(n1%i==0 && i!=a){
                b= i;
                break;
            }
        }

        if(b==-1){
            cout<<"NO"<<endl;
            continue;
        }

        int c = n/(a*b);

        if(c!=a && a!=b && c>1){
            cout<<"YES"<<endl;
            cout<<a<<" "<<b<<" "<<c<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}