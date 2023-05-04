#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> V = {500000, 200000, 100000, 50000, 20000, 10000, 5000, 2000, 1000}; // danh sách các loại tiền

void doi_tien(int n) {
    sort(V.begin(), V.end(), greater<int>()); // sắp xếp danh sách theo thứ tự giảm dần

    int i = 0;
    while (n > 0) { // lặp lại cho đến khi số tiền đổi được bằng số tiền cần đổi
        if (n >= V[i]) { // nếu số tiền cần đổi vẫn còn lớn hơn loại tiền đang xét
            cout << V[i] << " "; // đưa loại tiền đang xét vào danh sách kết quả
            n -= V[i]; // giảm số tiền cần đổi đi bằng giá trị loại tiền đang xét
        } else { // nếu không đổi được loại tiền đang xét, chuyển sang loại tiền tiếp theo
            i++;
        }
    }

    cout << endl; // in ra kết quả
}

int main() {
    int n;
    cout << "Nhap so tien can doi: ";
    cin >> n;

    cout << "Cac loai tien can dung de doi " << n << " la: ";
    doi_tien(n);

    return 0;
}
