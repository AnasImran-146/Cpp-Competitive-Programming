#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x1, x2, x3;
    cin>>x1>>x2>>x3;

    cout<<max({x1, x2, x3})-min({x1, x2, x3});
}