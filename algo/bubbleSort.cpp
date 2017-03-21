
#include <iostream>

using namespace std;                                           //此句也可以在main函数体中出现。
void print(int a[], int n){  
    for(int j= 0; j<n; j++){  
        cout<<a[j] <<"  ";  
    }  
    cout<<endl;  
}  
  
  
// 传统
void bubbleSort(int a[], int n){  
    for(int i =0 ; i< n-1; ++i) {  
        for(int j = 0; j < n-i-1; ++j) {  
            if(a[j] > a[j+1])  
            {  
                int tmp = a[j] ; a[j] = a[j+1] ;  a[j+1] = tmp;  
            }  
        }  
    }  
}  

// 改进
void Bubble_1 ( int r[], int n) {  
    int i= n -1;  //初始时,最后位置保持不变  
    while ( i> 0) {   
        int pos= 0; //每趟开始时,无记录交换  
        for (int j= 0; j< i; j++)  
            if (r[j]> r[j+1]) {  
                pos= j; //记录交换的位置   
                int tmp = r[j]; r[j]=r[j+1];r[j+1]=tmp;  
            }   
        i= pos; //为下一趟排序作准备  
     }   
}    

// 改进
void Bubble_2 ( int r[], int n){  
    int low = 0;   
    int high= n -1; //设置变量的初始值  
    int tmp,j;  
    while (low < high) {  
        for (j= low; j< high; ++j) //正向冒泡,找到最大者  
            if (r[j]> r[j+1]) {  
                tmp = r[j]; r[j]=r[j+1];r[j+1]=tmp;  
            }   
        --high;                 //修改high值, 前移一位  
        for ( j=high; j>low; --j) //反向冒泡,找到最小者  
            if (r[j]<r[j-1]) {  
                tmp = r[j]; r[j]=r[j-1];r[j-1]=tmp;  
            }  
        ++low;                  //修改low值,后移一位  
    }   
}   
  
int main(){  
    cout<<"元素个数：";
    int arrayCount;
    cin>>arrayCount;
    int b[arrayCount];
    for(int i = 0;i < arrayCount;i++)
    {
        cout<<"输入第"<<i+1<<"个值：";
        cin>>b[i];
        cout<<endl;
    }
    print(b,arrayCount);  
    Bubble_2(b,arrayCount);  
    cout<<"结果：";  
    print(b,arrayCount);  
  
}  