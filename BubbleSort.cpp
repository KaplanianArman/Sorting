#include <iostream>
#include <vector>

int main() {
    int n; std::cin >> n;
    std::vector<int> mas(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> mas[i];
    }

    for (int i = 1; i < n; ++i) {
        int cur = mas[i];
        int j = i - 1;
        while (j >= 0 && mas[j] > cur) {
            mas[j + 1] = mas[j];
            j--;
        }
        mas[j + 1] = cur;
    }
    for (int i = 0; i < n; ++i) {
        std::cout << mas[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}