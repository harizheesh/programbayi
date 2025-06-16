#include <iostream>
using namespace std;

struct Posyandu {
    int bb;
    int tb;
    int umur;
    string nama;
    char jk;
    Posyandu* prev;
    Posyandu* next;
};

Posyandu* head = nullptr;
Posyandu* tail = nullptr;

void inputData() {
    char ulang;
    do {
        Posyandu* baru = new Posyandu();
        cout << "\nMasukkan nama bayi: ";
        cin.ignore();
        getline(cin, baru->nama);

        cout << "Umur (bulan): ";
        cin >> baru->umur;
        cout << "Tinggi Badan (cm): ";
        cin >> baru->tb;
        cout << "Berat Badan (kg): ";
        cin >> baru->bb;
        cout << "Jenis Kelamin (L/P): ";
        cin >> baru->jk;

        baru->prev = nullptr;
        baru->next = nullptr;

        if (head == nullptr) {
            head = tail = baru;
        } else {
            tail->next = baru;
            baru->prev = tail;
            tail = baru;
        }

        cout << "Data berhasil ditambahkan!\n";
        cout << "Apakah ingin menambah data lagi? (y/n): ";
        cin >> ulang;
    } while (ulang == 'y' || ulang == 'Y');
}

void showData() {
    if (head == nullptr) {
        cout << "\nBelum ada data.\n";
    } else {
        Posyandu* cur = head;
        cout << "\n==== DATA BAYI POSYANDU ====\n";
        while (cur != nullptr) {
            cout << "Nama         : " << cur->nama << endl;
            cout << "Umur         : " << cur->umur << " bulan\n";
            cout << "Jenis Kelamin: " << cur->jk << endl;
            cout << "Tinggi Badan : " << cur->tb << " cm\n";
            cout << "Berat Badan  : " << cur->bb << " kg\n";
            cout << "-----------------------------\n";
            cur = cur->next;
        }
    }
    cout << "\nTekan Enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
}

void tukarData(Posyandu* a, Posyandu* b) {
    string tempNama = a->nama;
    int tempUmur = a->umur;
    int tempTb = a->tb;
    int tempBb = a->bb;
    char tempJk = a->jk;

    a->nama = b->nama;
    a->umur = b->umur;
    a->tb = b->tb;
    a->bb = b->bb;
    a->jk = b->jk;

    b->nama = tempNama;
    b->umur = tempUmur;
    b->tb = tempTb;
    b->bb = tempBb;
    b->jk = tempJk;
}

void sortData() {
    if (head == nullptr || head->next == nullptr) {
        cout << "Data kosong atau hanya satu, tidak perlu disorting.\n";
        return;
    }
    int pilih;
    cout << "\n==== PILIHAN SORTING ====\n";
    cout << "1. Berdasarkan Nama (A-Z)\n";
    cout << "2. Berdasarkan Tinggi Badan (cm)\n";
    cout << "3. Berdasarkan Berat Badan (kg)\n";
    cout << "4. Berdasarkan Umur (bulan)\n";
     cout << "----------------------\n";
    cout << "Pilih jenis sorting: ";
    cin >> pilih;

    Posyandu* i = head->next;
    while (i != nullptr) {
        Posyandu* j = i;
        while (j->prev != nullptr) {
            bool kondisi = false;
            switch (pilih) {
                case 1:
                    kondisi = j->nama < j->prev->nama;
                    break;
                case 2:
                    kondisi = j->tb < j->prev->tb;
                    break;
                case 3:
                    kondisi = j->bb < j->prev->bb;
                    break;
                case 4:
                    kondisi = j->umur < j->prev->umur;
                    break;
                default:
                    cout << "Pilihan tidak valid.\n";
                    return;
            }

            if (kondisi) {
                tukarData(j, j->prev);
                j = j->prev;
            } else {
                break;
            }
        }
        i = i->next;
    }

    cout << "\nData berhasil diurutkan.\n";
}

void cariData() {
    if (head == nullptr) {
        cout << "Data masih kosong.\n";
        return;
    }

    string cari;
    cout << "\nMasukkan nama yang ingin dicari: ";
    cin.ignore();
    getline(cin, cari);

    Posyandu* cur = head;
    bool found = false;

    while (cur != nullptr) {
        if (cur->nama == cari) {
            cout << "\n==== Data ditemukan! ====\n";
            cout << "Nama         : " << cur->nama << endl;
            cout << "Umur         : " << cur->umur << " bulan\n";
            cout << "Jenis Kelamin: " << cur->jk << endl;
            cout << "Tinggi Badan : " << cur->tb << " cm\n";
            cout << "Berat Badan  : " << cur->bb << " kg\n";
            cout << "---------------------------\n";
            found = true;
            break;
        }
        cur = cur->next;
    }

    if (!found) {
        cout << "\nData tidak ditemukan.\n";
    }
}

int main() {
    int pilihan;
    do {
        cout << "\n==== MENU UTAMA ====\n";
        cout << "1. Input Data\n";
        cout << "2. Show Data\n";
        cout << "3. Sort Data\n";
        cout << "4. Cari Data\n";
        cout << "5. Keluar\n";
        cout << "----------------------\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                inputData();
                break;
            case 2:
                showData();
                break;
            case 3:
                sortData();
                break;
            case 4:
                cariData();
                break;
            case 5:
                cout << "TERIMAKASIH ATAS KUNJUNGAN ANDA!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
    } while (pilihan != 5);

    return 0;
}