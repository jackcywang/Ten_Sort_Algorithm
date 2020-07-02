#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void SelectSort(vector<int>&);

int main()
{
    vector<int> arr = {2,3,6,1,4,7,5,9}; 
    SelectSort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }   
    return 0;
}


//定义：简单选择排序算法是从未排序的序列中，每次选择最小的一位排在前面。
void SelectSort(vector<int>& m_list){
    int i,j,min;
    for(i=0; i < m_list.size(); i++){
        min=i;
        for(j=i+1;j<m_list.size();j++){
            if(m_list[j]<m_list[min]){
                min = j;
            }
        }
        if(i != min){
            swap(m_list[i],m_list[min]);
        }
    }
}

//分析：简单选择排序的最大特点是交换移动次数相当少，这样也就节约了相应的时间,无论最好最坏情况，比较次数都是一样多的，
//比较次数为n-1+n-2+...+2+1 = n(n-1)/2,交换次数最好情况下是0次，最坏情况是n-1次,最好时间复杂度为O(n^2),最坏时间
//复杂度为O(n^2),平均时间复杂度也为O(n^2)