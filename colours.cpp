#include <iostream>
#include<vector>
using namespace std;

int minimumSwaps(vector<int>& arr){
    int swaps = 0;
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]!=i+1){
            int targetIndex = -1;
            for(int j=i+1;j<n;j++){
                if(arr[j] == i + 1){
                    targetIndex = j;
                    break;
                }
            }
            swap(arr[i], arr[targetIndex]);
            swaps++;
            
        }
    }
    
    return swaps;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<minimumSwaps(arr)<<endl;

    return 0;
}