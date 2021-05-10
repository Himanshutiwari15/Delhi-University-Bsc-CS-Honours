#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
float findMax(float A[], int n)
{
    if (n == 1)
        return A[0];
    return max(A[n - 1], findMax(A, n - 1));
}
void bucketSort(float arr[], int n)
{
    float max = findMax(arr, n);
    vector<float> b[n];
    // 2) Put array elements in different buckets
    for (int i = 0; i < n; i++)
    {
        int bi = n * arr[i] / (max + 1); // Index in bucket
        b[bi].push_back(arr[i]);
    }
    // 3) Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());
    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}
int main()
{
    int n;
    cin>>n;
    float arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    bucketSort(arr, n);
    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}