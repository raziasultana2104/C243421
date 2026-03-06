#include <iostream>

using namespace std;
void bubbleSort(int arr[], int n);
void inputArray(int arr[], int n);
void display(int arr[], int n);
int main()
{
    int n = 0;
    cin >> n;
    int arr[1000];
    inputArray(arr, n);
    bubbleSort(arr, n);
    display(arr,n);
    
}
void bubbleSort(int arr[], int n)
{
    int t= 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }
 
}
void inputArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
void display(int arr[],int n)
{
     for (int i = 0; i < n; i++)
    {
        cout<< arr[i]<<" ";
    }
    cout<<endl;
}