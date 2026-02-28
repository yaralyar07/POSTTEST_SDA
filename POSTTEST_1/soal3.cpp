#include <iostream>

using namespace std;

void reverseArray(int* arr, int n) {
    int* start = arr;           
    int* end = arr + n - 1;     

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++; 
        end--;   
    }
}

int main() {
    int prima[7] = {2, 3, 5, 7, 11, 13, 17};
    
    cout << "=== ARRAY SEBELUM DIBALIK ===" << endl;
    int* p = prima; 
    
    while (p < prima + 7) {
        cout << "Nilai: " << *p << "\t| Alamat: " << p << endl;
        p++; 
    }

    reverseArray(prima, 7);

    cout << "\n=== ARRAY SESUDAH DIBALIK ===" << endl;
    p = prima;
    
    while (p < prima + 7) {
        cout << "Nilai: " << *p << "\t| Alamat: " << p << endl;
        p++; 
    }

    return 0;
}