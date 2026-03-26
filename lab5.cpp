#include <iostream>

using namespace std;

void quickSort(int a[], int l, int r);
int partition(int a[], int l, int r);
void inputArray(int a[], int n);
void display(int a[], int n);

int main()
{
    int n = 0;
    cin >> n;

    int a[1000];

    inputArray(a, n);
    quickSort(a, 0, n - 1);
    display(a, n);
}

void quickSort(int a[], int l, int r)
{
    if (l < r)
    {
        int p = partition(a, l, r);

        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
    }
}

int partition(int a[], int l, int r)
{
    int p = a[r]; // pivot
    int i = l - 1;

    for (int j = l; j < r; j++)
    {
        if (a[j] < p)
        {
            i++;
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }

    int t = a[i + 1];
    a[i + 1] = a[r];
    a[r] = t;

    return i + 1;
}

void inputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}