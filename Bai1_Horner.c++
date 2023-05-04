#include <iostream>
using namespace std;

// Hàm tính giá trị của đa thức tại x, sử dụng thuật toán Horner
double evaluatePolynomial(double coefficients[], int degree, double x) {
    double result = coefficients[degree];
    for (int i = degree - 1; i >= 0; i--) {
        result = coefficients[i] + x * result;
    }
    return result;
}

int main() {
    int degree;
    cout << "Nhap bac cua da thuc: ";
    cin >> degree;

    double coefficients[degree + 1];
    cout << "Nhap cac he so cua da thuc theo thu tu: ";
    for (int i = degree; i >= 0; i--) {
        cin >> coefficients[i];
    }

    double x;
    cout << "Nhap gia tri cua x: ";
    cin >> x;

    double result = evaluatePolynomial(coefficients, degree, x);
    cout << "Gia tri cua bieu thuc tai x = " << x << " la " << result << endl;

    return 0;
}
