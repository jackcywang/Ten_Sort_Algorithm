#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//冒泡排序是一种交换排序，它的基本思想是：两两比较相邻记录的关键字，如果反序则交换，直到没有反序记录为止，如下为
//基本实现
void Bubble_sort(vector<int>& m_list){
    for(int i=0;i<m_list.size()-1;i++){
        for(int j=0; j<m_list.size()-1-i;j++){
            if(m_list[j]>m_list[j+1]){
                swap(m_list[j],m_list[j+1]);
            }
        }
    }
}

//假定排序数组为[2,1,3,4,5,6,7],使用上述算法第一次排序完后已经是有序的，后面依然会不断地比较，改进方法为设置已排序
//标志位,这样避免了已经有序的情况下还做无意义的循环判断
void Bubble_sort_optimize(vector<int>& m_list){
    bool sorted = true; //假定开始是无序的，需要排序
    for(int i=0;i<m_list.size()-1 && sorted;i++){
        sorted = false; //已经排好序了，无需排序
        for(int j=0; j<m_list.size()-1-i;j++){
            if(m_list[j]>m_list[j+1]){
                swap(m_list[j],m_list[j+1]);
                sorted = true; //无序的，需要排序
            }
        }
    }
}

int main()
{
    vector<int> arr = {2,3,6,1,4,7,5,9};   
    Bubble_sort_optimize(arr);
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i]<<" ";
    }
    return 0;
}

//复杂度分析：排序算法的最好情况下是有序的，没有数据需要交换，时间复杂度为O(n),最坏的情况则是完全是逆序的，此时需要比较
//1+2+3+...+(n-1)=n(n-1)/2次,时间复杂度为O(n^2),平均时间复杂度为O(n^2)