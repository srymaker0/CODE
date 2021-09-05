/*************************************************************************
	> File Name: 13.sort.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sat 06 Mar 2021 04:34:36 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

namespace haizei {
    void sort(int *arr, int l, int r, function<boll(int, int)> cmp) {
        if (l > r) return ;
        int x = l, y = r, z = arr[x];
        while (x < y) {
            while (x < y && arr[y] > z) y--;
            if (x < y) arr[x++] = arr[y];
            while (x < y && arr[x] < z) x++;
            if (x < y) arr[y--] = arr[x];
        }
        arr[x] = z;
        sort(arr, l, x - 1);
        sort(arr, x + 1, r);
    }
}

int main() {
    vector<int> arr;
    int n;
    cin >> n;
    while (n--) { int a; cin >> a, arr.push_back(a); }
    sort(arr, arr + n);

    return 0;
}
