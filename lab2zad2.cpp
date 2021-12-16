#include <iostream>
#include <string>

using namespace std;

template<class T> class Lista {
    private:
        struct Cvor {
            T element;
            Cvor *next;
            Cvor *prev;
        };

        Cvor *head;
        Cvor *tail;

    public:

        Lista() {head = tail = nullptr;}

        bool upis(T element) {
            Cvor *newCvor = new (nothrow) Cvor;
            if(newCvor == nullptr) {return false;}

            newCvor->element = element;
            newCvor->next = nullptr;
            newCvor->prev = tail;

            if(tail == nullptr) {
                head = newCvor;
            } else {
                tail->next = newCvor;
            }

            tail = newCvor;
            return true;
        }

        void ispis() {
            cout << "HEAD -> ";
            for(auto curr = head; curr != nullptr; curr = curr->next) {
                cout << curr -> element << " -> ";
            }
            cout << "NULLPTR";

        }
};


int main() {
    auto *l = new Lista<string>();

    int n;
    cout << "Upisite velicinu liste n, n <= 10: ";
    cin >> n;

    string element;
    for(int i = 0; i < n; i++) {
        cout << "Upisite " << (i + 1) << ". clan polja: ";
        cin >> element;
        l->upis(element);
    }
    l->ispis();

    return 0;
}