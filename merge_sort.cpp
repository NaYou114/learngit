#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;
// 对merge过程进行改造即可变为小和问题的求解
void merge(vector<int> &a, int l, int mid, int r){
    int *temp = new int[r - l + 1];
    int idx = 0;
    int i = l;
    int j = mid+1;
    while(i<=mid && j<=r){
        if (a[i]<=a[j]){
            temp[idx++] = a[i];
            i++;
        }
        else{
            temp[idx++] = a[j];
            j++;
        }   
    }
    while(i<=mid){
        temp[idx++] = a[i++];
    }
    while(j<=r){
        temp[idx++] = a[j++];
    }
    for (int i = 0; i < r - l + 1;i++){
        a[l + i] = temp[i];
    }
    delete[] temp;
} 
void mergeSort(vector<int> &a, int l, int r)
{
    if (l>=r){
        return;
    }
    int mid = l+((r-l)>>1);   // l+ (r-l)>>1; 防止l+r溢出  +-的优先级高于>>
    //int mid = l + (r - l) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    merge(a, l,mid, r);
}
void merge_sort(vector<int> &a)
{
    if(a.size()<2){
        return;
    }
    mergeSort(a, 0, a.size() - 1);
}

int main(){
    vector<int> a;
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    merge_sort(a);
    for (int i = 0; i < a.size();i++){
        cout << a[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}