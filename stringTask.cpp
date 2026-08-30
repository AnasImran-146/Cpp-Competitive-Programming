#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin>>s;

    string ans = "";

    for(int i=0; i<s.length(); i++){
        char c = tolower(s[i]);
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||c=='y'){
            continue;
        }
        ans = ans + '.' + c;
    }
    cout<<ans<<endl;

    return 0;
}