#include<iostream>
using namespace std;

#define ll long long

void solution(){
    int n;
    cin>>n;

    ll red[n];
    for(int i=0; i<n; i++){
        cin>>red[i];
    }

    ll blue[n];
    for(int i=0; i<n; i++){
        cin>>blue[i];
    }

    ll kMax = 0;
    ll kMin = 0;

    ll maxRed, maxBlue, minRed, minBlue;

    for(int i=0; i<n; i++){
        maxRed = kMax-red[i];
        maxBlue = blue[i]-kMax;
        minRed = kMin-red[i];
        minBlue = blue[i]-kMin;

        ll max1 = max(maxRed, maxBlue);
        ll max2 = max(minRed, minBlue);
        kMax = max(max1, max2);

        ll min1 = min(maxRed, maxBlue);
        ll min2 = min(minRed, minBlue);
        kMin = min(min1, min2);
    }

    cout<<kMax<<endl;   
}

int main(){
    int t;
    cin>>t;

    while(t--){
        solution();
    }

    return 0;
}