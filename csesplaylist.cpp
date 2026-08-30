#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<long> id(n);
    for(int i=0; i<n; i++){
        cin>>id[i];
    } 
    map<long, long> mp;
    int i=0, j=0;
    int ans = 1;

    mp[id[0]]++;

    while(j<n-1){
        j++;
        while(mp[id[j]]!=0){
            mp[id[i]]--;
            i++;
        }
        mp[id[j]]++;

        ans = max(ans, j-i+1);
    }
    cout<<ans<<endl;

    return 0;
}