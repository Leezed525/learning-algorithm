//
// Created by Leezed on 2024/9/21.
// 目前仅针对int类型来实现一个维护列表
// 会维持一个有序的列表
//
#include <functional>
#include "vector"
#include "algorithm"
#include "iostream"
#include "iterator"

using std::begin;
using std::end;

class MaintainVector {
private:
    std::vector<int> data;
    bool ig = true;
public:
    int getLength() {
        return (int) data.size();
    }

    MaintainVector() {
        data.clear();
    }

    MaintainVector(int *a, int len, bool is_greater = true) : ig(is_greater) {
        data = std::vector<int>(a, a + len);
        if (is_greater) { //升序排序
            std::sort(data.begin(), data.end());
        } else { //降序排序
            std::sort(data.begin(), data.end(), [](int a, int b) {
                return a > b;
            });
        }
    }

    //二分查找
    int search(int target) {
        int left = 0, right = getLength();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (data[mid] == target) {
                return mid;
            } else if (data[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return -1;
    }

    //二分插入
    void insert(int target) {
        int left = 0, right = getLength();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (data[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        data.insert(data.begin() + left, target);
    }

    //删除
    void remove(int target) {
        int index = search(target);
        if (index != -1) {
            data.erase(data.begin() + index);
        }
    }

    void print_data() {
        for (int i = 0; i < data.size(); i += 1) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    int tmp[] = {1, 9, 8, 7, 5, 3, 4, 5, 6};
    MaintainVector list = MaintainVector(tmp, 9);
    list.print_data();
    return 0;
}
