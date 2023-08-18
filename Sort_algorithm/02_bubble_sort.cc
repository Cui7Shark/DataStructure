/*   冒泡排序 -- 稳定的
    比较相邻两个元素，大的往后放，小的放前面, 相等的两个不会交换
    相同元素的前后顺序并没有改变，所以冒泡排序是一种稳定排序算法。
    
    1.比较相邻的元素。如果第一个比第二个大，就交换他们两个。
    2.对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。
      这步做完后，最后的元素会是最大的数。
    3.针对所有的元素重复以上的步骤，除了最后一个。
    4.持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。

    时间复杂度 O(n^2)
*/
#include <iostream>
#include <vector>
void bubbleSort(std::vector<int> &num) {
    int len = num.size();
    bool flag = false;
    for (int i = 0; i < len-1; ++i) {
        flag = false;
        for (int j = 0; j < len-1-i; ++j) {
            if (num[j] > num[j+1]) {
                std::swap(num[j], num[j+1]);
                flag = true;
            }
        }

        if (!flag) break;
    }

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
    bubbleSort(num);
    Print(num);

    return 0;
}