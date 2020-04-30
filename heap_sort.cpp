#include <iostream>
#include <algorithm>

using namespace std;

void swap(int *a, int i, int j){
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
void heapInsert(int *a, int index){
    while(a[index]>a[(index-1)/2]){
        swap(a, index, (index - 1) / 2);
        index = (index - 1) / 2;
    }
}
void heapify(int *a, int index, int heapsize){
    int left = index * 2 + 1;
    while(left<heapsize){
        int larget = (left + 1) < heapsize && a[left + 1] > a[left] ? left + 1 : left;
        larget = a[larget] > a[index] ? larget : index;
        if(larget == index){
            break;
        }
        swap(a, larget, index);
        index = larget;
        left = index * 2 + 1;
    }
}
void heap_sort(int * a, int n){
    if (n<2){
        return;
    }
    for (int i = 0; i < n;i++){  // o(n)
        heapInsert(a, i);
    }
    for (int i = n-1; i >0;i--){   // o(nlgn)
        swap(a, 0, i);
        heapify(a, 0, i);
    }
}
int main(){
    int a[20];
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    make_heap(a, a+n, greater<int>());  //建堆, 在于比较器
    for (int i = 0; i < n;i++){  
        cout << a[i] << " ";
    }
    a[n] = 12;
    push_heap(a, a+n + 1);
    for (int i = 0; i < n+1;i++){   
        cout << a[i] << " ";
    }
    pop_heap(a, a + n + 1);

    //heap_sort(a, n);
    for (int i = 0; i < n+1;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}