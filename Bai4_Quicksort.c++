#include <iostream>

using namespace std;

template <class DataType>
void quickSort(DataType a[], int left, int right)
{
    if (left >= right) return;

    DataType x = a[(left + right) / 2];
    int i = left - 1, j = right + 1;

    while (i < j) {
        do { i++; } while (a[i] < x);
        do { j--; } while (a[j] > x);
        if (i < j) swap(a[i], a[j]);
    }

    quickSort(a, left, j);
    quickSort(a, j + 1, right);
}

int main()
{
    int n;
    cout << "Nhap so luong phan tu : ";
    cin >> n;

    int arr[n];
    cout << "Nhap mang arr:";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
