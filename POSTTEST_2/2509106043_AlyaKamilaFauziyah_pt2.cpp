#include <iostream>
#include <string>

using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    int harga;
};

void swap_hewan(Hewan* a, Hewan* b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

void tampil_data(Hewan* arr, int n) {
    cout << "\n=== Daftar Hewan Pawcare Petshop ===\n";
    if (n == 0) {
        cout << "Data masih kosong!\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". ID: " << (arr + i)->id 
             << " | Nama: " << (arr + i)->nama 
             << " | Jenis: " << (arr + i)->jenis 
             << " | Harga: Rp" << (arr + i)->harga << "\n";
    }
}

void tambah_data(Hewan* arr, int* n) {
    cout << "\n=== Tambah Data Hewan ===\n";
    cout << "Masukkan ID Hewan : "; cin >> (arr + *n)->id;
    cout << "Masukkan Nama     : "; cin >> ws; getline(cin, (arr + *n)->nama);
    cout << "Masukkan Jenis    : "; getline(cin, (arr + *n)->jenis);
    cout << "Masukkan Harga    : "; cin >> (arr + *n)->harga;
    (*n)++; 
    cout << "Data berhasil ditambahkan!\n";
}

void linear_search(Hewan* arr, int n, string target) {
    bool found = false;
    cout << "\n=== Proses Linear Search (Berdasarkan Nama) ===\n";
    for (int i = 0; i < n; i++) {
        cout << "-> [Iterasi " << i+1 << "] Mengecek data ke-" << i+1 << " dengan nama: " << (arr + i)->nama << "\n";
        
        if ((arr + i)->nama == target) {
            cout << "\n[!] Data Ditemukan!\n";
            cout << "ID: " << (arr + i)->id << " | Nama: " << (arr + i)->nama << " | Harga: Rp" << (arr + i)->harga << "\n";
            found = true;
            break;
        }
    }
    if (!found) cout << "\n[!] Data dengan nama '" << target << "' tidak ditemukan.\n";
}

void sort_id(Hewan* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((arr + j)->id > (arr + j + 1)->id) {
                swap_hewan((arr + j), (arr + j + 1));
            }
        }
    }
}

int min(int x, int y) {
    return (x <= y) ? x : y;
}

void fibonacci_search(Hewan* arr, int n, int target) {
    if (n == 0) {
        cout << "Data kosong!\n";
        return;
    }
    
    sort_id(arr, n);
    cout << "\n[Info] Data telah diurutkan berdasarkan ID secara otomatis untuk persiapan Fibonacci Search.\n";
    cout << "=== Proses Fibonacci Search (Berdasarkan ID) ===\n";

    int fibMMm2 = 0; 
    int fibMMm1 = 1; 
    int fibM = fibMMm2 + fibMMm1; 

    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;
    bool found = false;

    while (fibM > 1) {
        int i = min(offset + fibMMm2, n - 1);
        cout << "-> [Iterasi] Mengecek indeks ke-" << i << " (ID: " << (arr + i)->id << ")\n";

        if ((arr + i)->id < target) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        } else if ((arr + i)->id > target) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        } else {
            cout << "\n[!] Data Ditemukan!\n";
            cout << "ID: " << (arr + i)->id << " | Nama: " << (arr + i)->nama << " | Harga: Rp" << (arr + i)->harga << "\n";
            found = true;
            return;
        }
    }

    if (fibMMm1 && offset + 1 < n && (arr + offset + 1)->id == target) {
        cout << "-> [Iterasi Akhir] Mengecek indeks ke-" << offset + 1 << " (ID: " << (arr + offset + 1)->id << ")\n";
        cout << "\n[!] Data Ditemukan!\n";
        cout << "ID: " << (arr + offset + 1)->id << " | Nama: " << (arr + offset + 1)->nama << " | Harga: Rp" << (arr + offset + 1)->harga << "\n";
        return;
    }

    if (!found) cout << "\n[!] Data dengan ID '" << target << "' tidak ditemukan.\n";
}

void bubblesort_nama(Hewan* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((arr + j)->nama > (arr + j + 1)->nama) {
                swap_hewan((arr + j), (arr + j + 1));
            }
        }
    }
    cout << "Data berhasil diurutkan berdasarkan Nama (A-Z) dengan Bubble Sort!\n";
}

void selectionsort_nama(Hewan* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->harga < (arr + min_idx)->harga) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap_hewan((arr + min_idx), (arr + i));
        }
    }
    cout << "Data berhasil diurutkan berdasarkan Harga (Termurah-Termahal) dengan Selection Sort!\n";
}

int main() {
    Hewan data_petshop[100];
    int jumlah_hewan = 0;
    int pilihan;

    do {
        cout << "\n=== PAWCARE PETSHOP ===\n";
        cout << "1. Tampil Data Hewan\n";
        cout << "2. Tambah Data Hewan\n";
        cout << "3. Cari Hewan (Nama - Linear Search)\n";
        cout << "4. Cari Hewan (ID - Fibonacci Search)\n";
        cout << "5. Urutkan Hewan (Nama A-Z - Bubble Sort)\n";
        cout << "6. Urutkan Hewan (Harga Termurah - Selection Sort)\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampil_data(data_petshop, jumlah_hewan);
                break;
            case 2:
                tambah_data(data_petshop, &jumlah_hewan);
                break;
            case 3: {
                string cari_nama;
                cout << "Masukkan nama hewan yang dicari: ";
                cin >> ws; getline(cin, cari_nama);
                linear_search(data_petshop, jumlah_hewan, cari_nama);
                break;
            }
            case 4: {
                int cari_id;
                cout << "Masukkan ID hewan yang dicari: ";
                cin >> cari_id;
                fibonacci_search(data_petshop, jumlah_hewan, cari_id);
                break;
            }
            case 5:
                bubblesort_nama(data_petshop, jumlah_hewan);
                break;
            case 6:
                selectionsort_nama(data_petshop, jumlah_hewan);
                break;
            case 0:
                cout << "Terima kasih telah menggunakan Pawcare Petshop System!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}