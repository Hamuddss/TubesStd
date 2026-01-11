#ifndef KOSAN_H
#define KOSAN_H

#include <iostream>
#include <string>
#include <vector> // Tambahkan ini
using namespace std;

struct Tenant {
    string nama;
    int umur;
    long long budget;
    string tipeKamar;
};

struct Node {
    Tenant data;
    Node *left;
    Node *right;
};

// Fungsi-fungsi
Node* createNode(string nama, int umur, long long budget);
Node* insertNode(Node* root, string nama, int umur, long long budget);
void determineType(Tenant &t);
void displayInOrder(Node* root);
void displayRaw(const vector<Tenant>& history);
void cleanUp(Node* root);

#endif
