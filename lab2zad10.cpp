#include <iostream>
using namespace std;

void selection2Sort (int A[], int n, char smjer) {
    for(int i=0; i<n/2; i++) {
        int min=i, max=n-1-i, tmin, tmax;
        for (int j=i; j<n-i; j++) {
            if (A[min] > A[j]) min=j;
            if (A[max] < A[j]) max=j;
        }
        int manji = smjer == '0' ? i : n-1-i;
        int veci = smjer == '0' ? n-1-i : i;
        tmin = A[min];
        tmax = A[max];
        A[min] = A[manji];
        A[max] = A[veci];
        A[manji] = tmin;
        A[veci] = tmax;

    }
}

int main(void) {
    int n;
    cout << "Upisite velicinu cjelobrojnog polja n, n <= 10: ";
    cin >> n;
    int polje[n];


    for(int i=0; i<n; i++) {
        cout << "Upisite " << i << ". clan polja > ";
        cin >> polje[i];
    }

    char s;
    cout << "Upisite 0 za uzlazno sortiranje, 1 za silazno sortiranje > ";
    cin >> s;
    selection2Sort(polje, n, s);

    cout << "sortirano polje je:" << endl;
    for(int i=0; i<n; i++) {
        cout << polje[i] << " ";
    }
    cout << endl;
}