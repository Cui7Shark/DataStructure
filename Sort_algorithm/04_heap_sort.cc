#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &tree, int n, int i)
{   
    //递归出口
    if (i >= n)
        return;

    int c1 = 2 * i + 1; // 一个根节点i的左子节点
    int c2 = 2 * i + 2; // 一个根节点i的左子节点
    int max = i;        
    if (c1 < n && tree[c1] > tree[max])
    {
        max = c1;
    }
    if (c2 < n && tree[c2] > tree[max])
    {
        max = c2;
    }
    if (max != i)
    {
        // 移动最大的值到根节点
        swap(tree[max], tree[i]);
        heapify(tree, n, max);
    }
}

void heapify_build(vector<int> &tree, int n)
{
    int last_node = n - 1; // 找到最后一个节点
    int parent = (last_node - 1) / 2; // 根据公式（parent=(i-1)/2）找到其父节点
    for (int i = parent; i >= 0; i--) // 从最后一层的父节点，由下至上进行heapify
    {
        heapify(tree, n, i);
    }
}

void heap_sort(vector<int> &tree, int n)
{
    // 构建大根堆
    heapify_build(tree, n); 
    for (int i = n - 1; i >= 0; i--)
    {   
        //根节点与最后一个节点交换
        swap(tree[i], tree[0]);
        //把最后一个节点砍掉， 用i控制堆的节点个数，进行下一次heapify
        heapify(tree, i, 0);
    }
}
void Print(vector<int> &tree, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> tree = {2, 5, 3, 1, 10, 4};
    int n = tree.size();
    heap_sort(tree, n); // 堆排序入口
    Print(tree, n);
    return 0;
}