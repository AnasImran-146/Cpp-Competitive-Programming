#include<bits/stdc++.h>
using namespace std;

bool sum(int n, int e1, int e2,int x1, int x2, int w1[], int w2[]){
    int sum1=e1+x1, sum2=e2+x2;
    for(int i=0; i<n; i++){
        sum1 += w1[i];
        sum2 += w2[i];
    }

    if(sum1<sum2){
        return 1;
    }else if(sum2<sum1){
        return 0;
    }else{
        if(e1<e2) return 1;
        else return 0;
    }

}

void solve(){
    int n;
    cin>>n;

    int e1, e2;
    cin>>e1>>e2;

    int w1[n];
    for(int i=0; i<n; i++){
        cin>>w1[i];
    }

    int w2[n];
    for(int i=0; i<n; i++){
        cin>>w2[i];
    }

    int s1[n];
    for(int i=0; i<n; i++){
        cin>>s1[i];
    }

    int s2[n];
    for(int i=0; i<n; i++){
        cin>>s2[i];
    }

    int x1, x2;
    cin>>x1>>x2;

    int total = 0;
    int* curr = NULL;
    if(sum(n, e1, e2, x1, x2, w1, w2)){
        total += e1;
        curr = w1;
    }else{
        total += e2;
        curr = w2;
    }

    int j = 0;
    for(int i=0; i<n; i++){
        if(i==0){
            total += *(curr+i);
            continue;
        }
        if(w1[i]<w2[i]){
            if(curr == w1){
                total += w1[i];
                
            }else{
                if(s1[j]+w2[i] < w1[i]){
                    curr = w2;
                    total += s1[j]+w2[i];
                    j++;
                    
                }else{
                    total += w1[i];
                    continue;
                }
            }
            if(curr == w2){
                total += w2[i];
                
            }else{
                if(s2[j]+w1[i] < w2[i]){
                    curr = w1;
                    total += s2[j]+w1[i];
                    j++;
                    
                }else{
                    total += w2[i];
                    continue;
                }
            }
        }
        
        if(w2[i]<w1[i]){
            if(curr == w2){
                total += w2[i];
                
            }else{
                if(s2[j]+w1[i] < w2[i]){
                    curr = w1;
                    total += s2[j]+w1[i];
                    j++;
                    
                }else{
                    total += w2[i];
                    continue;
                }
            }
            if(curr == w1){
                total += w1[i];
                
            }else{
                if(s1[j]+w2[i] < w1[i]){
                    curr = w2;
                    total += s1[j]+w2[i];
                    j++;
                    
                }else{
                    total += w1[i];
                    continue;
                }
            }
        }

    }
    if(curr == w1){
        total += x1;
    }else total += x2;

    cout<<total<<endl;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}