// 快速排序实现
// 1. 选取一个哨兵，一般选第一个数
// 2. 把比哨兵小的数放到前面， 比哨兵大的数放到后面 分为了两个区间
// 3. 对左右区间重复上一步，直到各区间只有一个数
#include <iostream>
#include <vector>

void quickSort(std::vector<int>& num, int begin, int end) {
    if (begin > end) return;
    int l = begin;
    int r = end;
    int key = num[l]; // 哨兵

    while (l < r) {
        // 从后向前走
        while (l < r && num[r] >= key) {
            r--;
        }
        if (l < r) {
            num[l++] = num[r];
        }
        // 从前向后走
        while (l < r && num[l] <= key) {
            l++;
        }
        if (l < r) {
            num[r--] = num[l];
        }
    }
    // 填坑
    num[l] = key;
    // 递归
    quickSort(num, begin, l-1);   // 注意是以本次的l为基准分区间的 
    quickSort(num, l+1, end);   


}


void Print(const std::vector<int> &num) {
    std::cout << "num is : "; 
    for(auto it : num) {
        std::cout << it << " "; 
    }
    std::cout << std::endl;

}   

int main() {
    std::vector<int> num = {1,1,4,5,1,4};
    Print(num);
    quickSort(num, 0, num.size()-1);
    Print(num);

    return 0;

}