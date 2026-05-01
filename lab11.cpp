#include <iostream>
#include <algorithm>
using namespace std;
struct item
{
    int id;
    int v;
    int w;
};

int main()
{
    int w = 0, n;
    cin >> w >> n;
    item it[100];
    for (int i = 0; i < n; i++)
    {
        it[i].id = i + 1;
        cin >> it[i].w >> it[i].v;
    }
    int b[101][1001]{};
    for (int i = 1; i <= n; i++)
    {
        cout<<"0 ";
        for (int j = 1; j <= w; j++)
        {
            if (it[i - 1].w > j)
            {
                b[i][j] = b[i - 1][j];
            }
            else
            {
                int v = b[i][j- (it[i-1].w)] + it[i-1].v;
                if (b[i - 1][j] < v)
                {
                    b[i][j] = v;
                }
                else
                {
                    b[i][j] = b[i - 1][j];
                }
            }
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Max: "<<b[n][w]<<endl;
    cout<<"cuts: ";
    int m=b[n][w];
    int i=n, j=w;
    while(m>0)
    {
        if(b[i][j]==b[i-1][j])
        {
            i--;
        }
        else
        {
            cout<<it[i-1].id<<" ";
            m-=it[i-1].v;
            j-=it[i-1].w;
        }
        
    }
}
/*
5
4
1 2
2 3
3 6
4 9



5
6
4.
*/