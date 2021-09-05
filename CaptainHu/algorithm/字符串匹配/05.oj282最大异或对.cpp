/*************************************************************************
	> File Name: 05.oj282最大异或对.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Tue 23 Feb 2021 05:32:00 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 100000
#define BASE 31
struct Node {
    Node *next[2];
} tree[MAX_N * BASE + 5];
int cnt = 0;

Node *getNode() {
    return &tree[cnt++];
}

void insert(Node *root, int x) {
    for (int i = 30; i >= 0; i--) {
        int ind = !!(x & (1 << i));
        if (root->next[ind] == NULL) root->next[ind] = getNode();
        root = root->next[ind];
    }
    return ;
}

int query(Node *root, int x) {
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
        int ind = !(x & (1 << i));
        if (root->next[ind]) {
            ans |= (1 << i);
            root = root->next[ind];
        } else {
            root = root->next[!ind];
        }
    }
    return ans;
}

int n;
int val[MAX_N + 5];

int main() {
    cin >> n;
    int ans = 0, a;
    Node *root = getNode();
    cin >> a, n--;
    insert(root, a);
    while (n--) {
        cin >> a;
        ans = max(query(root, a), ans);
        insert(root, a);
    }
    cout << ans << endl;
    return 0;
}
