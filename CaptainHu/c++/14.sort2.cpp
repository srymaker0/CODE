/*************************************************************************
	> File Name: 14.sort2.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Tue 09 Mar 2021 10:13:13 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

ostream &operator<<(ostream &out, const vector<int> &a) {
    for (auto x : a) {      //c++11  for之auto语法
        out << x << " ";
    }
    return out;
}

bool cmp1(int a, int b) {
    return a > b;
}


namespace haizei {
///仿函数， 重载() 变成可调用对象
class CMP {
public :
    CMP(int z = 0) : z(z) {}   // z = 0 less, z = 1 greater
    bool operator()(int a, int b) {
        return (a < b) ^ !!(z);      //逻辑归1 z默认是0 
    }
    int z;
};

//cmp是一个函数指针对象，表现的像函数指针，实际是一个对象
//cmp返回值是bool，传入的参数是两个int
void sort(int *arr, int l, int r, function<bool(int, int)> cmp = CMP()) {
    if (l >= r) return ;
    int x = l, y = r, z = arr[(l + r) >> 1];
    do {
        while (cmp(arr[x], z)) ++x;
        while (cmp(z, arr[y])) --y;
        if (x <= y) {
            swap(arr[x], arr[y]);
            ++x, --y;
        }
    } while (x <= y);
    sort(arr, l, y, cmp);
    sort(arr, x, r, cmp);
    return ;
}

}  //end of haizei
int main() {
    vector<int> arr;
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    //sort(arr.begin(), arr.end(), cmp1);   //第三个参数是函数名
    sort(arr.begin(), arr.end(), haizei::CMP(1));        //第三个参数是对象名 匿名对象  
    cout << arr << endl;
    int arr2[5] = {6, 8, 4, 5, 1};
    //小->大
    haizei::sort(arr2, 0, 4);
    for (int i = 0; i < 5; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    //大->小
    haizei::sort(arr2, 0, 4, cmp1);
    for (int i = 0; i < 5; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    //小->大
    haizei::sort(arr2, 0, 4, haizei::CMP());
    for (int i = 0; i < 5; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    //大->小
    haizei::sort(arr2, 0, 4, haizei::CMP(1));
    for (int i = 0; i < 5; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}
