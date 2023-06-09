#include <iostream>
using namespace std;

void hanoi(int n, char A, char B, char C) {
    if (n == 1) {
        cout << "Move disk 1 from " << A << " to " << C << endl;
        return;
    }
    hanoi(n - 1, A, C, B);
    cout << "Move disk " << n << " from " << A << " to " << C << endl;
    hanoi(n - 1, B, A, C);
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
