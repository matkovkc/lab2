#include <iostream>

using namespace std;

struct zapis {
    int sifra;
    string naziv;
};

void obicanBubbleSort(zapis A[], int n, char smjer) {
    int i, j;
    zapis temp;
    if(smjer == '0') {  //sortiraj uzlazno
        for(i = 0; i < n - 1; i++) {
            for(j = 0; j < n - 1 - i; j++) {
                if(A[j + 1].sifra < A[j].sifra) {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                }
            }
        }
    } else {
        for(i = 0; i < n - 1; i++) {
            for(j = 0; j < n - 1 - i; j++) {
                if(A[j+1].sifra > A[j].sifra) {
                    temp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = temp;
                }
            }
        }
    }
}


int main() {

    char s;
    int n;
    cout << "Upisite velicinu polja n, n <= 10: ";
    cin >>n;

    zapis polje[n];

    for(int i = 0; i < n; i++) {
        cout << (i + 1) << "." << endl;
        cout << "naziv jela: ";
        cin >> polje[i].naziv;
        cout << "sifra jela: ";
        cin >> polje[i].sifra;
    }

    cout << "Upisite 0 za uzlazno sortiranje ili 1 za silazno sortiranje > ";
    cin >> s;

    obicanBubbleSort(polje, n, s);

    for(int i = 0; i < n; i++) {
        cout << i + 1 << ". naziv jela: " << polje[i].naziv << ", sifra jela: " << polje[i].sifra << endl;
    }

    return 0;
}