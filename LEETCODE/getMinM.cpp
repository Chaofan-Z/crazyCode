#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// n个升序数组，求前m小
// 最小堆，堆顶元素取出来时候要知道其是来自哪个数组
// 可能该数组取完了，继续循环即可
struct node{
    int value;
    int vectorNum;
};
// 小顶堆
struct cmp
{
    bool operator()(node& a, node& b){ return a.value > b.value;}
};
vector<int> getMinM(vector<vector<int>> nums, int m){
    priority_queue<node, vector<node>, cmp> heap;
    vector<int> idxVec;

    for(int i=0; i<nums.size(); i++){
        node a = {nums[i][0], i};
        heap.push(a);
        idxVec.push_back(0);
    }

    vector<int> res;
    while(res.size() < m){
        node top = heap.top();
        heap.pop();
        res.push_back(top.value);

        idxVec[top.vectorNum] += 1;

        if(idxVec[top.vectorNum] >= nums[top.vectorNum].size()){
            continue;
        }

        node now = {nums[top.vectorNum][idxVec[top.vectorNum]], top.vectorNum};

        heap.push(now);
    }
    return res;
}
int main() {
    vector<vector<int>> test = {
            {1, 3, 5, 7},
            {1, 2, 4, 8},
            {0, 10, 12}
    };
    vector<int> res = getMinM(test, 11);
    for(int i=0 ;i<res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
