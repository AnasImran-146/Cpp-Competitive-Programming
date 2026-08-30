#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int maxScore = 0;
        int index = -1;

        for(int i=0;i<22;i++){
            int r, w;
            cin>>r>>w;

            int score = r+w*20;
            if(score>maxScore){
                maxScore=score;
                index=i;
            }
        }
        cout<<index+1<<endl;
    }

    return 0;
}