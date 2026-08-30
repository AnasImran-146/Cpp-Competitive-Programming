#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin>>s;

    int s1=0, s2=0, s3=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='1') s1++;
        else if(s[i]=='2') s2++;
        else if(s[i]=='3') s3++;
    }
    
    bool first = true;
    string ans = "";
    for(int i=0; i<s1; i++){
        if(!first) ans += '+';
        ans += '1';
        first = false;
    }

    for(int i=0; i<s2;i++){
        if(!first) ans += '+';
        ans += '2';
        first = false;
    }

    for(int i=0; i<s3; i++){
        if(!first) ans += '+';
        ans += '3';
        first = false;
    }

    cout<<ans<<endl;

    return 0;
}