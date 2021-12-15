#include <iostream>

using namespace std;

//red listom, elemente dodajemo na kraj, read je head, write je tail

class Red {
    private:
        struct Cvor {
            double broj;
            Cvor *next;
        };
        Cvor *read;
        Cvor *write;

    public:
        Red() {read = write = nullptr;}

        bool dodaj(double broj) {
            Cvor *newCvor = new (nothrow) Cvor;
            if(newCvor == nullptr) {return false;}

            newCvor->broj = broj;
            newCvor->next = nullptr;

            if(write == nullptr) {  //ako je red prazan, pa dodajemo prvi element u red
                read = write = newCvor;
            } else {
                write->next = newCvor;
            }
            write = newCvor;
            return true;
        }

        bool skini(double &broj) {

            if(read == nullptr) {     //ako je lista prazna
                return false;
            }

            Cvor *tbd = read;
            broj = read->broj;
            read = read->next;

            if(read == nullptr) {   //ako smo s ovime obrisali zadnji element, pa je sljedeci read na nullptr, zanci da je lista prazna, moramo i staviti write na nullptr, da write ne bi pokazivao na neki element koji je unisten
                write = nullptr;
            }
            
            delete tbd;
            return true;
        }

        void print() {
            cout << "READ";
            for(auto curr = read; curr != nullptr; curr = curr->next) {
                cout << " -> " << curr->broj;
            }
            cout << " <- WRITE" << endl;
        }

};

int main() {

    Red r;
    int n;
    cout << "Upisite velicinu reda n, n <= 10: ";
    cin >> n;

    double broj;
    for(int i = 0; i < n; i++) {
        cout << "Upisite realan broj kojeg zelite dodati u red >  ";
        cin >> broj;
        r.dodaj(broj);
    }

    r.print();

    cout << "READ";
    while(r.skini(broj)) {
        cout << " -> " << broj;
    }
    cout << " <- WRITE" << endl;

    return 0;
}