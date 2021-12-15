#include <iostream>
#include <string>

using namespace std;

template <class T> class Lista {

    private:
        struct Cvor {
            T element;
            Cvor *next;
        };

        Cvor *head;
        Cvor *tail;

    public:
        Lista() {head = tail = nullptr;}

        bool upis(T element) {
            Cvor *newCvor = new (nothrow) Cvor;
            if(newCvor == nullptr) { return false;}

            newCvor->element = element;
            newCvor->next = nullptr;

            if(head == nullptr || head->element > newCvor->element) {
                newCvor->next = head;
                head = newCvor;
            } else {
                Cvor *curr = head;
                Cvor *prev;
                while(curr != nullptr && curr->element < newCvor->element) {
                    prev = curr;
                    curr = curr->next;
                }

                newCvor->next = curr;
                prev->next = newCvor;
            
            }

            if(tail == nullptr || newCvor->next == nullptr) {
                tail = newCvor;
            }

            return true;
        }

        void ispis() {
            cout << "HEAD -> ";
            for(auto curr = head; curr != nullptr; curr = curr->next) {
                cout << curr->element << " -> ";
            }
            cout << "NULLPTR" << endl;
        }

};

int main() {

    auto *l = new Lista<int>();

    int n;
    cout << "Upisite velicinu liste n, n <= 10 : ";
    cin >> n;

    int element;

    for(int i = 0; i < n; i++) {
        cout << "Upisite " << (i + 1) <<". clan: ";
        cin >> element;
        l->upis(element);
    }

    l->ispis();

}