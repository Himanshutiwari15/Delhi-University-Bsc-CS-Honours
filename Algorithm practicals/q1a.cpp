//Insertion Sort

#include <iostream>
#include <conio.h>

using namespace std;

void display(int *a, int size)
{
    cout << "{ ";
    for (int i = 0; i < size; i++)
        cout << a[i] << ' ';
    cout << "}" << endl;
}

int insertionSort(int *a, int n)
{
    int i, j, k, comperision = 0;
    for (i = 1; i < n; i++)
    {
        comperision++;
        k = a[i];
        for (j = i - 1; (a[j] > k) && (j >= 0); j--)
        {
            comperision += 2;
            a[j + 1] = a[j];
        }
        a[j + 1] = k;
    }
    return comperision;
}

int main()
{
    // clrscr();
    int size, i, *arr;

    cout << "\nEnter the size of array (max. 10): ";
    cin >> size;
    arr = new int[size];
    cout << "\nEnter the array: \n";
    for (i = 0; i < size; i++)
        cin >> arr[i];

    // clrscr();
    cout << "\n Your array: \n";
    display(arr, size);

    getch();
    // clrscr();
    cout << "\n\nTotal comperision made: " << insertionSort(arr, size);

    cout << "\n Sorted array: ";
    display(arr, size);

    getch();
    return 0;
}