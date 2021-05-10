/*
	Implement Radix Sort.
*/

#include <iostream>
using namespace std;

class unsortedArray
{
private:
    int a[5];

public:
    int len = 0;

    // The array to be sorted
    void array()
    {
        cout << "Enter the numbers : \n";
        for (int i = 0; i < 5; i++)
        {
            cout << "   a[" << i << "] = ";
            cin >> a[i];
        }
        len = (sizeof(a) / sizeof(a[0]));
    }

    // Maximum value in array a[5]
    int getMax()
    {
        int m = a[0];
        for (int i = 1; i < len; i++)
            if (a[i] > m)
                m = a[i];
        return m;
    }

    // Counting sort of array a[5] according to digit represented by exp.
    void countSort(int exp)
    {
        int output[len];
        int count[len + 1] = {0};

        for (int i = 0; i < len; i++)
            count[(a[i] / exp) % 10]++;

        for (int i = 1; i < len + 1; i++)
            count[i] += count[i - 1];

        for (int i = len - 1; i >= 0; i--)
        {
            output[count[(a[i] / exp) % 10] - 1] = a[i];
            count[(a[i] / exp) % 10]--;
        }

        for (int i = 0; i < len; i++)
            a[i] = output[i];
    }

    // Radix Sort
    void radixSort()
    {
        int m = getMax();

        for (int exp = 1; m / exp > 0; exp *= 10)
            countSort(exp);
    }

    // Printing the array
    void printArray()
    {
        for (int i = 0; i < len; i++)
            cout << a[i] << "\t";
        cout << endl;
    }
};

int main()
{
    unsortedArray a1;
    a1.array();

    cout << "\nRadix Sort=>\n";
    a1.radixSort();
    a1.printArray();

    for (int i = 0; i < 211; i++)
        cout << "-";
    cout << endl;

    return 0;
}