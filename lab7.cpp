#include <iostream>
using namespace std;

void activitySelection(int s[], int f[], int n);
void inputArray(int a[], int n);
void displayArray(int a[], int n);

int main()
{
    int n = 0;
    cin >> n;

    int s[1000], f[1000];

    inputArray(s, n);
    inputArray(f, n);

    activitySelection(s, f, n);
}

void activitySelection(int s[], int f[], int n)
{
    int i = 0;
    cout << i + 1 << " ";

    for (int j = 1; j < n; j++)
    {
        if (s[j] >= f[i])
        {
            cout << j + 1 << " ";
            i = j;
        }
    }
    cout << endl;
}

void inputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}