#include <iostream>
#include <vector>
using namespace std;
void mergeSort(vector<int> &num, vector<int> &temp, int left, int right)
{
    
    if (left >= right)
        return;
    // 递归的划分左右区间
    int mid = left + (right - left) / 2;
    mergeSort(num, temp, left, mid);
    mergeSort(num, temp, mid + 1, right);
    // 对左右区间进行排序
    // 标记左半区间的第一个下标
    int l_pos = left;
    // 标记右半区间的第一个下标
    int r_pos = mid + 1;
    // 标记临时数组的下标, 从left区间的第一个下标开始算
    int pos = left; 
    while (l_pos <= mid && r_pos <= right)
    {
        if (num[l_pos] < num[r_pos]) 
        {
            temp[pos++] = num[l_pos++];
        } else
        {
            temp[pos++] = num[r_pos++];
        }
    }
    // 左半区的元素还有剩余,直接放到temp
    while(l_pos <= mid)
    {
        temp[pos++] = num[l_pos++];
    }
    // 右半区的元素还有剩余,直接放到temp
    while (r_pos <= right)
    {
        temp[pos++] = num[r_pos++];
    }

    //把临时数组temp的元素拷贝到num中
    while(left <= right)
    {
        num[left] = temp[left];
        left++;
    }
    

}

void Print(const vector<int> &num)
{   
    cout << "num : ";
    for(int i = 0; i < num.size(); i++)
    {
        cout << num[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> num = {4, 1, 3, 4, 6, 0};
    Print(num);
    vector<int> temp(num.size(), 0);
    int len = num.size();
    mergeSort(num, temp, 0, len - 1);
    Print(num);
    return 0;
}