#include<iostream>
#include<vector>
using namespace std;

typedef int i;
typedef double d;
typedef vector<int> v;

#define pb push_back
#define pp pop_back

#define rep(i, a, b) for(int i=a; i<b; i++)

int main(){
    // v vec;
    // vec.pb(10);
    // vec.pb(20);
    // vec.pb(30);

    // rep(i, 0, 3){
    //     cout<<vec[i]<<" ";
    // }

    // cout<<endl;
    // vec.pp();
    // vec.pp();

    // rep(i, 1, 3){
    //     cout<<vec[i]<<" ";
    // }

    // cout<<endl;

    pair<int, int> arr[3];
    
    arr->first = 1;
    arr->second = 2;
    (arr+1)->first = 2;
    (arr+1)->second = 3;
    (arr+2)->first = 3;
    (arr+2)->second = 4;

    for(int i=0; i<3; i++){
        cout<<(arr+i)->first<<" : "<<(arr+i)->second<<endl;
    }

    return 0;
}