#include <iostream>
using namespace std;

struct Element {
    int value;
    int freq;
};

int countFreq(int* arr, int n, Element* unique) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < k; j++) {
            if (unique[j].value == arr[i]) {
                unique[j].freq++;
                found = true;
                break;
            }
        }
        if (!found) {
            unique[k].value = arr[i];
            unique[k].freq = 1;
            k++;
        }
    }
    return k;
}

void frequencySort(int* arr, int n) {
    Element unique[100];
    int size = countFreq(arr, n, unique);

    // Sort by frequency desc, value asc
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (unique[i].freq < unique[j].freq ||
               (unique[i].freq == unique[j].freq && unique[i].value > unique[j].value)) {
                swap(unique[i], unique[j]);
            }
        }
    }

    // Rebuild array
    int index = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < unique[i].freq; j++) {
            arr[index++] = unique[i].value;
        }
    }
}

int main() {
    int arr[] = {5, 5, 4, 6, 4, 5};
    int n = 6;
    frequencySort(arr, n);
    cout << "Sorted by frequency: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
