#include <iostream>
using namespace std;

// ANALISIS KOMPLEKSITAS WAKTU:

// Hitungan Tmin(n) (Best Case):
//  Kondisi: Elemen array sudah ascending.
//  Tmin(n) = (c2 + c3)n + (c1 - c3 + c5)
//  Kompleksitas Best Case: O(n)

// Hitungan Tmax(n) (Worst Case):
//  Kondisi: Elemen array descending.
//  Tmax(n) = (c2 + c3 + c4)n + (c1 - c3 - c4 + c5)
//  Kompleksitas Worst Case: O(n)


void FindMin(int A[], int n) {
    int min = A[0];
    int index_min = 0;
    
    for (int i = 1; i < n; i++) {
        if (A[i] < min) {
            min = A[i];
            index_min = i;
        }
    }
    
    cout << "Nilai minimum        : " << min << endl;
    cout << "Indeks nilai minimum : " << index_min << endl;
}

int main() {
    int arr[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int n = 8;
    
    cout << "Isi Array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n----------------------------" << endl;
    
    FindMin(arr, n);
    
    return 0;
}