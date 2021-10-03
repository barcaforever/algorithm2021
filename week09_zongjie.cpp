// 本周总结

// 学完了LRU,排序和高级动规；重新复习了下散列表和链表的相关特性；
// 排序 实现了 快速排序和归并排序。
// 继续复习动规的题目，以及前面的内容。重点是跟树有关的算法实现，如dfs,bfs，trie树实现等，查询搜索时树与散列表，链表以及组合起来的高级树的相应的效率和性能对比。


// 快速排序
#include<iostream>
using namespace std;

//选择基准（轴）
int partition(int array[], int low, int high)
{
    while (low < high) 
    {   //low位置为轴点，low右边的不小于low左边的
        while (low < high && array[low] <= array[high])
        {
            high --;
        }
        int tmp = array[low];
        array[low] = array[high];
        array[high] = tmp;

        //high位置为轴点，high左边的不大于high右边的
        while (low < high && array[low] <= array[high])
        {
            low ++;
        }
        tmp = array[low];
        array[low] = array[high];
        array[high] = tmp;

    }
    return low;
}

void quickSortHelp(int array[], int low, int high)
{
    if (low < high)
    {
        int loc = partition(array, low, high)//找枢轴元位置
        quickSortHelp(array, low, loc - 1);
        quickSortHelp(array, loc + 1, high);

    }
}

void quickSort(int array[], int n)
{
    quickSortHelp(array, 0, n - 1);//以第一个数组元素为基准（轴）
}


// 归并排序
void Merge(int array[], int l, int q, int r) {
    int n = r-l+1; // 临时数组存合并后的有序序列
    int *tmp = new int[n];
    int i = 0;
    int left = l;
    int right = q + 1;

    while (left <= q && right <= r) {
        tmp[i++] = array[left] <= array[right] ? array[left++]:array[right++];
    }
    while (left <= q) {
        tmp[i++] = array[left++];
    }
    while (right <= r) {
        tmp[i++] = array[right++];
    }

    for (int j = 0; j < n; j++) {
        array[l + j] = tmp[j];
    }

    delete [] tmp; // 删掉堆里的内存
}

void MergeSort(int array[], int l, int r) {
    if (l == r) return ;
    int q = (l + r) / 2;
    MergeSort(array, l , q);
    MergeSort(array, q + 1, r);
    Merge(array, l  , q, r);
}
