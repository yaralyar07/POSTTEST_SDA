#include <iostream>
#include <string>

using namespace std;

const int MAX = 5; 

struct Hewan {
    int id;
    string nama;
    string jenis;
    int harga;
};

struct QueueAntrian {
    Hewan data[MAX];
    int front;
    int rear;
};

struct StackRiwayat {
    Hewan data[MAX];
    int top;
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

int min_val(int x, int y) {
    return (x <= y) ? x : y;
}

void fibonacci_search(Hewan* arr, int n, int target) {
    if (n == 0) {
        cout << "Data kosong!\n";
        return;
    }
    sort_id(arr, n);
    cout << "\n[Info] Data telah diurutkan berdasarkan ID otomatis untuk Fibonacci Search.\n";
    
    int fib_m2 = 0; 
    int fib_m1 = 1; 
    int fib_m = fib_m2 + fib_m1; 

    while (fib_m < n) {
        fib_m2 = fib_m1;
        fib_m1 = fib_m;
        fib_m = fib_m2 + fib_m1;
    }

    int offset = -1;
    bool found = false;

    while (fib_m > 1) {
        int i = min_val(offset + fib_m2, n - 1);
        cout << "-> [Iterasi] Mengecek indeks ke-" << i << " (ID: " << (arr + i)->id << ")\n";

        if ((arr + i)->id < target) {
            fib_m = fib_m1;
            fib_m1 = fib_m2;
            fib_m2 = fib_m - fib_m1;
            offset = i;
        } else if ((arr + i)->id > target) {
            fib_m = fib_m2;
            fib_m1 = fib_m1 - fib_m2;
            fib_m2 = fib_m - fib_m1;
        } else {
            cout << "\n[!] Data Ditemukan!\n";
            cout << "ID: " << (arr + i)->id << " | Nama: " << (arr + i)->nama << " | Harga: Rp" << (arr + i)->harga << "\n";
            found = true;
            return;
        }
    }

    if (fib_m1 && offset + 1 < n && (arr + offset + 1)->id == target) {
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
    cout << "Data berhasil diurutkan berdasarkan Harga dengan Selection Sort!\n";
}

bool is_queue_full(QueueAntrian* q) { return q->rear == MAX - 1; }
bool is_queue_empty(QueueAntrian* q) { return q->rear < q->front; }

void enqueue(QueueAntrian* q, Hewan* h) {
    if (is_queue_full(q)) {
        cout << "[!] OVERFLOW: Antrian sudah penuh! Kapasitas maksimal " << MAX << " pasien.\n";
        return;
    }
    q->rear++;
    *(q->data + q->rear) = *h;
    cout << "-> Pasien " << h->nama << " (ID: " << h->id << ") berhasil masuk antrian.\n";
}

Hewan dequeue(QueueAntrian* q, bool& success) {
    Hewan dipanggil;
    if (is_queue_empty(q)) {
        cout << "[!] UNDERFLOW: Antrian kosong! Tidak ada pasien yang bisa dipanggil.\n";
        success = false;
        return dipanggil;
    }
    
    dipanggil = *(q->data + q->front);
    cout << "\n-> MEMANGGIL PASIEN: " << dipanggil.nama << " (ID: " << dipanggil.id << ") untuk diperiksa.\n";

    for (int i = q->front; i < q->rear; i++) {
        *(q->data + i) = *(q->data + i + 1);
    }
    q->rear--; 
    success = true;
    return dipanggil;
}

void tampil_antrian(QueueAntrian* q) {
    cout << "\n=== DAFTAR ANTRIAN PEMERIKSAAN ===\n";
    if (is_queue_empty(q)) {
        cout << "Antrian kosong.\n";
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        cout << i + 1 << ". ID: " << (q->data + i)->id << " | Nama: " << (q->data + i)->nama << "\n";
    }
}

bool is_stack_full(StackRiwayat* s) { return s->top == MAX - 1; }
bool is_stack_empty(StackRiwayat* s) { return s->top == -1; }

void push(StackRiwayat* s, Hewan* h) {
    if (is_stack_full(s)) {
        cout << "[!] OVERFLOW: Riwayat penuh! Tidak bisa mencatat tindakan lagi.\n";
        return;
    }
    s->top++;
    *(s->data + s->top) = *h;
    cout << "-> Riwayat pemeriksaan pasien " << h->nama << " berhasil dicatat ke sistem.\n";
}

void pop(StackRiwayat* s) {
    if (is_stack_empty(s)) {
        cout << "[!] UNDERFLOW: Riwayat kosong! Tidak ada tindakan yang bisa dibatalkan.\n";
        return;
    }
    Hewan dihapus = *(s->data + s->top);
    s->top--;
    cout << "\n-> DIBATALKAN: Riwayat medis pasien " << dihapus.nama << " (ID: " << dihapus.id << ") berhasil dihapus.\n";
}

void tampil_riwayat(StackRiwayat* s) {
    cout << "\n=== RIWAYAT TINDAKAN MEDIS (TERBARU -> LAMA) ===\n";
    if (is_stack_empty(s)) {
        cout << "Belum ada riwayat medis.\n";
        return;
    }
    for (int i = s->top; i >= 0; i--) {
        cout << s->top - i + 1 << ". ID: " << (s->data + i)->id << " | Nama: " << (s->data + i)->nama << "\n";
    }
}

void peek_data(QueueAntrian* q, StackRiwayat* s) {
    cout << "\n=== INFO TERKINI (PEEK) ===\n";
    
    if (!is_queue_empty(q)) {
        cout << "Antrian Terdepan  : " << (q->data + q->front)->nama << " (ID: " << (q->data + q->front)->id << ")\n";
    } else {
        cout << "Antrian Terdepan  : KOSONG\n";
    }

    if (!is_stack_empty(s)) {
        cout << "Riwayat Terakhir  : " << (s->data + s->top)->nama << " (ID: " << (s->data + s->top)->id << ")\n";
    } else {
        cout << "Riwayat Terakhir  : KOSONG\n";
    }
}

int main() {
    Hewan data_petshop[100];
    int jumlah_hewan = 0;
    
    QueueAntrian antrian;
    antrian.front = 0;
    antrian.rear = -1;

    StackRiwayat riwayat;
    riwayat.top = -1;

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