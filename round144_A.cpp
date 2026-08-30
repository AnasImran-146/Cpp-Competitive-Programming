#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;

    int max = INT_MIN, min = INT_MAX, maxIndex = 0, minIndex = n-1;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;

        if(x>max){
            max = x;
            maxIndex = i;
        }

        if(x<=min){
            min = x;
            minIndex = i;
        }   
    }

    int ans = maxIndex + n-1 - minIndex;
    
    if(maxIndex>minIndex){
        cout<<ans-1<<endl;
    }else{
        cout<<ans<<endl;
    }

    return 0;
}