#include<iostream>
using namespace std;

int main(){
    int stops;
    cin>>stops;

    int passengerOnBoard = 0;
    int maximumCapacity = 0;

    for(int i=0; i<stops; i++){
        int passengerExiting, passengerEnterting;
        cin>>passengerExiting>>passengerEnterting;
        
        passengerOnBoard -= passengerExiting;
        passengerOnBoard += passengerEnterting;

        maximumCapacity = max(maximumCapacity, passengerOnBoard);
    }

    cout<<maximumCapacity<<endl;
    
    return 0;
}