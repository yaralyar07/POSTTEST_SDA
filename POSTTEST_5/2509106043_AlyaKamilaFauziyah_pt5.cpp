#include <iostream>
#include <string>
using namespace std;

// Struktur Node untuk Circular Linked List Perpustakaan
struct BukuNode {
    string judulBuku;
    BukuNode* next;

    // Constructor
    BukuNode(string judul) {
        judulBuku = judul;
        next = nullptr;
    }
};

// Fungsi insert di akhir Circular Linked List untuk membangun data
BukuNode* tambahBuku(BukuNode* head, string judul) {
    BukuNode* newNode = new BukuNode(judul);
    if (head == nullptr) {
        newNode->next = newNode;
        return newNode;
    }
    
    BukuNode* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

/**
 * @brief Fungsi untuk mencari buku berdasarkan judulnya dalam Circular Linked List.
 * @param head Pointer ke node pertama (head).
 * @param judulDicari String judul buku yang ingin dicari.
 * @return boolean true jika buku ditemukan, false jika tidak ditemukan.
 */
bool cariBuku(BukuNode* head, string judulDicari) {
    // 1. Cek apakah list kosong untuk mencegah error
    if (head == nullptr) {
        return false;
    }

    // 2. Inisialisasi pointer sementara dari head
    BukuNode* temp = head;

    // 3. Gunakan do-while untuk memastikan head ikut dicek pertama kali
    do {
        // Cek kecocokan judul buku pada node saat ini
        if (temp->judulBuku == judulDicari) {
            return true; // Langsung kembalikan true jika ditemukan
        }
        
        // Geser ke node selanjutnya
        temp = temp->next;

    } while (temp != head); // 4. Berhenti jika pointer temp sudah memutar kembali ke head

    // 5. Jika seluruh putaran selesai dan tidak ada yang cocok
    return false;
}

int main() {
    BukuNode* head = nullptr;
    
    // Menambahkan data buku ke dalam list
    head = tambahBuku(head, "Struktur Data dengan C++");
    head = tambahBuku(head, "Pengantar Algoritma");
    head = tambahBuku(head, "Pemrograman Berorientasi Objek");
    head = tambahBuku(head, "Sistem Basis Data");

    string buku1 = "Pengantar Algoritma";
    string buku2 = "Kalkulus Lanjut";

    // Mencari buku yang ada di dalam list
    cout << "Mencari buku '" << buku1 << "': " 
         << (cariBuku(head, buku1) ? "Ditemukan" : "Tidak Ditemukan") << endl; 
         // Harusnya output: Ditemukan

    // Mencari buku yang tidak ada di dalam list
    cout << "Mencari buku '" << buku2 << "': " 
         << (cariBuku(head, buku2) ? "Ditemukan" : "Tidak Ditemukan") << endl; 
         // Harusnya output: Tidak Ditemukan

    return 0;
}