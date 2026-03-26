#include <iostream>
using namespace std;

void fractionalKnapsack(int w[], int v[], int n, int c);
void inputArray(int a[], int n);

int main()
{
    int n = 0, c = 0;
    cin >> n >> c;

    int w[1000], v[1000];

    inputArray(w, n);
    inputArray(v, n);

    fractionalKnapsack(w, v, n, c);
}

void fractionalKnapsack(int w[], int v[], int n, int c)
{
    double r[1000];
    for (int i = 0; i < n; i++)
        r[i] = (double)v[i] / w[i];

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (r[i] < r[j])
            {
                double t;
                t = r[i]; r[i] = r[j]; r[j] = t;
                int tt;
                tt = w[i]; w[i] = w[j]; w[j] = tt;
                tt = v[i]; v[i] = v[j]; v[j] = tt;
            }

    double t = 0;
    for (int i = 0; i < n; i++)
    {
        if (c >= w[i])
        {
            t += v[i];
            c -= w[i];
        }
        else
        {
            t += v[i] * ((double)c / w[i]);
            break;
        }
    }

    cout << t << endl;
}

void inputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> a[i];
}