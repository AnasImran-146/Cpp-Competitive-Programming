#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int a, b;
    cin>>a>>b;

    double x = log((double)b/a) / log((double)3/2);
    int year = floor(x)+1;

    cout<<year<<endl;
}

