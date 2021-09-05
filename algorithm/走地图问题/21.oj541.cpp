/*************************************************************************
	> File Name: 21.oj541.cpp
	> Author:Yj_Z 
	> Mail: 
	> Created Time: Tue 02 Feb 2021 03:43:59 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int n, m, arr[2][20][20], ans[2][100005], ans_cnt[2];

void func(int people, int now, int cost) {
    if (now == n) {
        ans[people][ans_cnt[people]] = cost;
        ans_cnt[people]++;
        return ;
    }
    for (int i = now + 1; i <= n; i++) {
        if (arr[people][now][i] != 0) {
            func(people, i, cost + arr[people][now][i]);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        arr[0][a][b] = arr[0][b][a] = c;
        arr[1][a][b] = arr[1][b][a] = d;
    }
    func(0, 1, 0);
    func(1, 1, 0);
    sort(ans[0], ans[0] + ans_cnt[0]);
    for (int i = 0; i < ans_cnt[0]; i++) {
        for (int j = 0; j < ans_cnt[1]; j++) {
            if (ans[0][i] == ans[1][j]) {
                cout << ans[0][i] << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
