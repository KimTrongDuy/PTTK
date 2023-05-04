#include <iostream>
#include <cstdlib> // thư viện sử dụng hàm rand()

using namespace std;

template <class DataType>
int partition(DataType a[], int left, int right)
{
    // sinh số ngẫu nhiên trong khoảng từ left đến right
    int randIndex = rand() % (right - left + 1) + left;
    DataType x = a[randIndex];
    swap(a[randIndex], a[right]); // đưa phần tử mốc lên cuối mảng

    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (a[j] < x) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[right]);
    return i + 1;
}

template <class DataType>
void quickSort(DataType a[], int left, int right)
{
    if (left >= right) return;

    int pivotIndex = partition(a, left, right);

    quickSort(a, left, pivotIndex - 1);
    quickSort(a, pivotIndex + 1, right);
}

int main()
{
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    int arr[n];
    cout << "Nhap mang arr: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr, 0, n - 1);

    cout << "Mang arr da duoc sap xep: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
