#include<iostream>
#include<vector>
using namespace std;

void solution(){
    int n;
    cin>>n;

    int power = 1;
    vector<int> ans;

    while(n>0){
        if(n%10>0){
            ans.push_back((n%10)*power);
        }
        n /= 10;
        power *= 10;
    }

    cout<<ans.size()<<endl;
    for(int i : ans) cout<<i<<" ";
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        solution();
    }
    
    return 0;
}