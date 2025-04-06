//中位数 是有序整数列表中的中间值。如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值。 
//
// 例如， [2,3,4] 的中位数是 3 [2,3] 的中位数是 (2 + 3) / 2 = 2.5 设计一个支持以下两种操作的数据结构： 
//
// 
// void addNum(int num) - 从数据流中添加一个整数到数据结构中。 
// double findMedian() - 返回目前所有元素的中位数。 
// 
//
// 示例 1： 
//
// 
//输入：
//["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
//[[],[1],[2],[],[3],[]]
//输出：[null,null,null,1.50000,null,2.00000]
// 
//
// 示例 2： 
//
// 
//输入：
//["MedianFinder","addNum","findMedian","addNum","findMedian"]
//[[],[2],[],[3],[]]
//输出：[null,null,2.00000,null,2.50000] 
//
// 
//
// 提示： 
//
// 
// 最多会对 addNum、findMedian 进行 50000 次调用。 
// 
//
// 注意：本题与主站 295 题相同：https://leetcode-cn.com/problems/find-median-from-data-
//stream/ 
//
// 
//
// Related Topics 设计 双指针 数据流 排序 堆（优先队列） 👍 477 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class MedianFinder {
public:
    /** initialize your data structure here. */

    //两个优先队列
    priority_queue<int, vector<int>, less<int>> maxHeap; //大顶堆 存储较小的一半
    priority_queue<int, vector<int>, greater<int>> minHeap; //小顶堆 存储较大的一半

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int m = minHeap.size();
        int n = maxHeap.size();
        if(m == n){
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }else{
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (minHeap.size() != maxHeap.size()) {
            return minHeap.top();
        } else {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
//leetcode submit region end(Prohibit modification and deletion)
