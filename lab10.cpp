#include <iostream>
using namespace std;

void rabinKarp(string t, string p, int q)
{
    int d = 256;
    int n = t.size();
    int m = p.size();

    int h = 1;

    
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    int ph = 0; 
    int th = 0; 

   
    for (int i = 0; i < m; i++)
    {
        ph = (d * ph + p[i]) % q;
        th = (d * th + t[i]) % q;
    }

    for (int i = 0; i <= n - m; i++)
    {
        if (ph == th)
        {
            bool match = true;

            for (int j = 0; j < m; j++)
            {
                if (t[i + j] != p[j])
                {
                    match = false;
                    break;
                }
            }

            if (match)
                cout << "Match at index " << i << endl;
        }

        if (i < n - m)
        {
            th = (d * (th - t[i] * h) + t[i + m]) % q;

            if (th < 0)
                th += q;
        }
    }
}

int main()
{
    string t, p;
    int q;

    cin >> q;
    cin >> t >> p;

    rabinKarp(t, p, q);

    return 0;
}