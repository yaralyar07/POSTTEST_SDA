#include <iostream>

using namespace std;

void tukarNilai(int* a, int* b) {
    int temp = *a; 
    
    *a = *b;       
    
    *b = temp;     
}

int main() {
    int angka1, angka2;

    cout << "=== Program Tukar Nilai ===" << endl;
    
    cout << "Masukkan angka pertama : ";
    cin >> angka1;
    cout << "Masukkan angka kedua   : ";
    cin >> angka2;

    cout << "\n[ SEBELUM DITUKAR ]" << endl;
    cout << "Angka pertama = " << angka1 << endl;
    cout << "Angka kedua   = " << angka2 << endl;

    tukarNilai(&angka1, &angka2);

    cout << "\n[ SESUDAH DITUKAR ]" << endl;
    cout << "Angka pertama = " << angka1 << endl;
    cout << "Angka kedua   = " << angka2 << endl;

    return 0;
}