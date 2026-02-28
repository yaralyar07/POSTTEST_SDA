#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    Mahasiswa mhs[5];

    cout << "=== Program Data Mahasiswa ===" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "\nMasukkan data Mahasiswa ke-" << (i + 1) << endl;
        
        cout << "Nama : ";
        getline(cin >> ws, mhs[i].nama); 
        
        cout << "NIM  : ";
        cin >> mhs[i].nim;
        
        cout << "IPK  : ";
        cin >> mhs[i].ipk;
    }

    int indeks_tertinggi = 0; 
    
    for (int i = 1; i < 5; i++) {
        if (mhs[i].ipk > mhs[indeks_tertinggi].ipk) {
            indeks_tertinggi = i;
        }
    }

    cout << "\n=============================================" << endl;
    cout << "       Mahasiswa dengan IPK Tertinggi        " << endl;
    cout << "=============================================" << endl;
    cout << "Nama : " << mhs[indeks_tertinggi].nama << endl;
    cout << "NIM  : " << mhs[indeks_tertinggi].nim << endl;
    cout << "IPK  : " << mhs[indeks_tertinggi].ipk << endl;

    return 0;
}