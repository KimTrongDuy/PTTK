#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm tìm giá trị lớn nhất giữa 2 số
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Hàm giải bài toán xếp balo bằng phương pháp quy hoạch động
int knapsack(int W, vector<int> wt, vector<int> val, int n) {
    vector<vector<int>> K(n + 1, vector<int>(W + 1));

    // Tạo bảng K[][] để lưu trữ giá trị tối ưu cho các bài toán con
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            }
            else if (wt[i - 1] <= w) {
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            }
            else {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    return K[n][W];
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W, max_val;

    cout << "Nhập giá trị max mà balo có thể chứa: ";
    cin >> W;

    int n = val.size();

    max_val = knapsack(W, wt, val, n);

    if (max_val > W) {
        cout << "Khong the xep het tat ca cac vat pham vao balo";
    }
    else {
        cout << "Gia tri toi da co the dat duoc: " << max_val;
    }

    return 0;
}
