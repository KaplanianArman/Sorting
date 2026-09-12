#include <iostream>
#include <vector>

std::vector<int> mas;
void Merge(int l, int r) {
    int m = (l + r) / 2;
    int sz = r - l + 1;
    std::vector<int> cur_mas(sz);
    int ptr1 = l, ptr2 = m + 1;
    int pos = 0;
    while (ptr1 <= m && ptr2 <= r) {
        if (mas[ptr1] <= mas[ptr2]) {
            cur_mas[pos] = mas[ptr1];
            ptr1++;
        }
        else {
            cur_mas[pos] = mas[ptr2];
            ptr2++;
        }
        pos++;
    }
    while (ptr1 <= m) {
        cur_mas[pos] = mas[ptr1];
        ptr1++;
        pos++;
    }
    while (ptr2 <= r) {
        cur_mas[pos] = mas[ptr2];
        ptr2++;
        pos++;
    }
    for (int i = 0; i < sz; ++i) {
        mas[i + l] = cur_mas[i];
    }
}

void MergeSort(int l, int r) {
    if (l == r) {//массив из одного элемента всегда отсортирован
        return;
    }
    int m = (l + r) >> 1;
    MergeSort(l, m);
    MergeSort(m + 1, r);
    Merge(l, r);
}

int main() {
    int n; std::cin >> n;
    mas.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> mas[i];
    }
    MergeSort(0, n - 1);
    for (int i = 0; i < n; ++i) {
        std::cout << mas[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}