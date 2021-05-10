#include <iostream>
#include <conio.h>

using namespace std;

int comparison = 0;
void display(int *a, int size)
{
    cout << "{ ";
    for (int i = 0; i < size; i++)
        cout << a[i] << ' ';
    cout << "}" << endl;
}

void merge(int *a, int beg, int mid, int end)
{
    int size = end - beg + 1;
    int *temp = new int[size];
    int i = beg, j = mid + 1, k = 0;

    //arranging in order
    while (i <= mid && j <= end)
    {
        temp[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
        comparison += 3;
    }
    while (i <= mid)
    {
        comparison++;
        temp[k++] = a[i++];
    }
    while (j < end)
    {
        comparison++;
        temp[k++] = a[j++];
    }

    for (i = 0; i < k; i++)
    {
        a[i + beg] = temp[i];
    }
}

void mergeSort(int *a, int beg, int end)
{
    if (beg < end)
    {
        comparison++;
        int mid = (beg + end) / 2;
        mergeSort(a, beg, mid);
        mergeSort(a, mid + 1, end);
        merge(a, beg, mid, end);
    }
}

int main()
{
    //  clrscr();
    int size, i, *arr;

    cout << "\nEnter the size of array (max. 10): ";
    cin >> size;
    arr = new int[size];
    cout << "\nEnter the array: \n";
    for (i = 0; i < size; i++)
        cin >> arr[i];

    //  clrscr();
    cout << "\n Your array: \n";
    display(arr, size);

    getch();
    //  clrscr();
    mergeSort(arr, 0, size - 1);
    cout << "\n\nTotal comperision made: " << comparison;

    cout << "\n Sorted array: \n";
    display(arr, size);

    getch();
    return 0;
}