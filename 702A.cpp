#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int maximumLength = 1;
    int subarrayLength = 1;

    long long previous;
    long long current;
    cin>>previous;

    for(int i=1; i<n; i++){
        cin>>current;

        if(current>previous){
            subarrayLength++;
        }else{
            subarrayLength=1;
        }
        maximumLength = max(maximumLength, subarrayLength);
        previous=current;
    }

    cout<<maximumLength<<endl;

    return 0;
}