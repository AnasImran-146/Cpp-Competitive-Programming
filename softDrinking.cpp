#include<iostream>
#include<algorithm>
using namespace std;

void solve(){
    int n, k, l, c, d, p, nl, np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;

    int totalLiter = k*l;
    int totalLimesSlices = c*d;

    int drinkToast = totalLiter/nl;
    int limeToast = totalLimesSlices;
    int saltToast = p/np;

    int total = min({drinkToast, limeToast, saltToast});
    cout<<total/n<<endl;
}

int main(){
    solve();
    return 0;
}