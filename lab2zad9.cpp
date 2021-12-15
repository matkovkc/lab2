#include <iostream>
#include <string>

using namespace std;

struct Zapis {
    int postBr;
    string naziv;
};

void InsertionSort(Zapis A[], int n, char smjer) {
    Zapis curr;
    int i, j;
    for(i = 1; i < n; i++) {
        curr = A[i];
        for(j = i; j >= 1 && (smjer == '1' ? curr.postBr > A[j-1].postBr : curr.postBr < A[j-1].postBr); j--) {
            A[j] = A[j - 1];
        }
        A[j] = curr;
    }
}

int main() {
    int n;
    cout << "Upisite broj clanova polja (n <= 10) > ";
    cin >> n;

    Zapis polje[n];

    cout << "Upisite naziv i postanski broj za " << n << " mjesta: " << endl;
    for(int i = 0; i < n; i++) {
        cout << i + 1 << "." << endl;
        cout << "naziv > ";
        cin >> polje[i].naziv;
        cout << "postanski broj > ";
        cin >> polje[i].postBr;
    }

    char s;
    cout << "Unesite 1 za silazno sortiranje ili 0 za uzlazno sortiranje > ";
    cin >> s;
    InsertionSort(polje, n, s);

    for(int i = 0; i < n; i++) {
        cout << i + 1 << "." << endl;
        cout << polje[i].naziv << " " << polje[i].postBr << endl;
    }

    return 0;

}