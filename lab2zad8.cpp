#include <iostream>
#include <ctime>

using namespace std;
//red implementiran listom, elemente dodajemo na kraj
class Red {
    private:
        struct Cvor {
            double broj;
            Cvor *next;
        };
        Cvor *write;  //tail, ulaz
        Cvor *read;  //head, izlaz

    public:

        bool dodaj(int broj) {
            Cvor *newCvor = new (nothrow) Cvor;
            if(newCvor == nullptr) {return false;}

            newCvor->broj = broj;
            newCvor->next = nullptr;

            if(write == nullptr) {  //ako je tail na nullptr, lista je prazna
                read = newCvor;
            } else {
                write->next = newCvor;
            }
            write = newCvor;
            return true;

        }

        bool skini(double &broj) {

            if(read == nullptr) {
                return false;
            }

            Cvor *tbd = read;
            broj = read->broj;
            read = read->next;

            if(read == nullptr) {
                write == nullptr;
            }

            delete tbd;
            return true;
        }

        bool poljeURed(int polje[], int n) {
            if(n == 0) {
                return true;
            }

            cout << "Dodaje se broj > " << polje[n - 1] << endl;
            return this->dodaj(polje[n - 1]) ? poljeURed(polje, n - 1) : false;
        }

};

int main() {

    int polje[10];
    Red *r = new Red();
    
    srand((unsigned)time(0));

    for(int i = 0; i < 10; i++) {
        polje[i] = rand() % 10 + 1;
    }

    cout << "Clanovi polja prije dodavanja u red:" << endl;
    for(int i = 0; i < 10; i++) {
        cout << i << ". ->" << polje[i] << endl;
    }

    r->poljeURed(polje, 10);

    double broj;
    cout << "Red nakon dodavanja clanova iz polja:" << endl;
    cout << "READ";
    while(r->skini(broj)) {
        cout << " -> " << broj;
    }
    cout << " <- WRITE" << endl;
    return 0;
}


