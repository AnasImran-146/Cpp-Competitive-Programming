#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int cards[n];

    for(int i=0; i<n; i++){
        cin>>cards[i];
    }

    int start = 0;
    int end = n-1;

    int seraja = 0;
    int dima = 0;

    while(start<=end){//1 2 3 4 
        seraja += max(cards[start], cards[end]);
        if(cards[start]<cards[end]){
            end--;
        }else{
            start++;
        }

        if(start>end){
            break;
        }
        
        dima += max(cards[start], cards[end]);
        if(cards[start]<cards[end]){
            end--;
        }else{
            start++;
        }
    }


    cout<<seraja<<" "<<dima<<endl;
    return 0;
}