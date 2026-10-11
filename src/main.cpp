#include <iostream>
#include <string>
using namespace std;

// Task 1: Create the Node[cite: 1]
struct Node {
    string data;
    Node* prev;
    Node* next;
};

// Task 3: Forward Traversal
void cetakMaju(Node* head) {
    Node* temp = head;
    cout << "Forward:\n";
    while (temp != NULL) {
        cout << temp->data << "\n";
        temp = temp->next;
    }
    cout << endl;
}

// Task 4: Backward Traversal
void cetakMundur(Node* tail) {
    Node* temp = tail;
    cout << "Backward:\n";
    while (temp != NULL) {
        cout << temp->data << "\n";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    // Task 2: Build a List (Membuat 5 Node)
    Node* a = new Node{"Song A", NULL, NULL};
    Node* b = new Node{"Song B", NULL, NULL};
    Node* c = new Node{"Song C", NULL, NULL};
    Node* d = new Node{"Song D", NULL, NULL};
    Node* e = new Node{"Song E", NULL, NULL};

    // Menghubungkan node menjadi: A <-> B <-> C <-> D <-> E
    a->next = b; 
    b->prev = a; b->next = c;
    c->prev = b; c->next = d;
    d->prev = c; d->next = e;
    e->prev = d;

    Node* head = a;
    Node* tail = e;

    cout << "--- Hasil Task 2, 3, dan 4 ---\n";
    cetakMaju(head);
    cetakMundur(tail);

    // Task 5: Insert in the Middle (Menyisipkan Song X antara B dan C)
    Node* x = new Node{"Song X", NULL, NULL};
    // Memutus B <-> C dan menyambungkannya dengan X
    b->next = x;
    x->prev = b;
    x->next = c;
    c->prev = x;

    cout << "--- Hasil Task 5 (Setelah Song X disisipkan) ---\n";
    cetakMaju(head); // Akan mencetak: A -> B -> X -> C -> D -> E
    cetakMundur(tail);

    // Task 6: Delete a Node (Menghapus Song C)
    // Rantai saat ini: B <-> X <-> C <-> D
    x->next = d; // Pointer next dari X melewati C, langsung ke D
    d->prev = x; // Pointer prev dari D melewati C, langsung ke X
    delete c;    // Hapus C dari memori

    cout << "--- Hasil Task 6 (Setelah Song C dihapus) ---\n";
    cetakMaju(head); // Akan mencetak: A -> B -> X -> D -> E[cite: 2]
    cetakMundur(tail);

    return 0;
}