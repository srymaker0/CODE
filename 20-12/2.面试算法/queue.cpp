/*************************************************************************
	> File Name: queue.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 11 Nov 2020 07:14:43 PM CST
 ************************************************************************/

#include<iostream>
#include <queue>
using namespace std;

struct node {
    int x, y;
};

int main() {
    queue<int> que;
    node a;
    a.x = a.y = 6;
    que.push(a);
    que.push((node){7, 8});
    cout << que.front().x << endl;
   
   /*
    for (int i = 9; i > 4; i--) {
        que.oush(i);
    }
    while(ique.empty()) {
        cout << "que.front() = " << que.front() << "\tque.size() = " que.size << endl;
        que.pop();
    }
    */

    return 0;
}
