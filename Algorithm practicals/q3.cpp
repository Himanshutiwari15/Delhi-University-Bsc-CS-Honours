//Randomized Quick Sort

#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int comparison = 0;

void display(int *a, int size)
{
    cout << "{ ";
    for (int i = 0; i < size; i++)
        cout << a[i] << ' ';
    cout << "}" << endl;
}

void swap(int *a, int x, int y)
{
    int temp = a[y];
    a[y] = a[x];
    a[x] = temp;
}

int partition(int *a, int p, int r)
{
    int i = p - 1, j, x;
    for (j = p; j < r; j++)
        if (a[j] <= a[r])
        {
            comparison += 2;
            i++;
            swap(a, j, i);
        }
    swap(a, i + 1, r);

    return i + 1;
}

int randomizedPartition(int *a, int beg, int end)
{
    int t = (rand() % (end - beg)) + beg;
    swap(a, end, t);
    return partition(a, beg, end);
}

void randomizedQuickSort(int *a, int p, int r)
{
    if (p < r)
    {
        comparison++;
        int q = randomizedPartition(a, p, r);
        randomizedQuickSort(a, p, q - 1);
        randomizedQuickSort(a, q + 1, r);
    }
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

    randomizedQuickSort(arr, 0, size - 1);
    cout << "\n\nTotal comperision made: " << comparison;

    cout << "\n Sorted array: \n";
    display(arr, size);
    getch();
    return 0;
}