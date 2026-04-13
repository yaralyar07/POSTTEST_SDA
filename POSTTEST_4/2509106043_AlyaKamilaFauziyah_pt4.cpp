#include <iostream>
#include <string>

using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    int harga;
    Hewan* next; 
};

struct QueueAntrian {
    Hewan* front;
    Hewan* rear;
};

struct StackRiwayat {
    Hewan* top;
};


void swap_hewan(Hewan* a, Hewan* b) {
    int temp_id = a->id;
    a->id = b->id;
    b->id = temp_id;

    string temp_nama = a->nama;
    a->nama = b->nama;
    b->nama = temp_nama;

    string temp_jenis = a->jenis;
    a->jenis = b->jenis;
    b->jenis = temp_jenis;

    int temp_harga = a->harga;
    a->harga = b->harga;
    b->harga = temp_harga;
    
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
    (arr + *n)->next = nullptr; 
    (*n)++; 
    cout << "Data berhasil ditambahkan!\n";
}

void linear_search(Hewan* arr, int n, string target) {
    bool found = false;
    cout << "\n=== Proses Linear Search ===\n";
    for (int i = 0; i < n; i++) {
        cout << "-> [Iterasi " << i+1 << "] Mengecek data dengan nama: " << (arr + i)->nama << "\n";
        if ((arr + i)->nama == target) {
            cout << "\n[!] Data Ditemukan!\n";
            cout << "ID: " << (arr + i)->id << " | Nama: " << (arr + i)->nama << " | Harga: Rp" << (arr + i)->harga << "\n";
            found = true;
            break;
        }
    }
    if (!found) cout << "\n[!] Data tidak ditemukan.\n";
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

int min_val(int x, int y) {
    return (x <= y) ? x : y;
}

void fibonacci_search(Hewan* arr, int n, int target) {
    if (n == 0) { cout << "Data kosong!\n"; return; }
    sort_id(arr, n);
    
    int fib_m2 = 0, fib_m1 = 1; 
    int fib_m = fib_m2 + fib_m1; 
    while (fib_m < n) {
        fib_m2 = fib_m1; fib_m1 = fib_m; fib_m = fib_m2 + fib_m1;
    }

    int offset = -1;
    bool found = false;

    while (fib_m > 1) {
        int i = min_val(offset + fib_m2, n - 1);
        if ((arr + i)->id < target) {
            fib_m = fib_m1; fib_m1 = fib_m2; fib_m2 = fib_m - fib_m1; offset = i;
        } else if ((arr + i)->id > target) {
            fib_m = fib_m2; fib_m1 = fib_m1 - fib_m2; fib_m2 = fib_m - fib_m1;
        } else {
            cout << "\n[!] Data Ditemukan!\n";
            cout << "ID: " << (arr + i)->id << " | Nama: " << (arr + i)->nama << "\n";
            found = true; return;
        }
    }
    if (fib_m1 && offset + 1 < n && (arr + offset + 1)->id == target) {
        cout << "\n[!] Data Ditemukan!\n";
        cout << "ID: " << (arr + offset + 1)->id << " | Nama: " << (arr + offset + 1)->nama << "\n";
        return;
    }
    if (!found) cout << "\n[!] Data tidak ditemukan.\n";
}

void bubblesort_nama(Hewan* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((arr + j)->nama > (arr + j + 1)->nama) {
                swap_hewan((arr + j), (arr + j + 1));
            }
        }
    }
    cout << "Data berhasil diurutkan!\n";
}

void selectionsort_nama(Hewan* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->harga < (arr + min_idx)->harga) {
                min_idx = j;
            }
        }
        if (min_idx != i) swap_hewan((arr + min_idx), (arr + i));
    }
    cout << "Data berhasil diurutkan!\n";
}

bool is_queue_empty(QueueAntrian* q) { 
    return q->front == nullptr; 
}

void enqueue(QueueAntrian* q, Hewan* h) {
    Hewan* node_baru = new Hewan;
    node_baru->id = h->id;
    node_baru->nama = h->nama;
    node_baru->jenis = h->jenis;
    node_baru->harga = h->harga;
    node_baru->next = nullptr;

    if (is_queue_empty(q)) {
        q->front = node_baru;
        q->rear = node_baru;
    } else {
        q->rear->next = node_baru;
        q->rear = node_baru;
    }
    cout << "-> Pasien " << h->nama << " (ID: " << h->id << ") berhasil masuk antrian.\n";
}

Hewan dequeue(QueueAntrian* q, bool& success) {
    Hewan dipanggil;
    if (is_queue_empty(q)) {
        cout << "[!] UNDERFLOW: Antrian kosong! Tidak ada pasien yang bisa dipanggil.\n";
        success = false;
        return dipanggil;
    }
    
    Hewan* temp = q->front;
    dipanggil = *temp; 
    dipanggil.next = nullptr; 

    cout << "\n-> MEMANGGIL PASIEN: " << dipanggil.nama << " (ID: " << dipanggil.id << ") untuk diperiksa.\n";

    q->front = q->front->next;
    
    if (q->front == nullptr) {
        q->rear = nullptr;
    }
    
    delete temp;
    success = true;
    return dipanggil;
}

void tampil_antrian(QueueAntrian* q) {
    cout << "\n=== DAFTAR ANTRIAN PEMERIKSAAN ===\n";
    if (is_queue_empty(q)) {
        cout << "Antrian kosong.\n";
        return;
    }
    
    Hewan* curr = q->front;
    int i = 1;
    while (curr != nullptr) {
        cout << i++ << ". ID: " << curr->id << " | Nama: " << curr->nama << "\n";
        curr = curr->next;
    }
}

bool is_stack_empty(StackRiwayat* s) { 
    return s->top == nullptr; 
}

void push(StackRiwayat* s, Hewan* h) {
    Hewan* node_baru = new Hewan;
    node_baru->id = h->id;
    node_baru->nama = h->nama;
    node_baru->jenis = h->jenis;
    node_baru->harga = h->harga;
    
    node_baru->next = s->top;
    s->top = node_baru;

    cout << "-> Riwayat pemeriksaan pasien " << h->nama << " berhasil dicatat ke sistem.\n";
}

void pop(StackRiwayat* s) {
    if (is_stack_empty(s)) {
        cout << "[!] UNDERFLOW: Riwayat kosong! Tidak ada tindakan yang bisa dibatalkan.\n";
        return;
    }
    
    Hewan* temp = s->top;
    string dihapus_nama = temp->nama;
    int dihapus_id = temp->id;

    s->top = s->top->next;
    
    delete temp; 
    cout << "\n-> DIBATALKAN: Riwayat medis pasien " << dihapus_nama << " (ID: " << dihapus_id << ") berhasil dihapus.\n";
}

void tampil_riwayat(StackRiwayat* s) {
    cout << "\n=== RIWAYAT TINDAKAN MEDIS (TERBARU -> LAMA) ===\n";
    if (is_stack_empty(s)) {
        cout << "Belum ada riwayat medis.\n";
        return;
    }
    
    Hewan* curr = s->top;
    int i = 1;
    while (curr != nullptr) {
        cout << i++ << ". ID: " << curr->id << " | Nama: " << curr->nama << "\n";
        curr = curr->next;
    }
}

void peek_data(QueueAntrian* q, StackRiwayat* s) {
    cout << "\n=== INFO TERKINI (PEEK) ===\n";
    
    if (!is_queue_empty(q)) {
        cout << "Antrian Terdepan  : " << q->front->nama << " (ID: " << q->front->id << ")\n";
    } else {
        cout << "Antrian Terdepan  : KOSONG\n";
    }

    if (!is_stack_empty(s)) {
        cout << "Riwayat Terakhir  : " << s->top->nama << " (ID: " << s->top->id << ")\n";
    } else {
        cout << "Riwayat Terakhir  : KOSONG\n";
    }
}

int main() {
    Hewan data_petshop[100];
    int jumlah_hewan = 0;
    
    QueueAntrian antrian;
    antrian.front = nullptr;
    antrian.rear = nullptr;

    StackRiwayat riwayat;
    riwayat.top = nullptr;

    int pilihan;

    do {
        cout << "\n=== MANAJEMEN PAWCARE PETSHOP ===\n";
        cout << "--- Data Master ---\n";
        cout << "1. Tampil Data Hewan\n";
        cout << "2. Tambah Data Hewan\n";
        cout << "3. Cari Hewan (Nama / ID)\n";
        cout << "4. Urutkan Hewan (Nama / Harga)\n";
        cout << "--- Layanan Klinik Medis ---\n";
        cout << "5. Daftarkan Pasien (Enqueue)\n";
        cout << "6. Periksa Pasien (Dequeue & otomatis Push)\n";
        cout << "7. Tampil Antrian (Queue)\n";
        cout << "8. Tampil Riwayat Medis (Stack)\n";
        cout << "9. Batalkan Tindakan Terakhir (Pop)\n";
        cout << "10. Cek Pasien Terdepan & Riwayat Terakhir (Peek)\n";
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
                int sub_pil;
                cout << "1. Cari by Nama (Linear) | 2. Cari by ID (Fibonacci) : ";
                cin >> sub_pil;
                if (sub_pil == 1) {
                    string c_nama;
                    cout << "Nama: "; cin >> ws; getline(cin, c_nama);
                    linear_search(data_petshop, jumlah_hewan, c_nama);
                } else {
                    int c_id;
                    cout << "ID: "; cin >> c_id;
                    fibonacci_search(data_petshop, jumlah_hewan, c_id);
                }
                break;
            }
            case 4: {
                int sub_pil;
                cout << "1. Urut Nama A-Z (Bubble) | 2. Urut Harga (Selection) : ";
                cin >> sub_pil;
                if (sub_pil == 1) bubblesort_nama(data_petshop, jumlah_hewan);
                else selectionsort_nama(data_petshop, jumlah_hewan);
                break;
            }
            case 5: {
                Hewan pasien_baru;
                cout << "\n=== Pendaftaran Pasien Medis ===\n";
                cout << "Masukkan ID Hewan : "; cin >> pasien_baru.id;
                cout << "Masukkan Nama     : "; cin >> ws; getline(cin, pasien_baru.nama);
                cout << "Masukkan Jenis    : "; getline(cin, pasien_baru.jenis);
                pasien_baru.harga = 0; 
                
                enqueue(&antrian, &pasien_baru);
                break;
            }
            case 6: {
                bool is_success;
                Hewan pasien_diperiksa = dequeue(&antrian, is_success);
                
                if (is_success) {
                    cout << "-> Pasien sedang ditangani oleh Dokter Hewan...\n";
                    push(&riwayat, &pasien_diperiksa);
                }
                break;
            }
            case 7:
                tampil_antrian(&antrian);
                break;
            case 8:
                tampil_riwayat(&riwayat);
                break;
            case 9:
                pop(&riwayat);
                break;
            case 10:
                peek_data(&antrian, &riwayat);
                break;
            case 0:
                cout << "Sistem ditutup. Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}