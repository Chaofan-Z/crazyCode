#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// n���������飬��ǰmС
// ��С�ѣ��Ѷ�Ԫ��ȡ����ʱ��Ҫ֪�����������ĸ�����
// ���ܸ�����ȡ���ˣ�����ѭ������
struct node{
    int value;
    int vectorNum;
};
// С����
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
