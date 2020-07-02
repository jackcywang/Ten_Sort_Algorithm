#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Insert_Sort(vector<int>&);

int main()
{
    vector<int> arr = {2,3,6,1,4,7,5,9};
    Insert_Sort(arr);
    for(int i=0; i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

//直接插入排序算法,它是一个插入排序,就是从一个未排序的序列中取出关键字逐个插入到已经排序好的序列中。
//从头到尾依次扫描未排序序列，将扫描到的每个元素插入有序序列的适当位置。（如果待插入的元素与有序序列
//中的某个元素相等，则将待插入元素插入到相等元素的后面。）
void Insert_Sort(vector<int>& m_list){
    for(int i=1;i<m_list.size();i++){
        int key = m_list[i];
        int j=i-1;
        while (j>=0 && m_list[j]>=key)
        {
            m_list[j+1]=m_list[j];
            j--;
        }
        m_list[j+1] = key;
    }
}

//分析：最好情况下待排序序列是有序的,那么下面的循环也就不会执行,比较次数为n-1次,时间复杂度为O(n),最坏情况下待排序
//序列是逆序的，则比较次数为1+2+3+...+n-1=n(n-1)/2，时间复杂度为O(n^2),平均时间复杂度为O(n^2).

