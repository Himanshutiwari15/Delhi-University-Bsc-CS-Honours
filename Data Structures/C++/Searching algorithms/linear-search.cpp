#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main(void)
{
    int x, n, arr[100];
    cout << "Size of the array : ";
    cin >> n;
    cout << "Enter elements : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter element to be searched : ";
    cin >> x;
    int result = linearSearch(arr, n, x);
    (result == -1) ? cout << "\nElement is not present in array"
                   : cout << "\nElement is present at index " << result;
    return 0;
}