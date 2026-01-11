#include "kost.h"
#include <iomanip> // Untuk merapikan output tabel

// Fungsi menentukan tipe kamar berdasarkan budget
void determineType(Tenant &t) {
    if (t.budget < 2000000) {
        t.tipeKamar = "Standard";
    } else if (t.budget == 2000000) {
        t.tipeKamar = "Deluxe";
    } else {
        t.tipeKamar = "VVIP";
    }
}

// Fungsi membuat Node baru
Node* createNode(string nama, int umur, long long budget) {
    Node* newNode = new Node();
    newNode->data.nama = nama;
    newNode->data.umur = umur;
    newNode->data.budget = budget;
    determineType(newNode->data); // Set tipe kamar otomatis
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Fungsi Insert ke dalam Tree (Berdasarkan Harga)
Node* insertNode(Node* root, string nama, int umur, long long budget) {
    if (root == NULL) {
        return createNode(nama, umur, budget);
    }

    // Logic BST: Harga lebih kecil ke kiri, lebih besar/sama ke kanan
    if (budget < root->data.budget) {
        root->left = insertNode(root->left, nama, umur, budget);
    } else {
        root->right = insertNode(root->right, nama, umur, budget);
    }
    return root;
}

// Fungsi Menampilkan Data secara In-Order (Urut dari harga terkecil)
void displayInOrder(Node* root) {
    if (root != NULL) {
        displayInOrder(root->left);

        // Menampilkan data
        cout << "| " << left << setw(15) << root->data.nama
             << "| " << setw(5) << root->data.umur
             << "| Rp " << setw(12) << root->data.budget
             << "| " << setw(10) << root->data.tipeKamar << " |" << endl;

        displayInOrder(root->right);
    }
}

void displayRaw(const vector<Tenant>& history) {
    for (size_t i = 0; i < history.size(); i++) {
        cout << "| " << left << setw(15) << history[i].nama
             << "| " << setw(5) << history[i].umur
             << "| Rp " << setw(12) << history[i].budget
             << "| " << setw(10) << history[i].tipeKamar << " |" << endl;
    }
}

// Membersihkan memori
void cleanUp(Node* root) {
    if (root != NULL) {
        cleanUp(root->left);
        cleanUp(root->right);
        delete root;
    }
}
