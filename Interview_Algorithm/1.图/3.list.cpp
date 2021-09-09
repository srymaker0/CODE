/*************************************************************************
	> File Name: 3.list.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Thu 15 Jul 2021 09:55:46 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

struct edge {
    int s, e, v;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<edge> > edg(n + 5, vector<edge>());
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edg[a].push_back((edge){a, b, c});
        //edg[a].push_back((edge){a, b, c});
    }
    for (int i = 1; i <= n; i++) {
        cout << i << " : ";
        for (int j = 0; j < edg[i].size(); j++) {
            cout << "{" << i/*edg[i][j].s*/ << "-->" << edg[i][j].e << ", " << edg[i][j].v << "} ";
        }
        cout << endl;
    }
    return 0;
}
