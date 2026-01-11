#include <iostream>
#include "kost.h"
#include <iomanip>
#include <vector> // Tambahkan ini

using namespace std;

int main() {
    Node* root = NULL;
    vector<Tenant> history; // Untuk menyimpan urutan asli (sebelum diurutkan)
    int pilihan;
    string inputNama;
    int inputUmur;
    long long inputBudget;

    do {
        cout << "\n========================================" << endl;
        cout << "        SISTEM MANAJEMEN KOS      " << endl;
        cout << "========================================" << endl;
        cout << "1. Daftar Masuk Kos (Input Data)" << endl;
        cout << "2. Lihat Urutan Input (Belum Terurut)" << endl;
        cout << "3. Lihat Berdasarkan Harga (Terurut BST)" << endl;
        cout << "4. Keluar" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

       switch (pilihan) {
        case 1: {
            cin.ignore();
            cout << "\nMasukkan Nama Calon Penghuni : ";
            getline(cin, inputNama);
            cout << "Masukkan Umur                : ";
            cin >> inputUmur;
            cout << "Masukkan Budget Harga        : Rp ";
            cin >> inputBudget;

            // Masukkan ke Tree
            root = insertNode(root, inputNama, inputUmur, inputBudget);

            // Masukkan ke Vector (History)
            Tenant tBaru;
            tBaru.nama = inputNama;
            tBaru.umur = inputUmur;
            tBaru.budget = inputBudget;
            determineType(tBaru);
            history.push_back(tBaru);

            cout << ">> Data berhasil ditambahkan!" << endl;
            break;
        } // Tambahkan kurung kurawal tutup

        case 2: {
            cout << "\nDATA SESUAI URUTAN INPUT (BELUM TERURUT):" << endl;
            cout << "--------------------------------------------------------" << endl;
            cout << "| " << left << setw(15) << "NAMA" << "| " << setw(5) << "UMUR"
                 << "| " << setw(15) << "HARGA" << "| " << setw(10) << "TIPE" << " |" << endl;
            cout << "--------------------------------------------------------" << endl;

            if (history.empty()) {
                cout << "|            Belum ada data penghuni                   |" << endl;
            } else {
                displayRaw(history);
            }
            cout << "--------------------------------------------------------" << endl;
            break;
        }

        case 3:
            cout << "\nDAFTAR PENGHUNI KOS (Diurutkan berdasarkan Harga Termurah):" << endl;
            cout << "--------------------------------------------------------" << endl;
            cout << "| " << left << setw(15) << "NAMA"
                 << "| " << setw(5) << "UMUR"
                 << "| " << setw(15) << "HARGA"
                 << "| " << setw(10) << "TIPE" << " |" << endl;
            cout << "--------------------------------------------------------" << endl;

            if (root == NULL) {
                cout << "|              Belum ada data penghuni                 |" << endl;
            } else {
                displayInOrder(root);
            }
            cout << "--------------------------------------------------------" << endl;
            break;

        case 4:
            cout << "Terima kasih telah menggunakan program." << endl;
            cleanUp(root);
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 4);

    return 0;
}
