#include <iostream>
#include <queue>
using namespace std;
struct node{
    int value;
    int vectorNum;
};
struct cmp
{
    bool operator()(node& a, node& b){ return a.value > b.value;}
};
vector<int> getMinM(vector<vector<int> > nums, int m){
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

void merge(vector<int> &nums, int start, int end){
    // merge start end
    // 其中start - mid 有序
    //    mid + 1 end 有序
    int mid = (start + end) / 2;
    // mid 可能和 start  end相同

    vector<int> temp;
    int left = start;
    int right = mid + 1;

    while(temp.size() != (end - start + 1)){
        if(left <= mid && right <= end){
            if(nums[left] < nums[right]){
                temp.push_back(nums[left]);
                left ++;
            }
            else{
                temp.push_back(nums[right]);
                right ++;
            }
        }
        else{
            if(left <= mid){
                temp.push_back(nums[left]);
                left ++;
            }
            else{
                temp.push_back(nums[right]);
                right ++;
            }
        }
    }

    for(int i=start; i<=end; i++){
        nums[i] = temp[i - start];
    }


}
// end  = size - 1
void mergeSort(vector<int> &nums, int start, int end){
    // 偶数个数字
    // 0 3  mid = 1
    // 如果不是mid - 1; mid + 1 会遇到start or end == mid 的情况
    int mid = (start + end) / 2;

    if(start >= end){
        return;
    }

    // mid 最后会和start or end相同
//    int mid = (start + end) / 2;
    mergeSort(nums, start, mid);
    mergeSort(nums, mid + 1, end);

    merge(nums, start, end);

}



int binarySearch(vector<int> &nums, int start, int end, int target){
    int mid = (start + end) / 2;
    cout << "start : " << start << " end : " << end << endl;
    cout << "mid : " << mid << endl;

    if(target == nums[mid]){
        return mid;
    }

    if(start + 1 == end){
        if(nums[start] == target){
            return start;
        }
        if(nums[end] == target){
            return end;
        }
        return -1;
    }
    if(nums[mid] > target){
        return binarySearch(nums, start, mid, target);
    }

    return binarySearch(nums, mid + 1, end, target);

}

void printVector(vector<int> &nums){
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}
int main() {

//    getMinM 函数测试
//    vector<vector<int> > test = {
//            {1, 3, 5, 7},
//            {1, 2, 4, 8},
//            {0, 10, 12}
//    };
//    vector<int> res = getMinM(test, 11);
//    for(int i=0 ;i<res.size(); i++){
//        cout << res[i] << " ";
//    }
//    cout << endl;
//
//
    vector<int> nums = {0, 11, 13, 15, 3, 5, 7, 8, };

    mergeSort(nums, 0, nums.size() - 1);
    printVector(nums);
//    cout << binarySearch(nums, 0, nums.size() - 1, 8);
    return 0;
}
