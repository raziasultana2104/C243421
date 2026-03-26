#include <iostream>

using namespace std;

void mergeSort(int a[], int l, int r);
void merge(int a[], int l, int m, int r);
void inputArray(int a[], int n);
void display(int a[], int n);

int main()
{
    int n = 0;
    cin >> n;
    int a[1000];
    inputArray(a, n);
    mergeSort(a, 0, n - 1);
    display(a, n);
}

void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

void merge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int x[1000], y[1000];
    for (int i = 0; i < n1; i++)
    {
        x[i] = a[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        y[j] = a[m + 1 + j];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (x[i] <= y[j])
        {
            a[k] = x[i];
            i++;
        }
        else
        {
            a[k] = y[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = x[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = y[j];
        j++;
        k++;
    }
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