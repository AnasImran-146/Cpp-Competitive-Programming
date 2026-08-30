#include <iostream>
#include <map>
#include <queue>

using namespace std;
#define ll long long

void solve(){
    ll n, k;
    cin>>n>>k;

    if(n==k) {
        cout<<0<<endl;
        return;
    }
    
    if(k>n){
        cout<<-1<<endl;
        return;
    }

    queue<pair<ll, int>> q;
    q.push({n, 0});

    map<ll, bool> v;
    v[n] = true;

    while (!q.empty()) {
        ll currVal = q.front().first;
        int currTime = q.front().second;
        q.pop();

        if(currVal<k) {
            continue;
        }

        ll p1 = currVal/2;
        ll p2 = (currVal+1)/2;
            
        if(p1==k||p2==k){
            cout<<currTime+1<<endl;
            return;
        }
        if(!v[p1] && p1>0){
            v[p1] = true;
            q.push({p1, currTime+1});
        }
        if(!v[p2] && p2>0){
            v[p2] = true;
            q.push({p2, currTime+1});
        }
    }
    cout<<-1<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}