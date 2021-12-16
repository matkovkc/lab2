#include <iostream>
#include <string>

using namespace std;

void Zamijeni(string *prvi, string *drugi)
{
    string temp = *prvi;
    *prvi = *drugi;
    *drugi = temp;
}

void BubbleSortPoboljsani(string A[], int N, int smjer)
{
    bool swapped = true;
    for (int i = 0; swapped; i++)
    {
        swapped = false;
        for (int j = 0; j < N - 1 - i; j++)
        {
            if (smjer == 1)
            { // uzlazno sortiranje
                if (A[j + 1] < A[j])
                {
                    Zamijeni(&A[j + 1], &A[j]);
                    swapped = true;
                }
            }
            else
            {
                if (A[j + 1] > A[j])
                {
                    Zamijeni(&A[j + 1], &A[j]);
                    swapped = true;
                }
            }
        }
    }
}

int main(void)
{
    static const int MAX = 4;
    string *A = new string[4];

    for (int i = 0; i < MAX; i++)
    {
        cout << "Upisite " << i + 1 << ". string: ";
        getline(cin, A[i]);
    }

    int smjer;
    cout << "Upisite zeljeni smjer sortiranja (0/1): ";
    cin >> smjer;

    BubbleSortPoboljsani(A, MAX, smjer);

    cout << "{";
    for (int i = 0; i < MAX - 1; i++)
    {
        cout << "\"" << A[i] << "\", ";
    }
    cout << "\"" << A[MAX - 1] << "\"}" << endl;

    delete[] A;

    return 0;
}