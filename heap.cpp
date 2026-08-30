#include<iostream>
using namespace std;

#define nl cout<<endl;

class Heap{
private:
    int* arr;
    int size; 
    int capacity;

public:

    Heap(int cap){
        capacity = cap;
        arr = new int[capacity];
        size = 0;
    }

    void insert(int val){
        int i = size;
        arr[i] = val;
        size++;

        while(i>0){
            int root = (i-1)/2;
            
            if(arr[root]<arr[i]){
                swap(arr[root], arr[i]);
                i = root;
            }else{
                return;
            }
        }
    }

    void heapify(int arr[], int n, int i){
        int parent = i;
        int leftChild = i*2+1;
        int rightChild = i*2+2;

        if(leftChild<n && arr[parent]<arr[leftChild]){
            parent = leftChild;
        }

        if(rightChild<n && arr[parent]<arr[rightChild]){
            parent = rightChild;
        }

        if(parent != i){
            swap(arr[parent], arr[i]);
            heapify(arr, n, parent);
        }
    }

    void deleteVal(){
        arr[0] = arr[size-1];
        size--;

        int i = 0;
        while(i<size){
            int left = i*2+1;
            int right = i*2+2;

            if(left<size && arr[i]<arr[left]){
                swap(arr[i], arr[left]);
                i = left;
            }else if(right<size && arr[i]<arr[right]){
                swap(arr[i], arr[right]);
                i = right;
            }else{
                return;
            }
        }

    }

    void heapSort(int arr[], int& n){
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        int arrSize = n;
        while(arrSize>0){
            swap(arr[0], arr[arrSize-1]);
            arrSize--;
            heapify(arr, arrSize, 0);
        }
    }

    void deleteSpecificElement(int v){
        int i;
        for(i=0; i<size; i++){
            if(arr[i]==v) break;
        }

        if(i==size){
            cout<<"Element Not found."; 
            return;
        }

        arr[i] = arr[size-1];
        size--;

        int parent = (i-1)/2;
        if(i>0 && arr[i]>arr[parent]){
            while(i>0 && arr[i]>arr[parent]){
                swap(arr[i], arr[parent]);
                i = parent;
                parent = (parent-1)/2;
            }
        }else{
            heapify(arr, size, i);
        }

    }

    void print(){
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }         
        cout<<endl;
    }

    ~Heap(){
        delete[] arr;
        arr = NULL;
    }

};

int main(){
    Heap heap(5);
    heap.insert(10);
    heap.insert(20);
    heap.insert(30);
    heap.insert(40);
    heap.insert(50);

    cout<<"Max heap : ";
    heap.print();

    // cout<<"Deletion"<<endl;
    // heap.deleteVal();

    // cout<<"After Deletion : ";
    // heap.print();

    // int arr[5] = {10, 20, 30, 40, 50};
    // cout<<"Heapify : ";
    // for(int i=5/2; i>=0; i--){
    //     heap.heapify(arr, 5, i);
    // }

    // for(int i=0; i<5; i++) cout<<arr[i]<<" "; nl

    // int size = sizeof(arr)/sizeof(arr[0]);
    // heap.heapSort(arr, size);

    // cout<<"Heap Sort : ";
    // for(int i=0; i<4; i++){
    //     cout<<arr[i]<<" ";
    // }nl

    heap.deleteSpecificElement(20);
    cout<<"Deleting an specific element : ";
    heap.print();

    return 0;
}