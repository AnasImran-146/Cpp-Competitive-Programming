#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s;
    cin>>s;

    vector<bool> numberOfUniqueElement(26, false);
    int count = 0;

    for(int i=0; i<s.length(); i++){
        int indx = s[i] - 'a';

        if(!numberOfUniqueElement[indx]){
            numberOfUniqueElement[indx] = true;
            count++;
        }
    }

    if(count%2==0){
        cout<<"CHAT WITH HER!"<<endl;
    }else{
        cout<<"IGNORE HIM!"<<endl;
    }
}