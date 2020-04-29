#include <iostream>
#include <windows.h>

using namespace std;
void swap(int *a , int x, int y){
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}
int* partision(int *a, int left, int right){
    int x = left - 1;
    int y = right + 1;
    int num = a[left];
    while(left < y){
        if(a[left]<num){
            x++;
            swap(a, left, x);
            left++;
        }
        else if(a[left]>num){
            y--;
            swap(a, left, y);
        }
        else{
            left++;
        }
    }
    return new int[2]{x, y};
}
void quickSort(int *a, int left, int right){
    if(left>=right){
        return;
    }
    // srand()
    // swap(a, right, rand()%(right-left+1)+left)
    int *p = partision(a, left, right);
    quickSort(a, left, p[0]);
    quickSort(a, p[1], right);
    delete[] p;
}

int main()
{
    int a[100] = {0};
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}