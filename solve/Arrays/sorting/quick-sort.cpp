#include<bits/stdc++.h>
using namespace std;

// #define int long long

int partition(vector<int>& v, int low, int high) {
    int pivot = v[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(v[j] <= pivot) {
            i++;
            swap(v[i], v[j]);
        }
    }

    swap(v[i+1], v[high]);
    return i + 1;
}

void quickSort(vector<int>& v, int low, int high) {
    if(low < high) {
        int pi = partition(v, low, high);

        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}

int main() {
    vector<int> v = {10, 7, 8, 9, 1, 5};
    int n = v.size();

    quickSort(v, 0, n - 1);

    cout << "Sorted array: ";
    for(int x : v) cout << x << " ";
    cout << '\n';

    return 0;
}