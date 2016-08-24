#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define length(arr) (sizeof(arr)/sizeof(arr[0]))
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int arr[], int len)
{
    int i, j;
    bool swaped;
    for(i = 0; i < len - 1; i++)
    {
        swaped = false;
        for(j = 0; j < len - 1 - i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                swaped = true;
            }
        }
        if(!swaped)  break;
    }
}
void selectionSort(int arr[], int len)
{
    int i, j, minIndex;
    
    for(i = 0; i < len - 1; i++)
    {
        minIndex = i;
        for(j = i + 1; j < len; j++)
            if(arr[j] < arr[minIndex])
                minIndex = j;
                
        if(minIndex != i) 
            swap(&arr[minIndex], &arr[i]);
    }
}
void insertionSort(int arr[], int len)
{
    int i, j, insert;
    
    for(i = 1; i < len; i++)
    {
        insert = arr[i];
        j = i;
        
        while(j > 0 && arr[j-1] > insert)
        {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = insert;
    }
}
void binaryInsertionSort(int arr[], int len)
{ }
void merge(int arr[], int l, int m, int r)
{
    int lIdx, rIdx;
    
    int lLen = m - l + 1;
    int rLen = r - m;
    
    int L[lLen], R[rLen];
    
    for(lIdx = 0; lIdx < lLen; lIdx++)
        L[lIdx] = arr[l + lIdx];
        
    for(rIdx = 0; rIdx < rLen; rIdx++)
        R[rIdx] = arr[m + rIdx + 1];
        
    lIdx = rIdx = 0;
    
    while (lIdx < lLen && rIdx < rLen)
    {
        if (L[lIdx] <= R[rIdx])
            arr[l] = L[lIdx++];
        else
            arr[l] = R[rIdx++];
        l++;    
    }
    while (lIdx < lLen)
        arr[l++] = L[lIdx++];
    while (rIdx < rLen)
        arr[l++] = R[rIdx++];    
}
void mergeSort(int arr[], int l, int r)
{
    if(l == r) return;
    
    int m = (l+r)/2;
    
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    
    merge(arr, l, m, r);
}
int partition(int arr[],int l,int r)
{
    int pivot = arr[r];
    
    for(int i = l; i < r; i++)
    {
        if(arr[i] <= pivot)
        {
            swap(&arr[i], &arr[l]);
            l++;
        }
    }
    swap(&arr[r], &arr[l]);
    return l;
}
void quickSort(int arr[], int l, int r)
{
    if(l >= r) return;
    
    int p = partition(arr, l, r);
    
    quickSort(arr, l, p - 1);
    quickSort(arr, p + 1, r);
}
void maxHeapifyDown(int arr[], int p, int len)
{
    int l = 2 * p + 1;
    
    while(l < len)
    {
        if(arr[l] < arr[l+1] && l+1 < len) //find max child
            l++;
        if(arr[p] > arr[l])
            return;
        
        swap(&arr[p], &arr[l]);
        p = l;
        l = 2 * p + 1;
    }
}
void heapSort(int arr[], int len)
{
    // build Max Heap
    //((len-1)-1)/2, p從最後一個父節點開始調整
    for(int p = len / 2 - 1; p >= 0; p--)
        maxHeapifyDown(arr, p, len);
        
    //swap first(max) to last, HeapifyDown(0, 扣掉last的len)
    for(len; len > 1; len--)
    {
        swap(&arr[0], &arr[len-1]);
        maxHeapifyDown(arr, 0, len-1);
    }
}
//I don't understand countingSort, so I modify it, what is this sort'name?
void countingSort(int arr[], int len, int range)
{
    //int output[len]; 
    int count[range+1];
    memset(count, 0, sizeof(count));
    
    int i;
    for(i = 0; i < len; i++)
        count[arr[i]]++;
    
    for(int j = 0, i = 0; i <= range; i++)
        if(count[i]-- > 0)
            arr[j++] = i--;
}
void printArray(int arr[], int len)
{
    for(int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 20, 1, 1};
    int len = length(arr);
    //heapSort(arr, len);
    //mergeSort(arr, 0, len - 1);
    //quickSort(arr, 0, len - 1);
    
    countingSort(arr, len, 20);
    printArray(arr, len);
}