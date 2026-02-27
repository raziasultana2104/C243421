#include <iostream>

using namespace std;
int binarySearch(int arr[], int n, int val);
void inputArray(int arr[], int n);
int main()
{
    int n = 0;
    cin >> n;
    int arr[1000];
    inputArray(arr, n);
    int val;
    cin >> val;
    int index = binarySearch(arr, n, val);
    if(index == -1)
    {
        cout<<"not found\n";
    }
    else
    {
        cout<<index+1;
    }
    return 0;
}
int binarySearch(int arr[], int n, int val)
{
    int index = -1;
    int l=0, r = n-1,m=0;
    while(l<=r)
    {
        m=(r+l)/2;
        if(arr[m]==val)
        {
            index=m;
            break;
        }
        else if(arr[m]<val)
        {
            l=m+1;
        }
        else
        {
            r=m-1;
        }
    }
    return index;
}
void inputArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
