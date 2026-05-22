#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> arr;
    int n=0,input;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>input;
        arr.push_back(input);
    }
    
    vector<int> lis(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    int maximum = 0;
    for (int i = 0; i < n; i++) {
        if (maximum < lis[i])
            maximum = lis[i];
    }

    cout << "Length of LIS: " << maximum << endl;

    return 0;
}