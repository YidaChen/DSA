#include <stdio.h>

#define length(arr) (sizeof(arr)/sizeof(arr[0]))

int linearSearch(int arr[], int len, int item)
{
    for(int i = 0; i < len; i++)
        if(item == arr[i])
            return i;
    return -1;
}
int binarySearch_i(int arr[], int l, int r, int item)
{
    while(l <= r)
    {
        int m = (l + r) / 2;
        
        if(item == arr[m]) 
            return m;
        if(item < arr[m])
            r = m - 1;
        else 
            l = m + 1;
    }
    return -1;
}
int binarySearch_r(int arr[], int l, int r, int item)
{
    if(l <= r)
    {
        int m = (l + r) / 2;
        
        if(item == arr[m]) 
            return m;
        if(item < arr[m])
            return binarySearch_r(arr, l, m-1, item);
            
        return binarySearch_r(arr, m+1, r, item);
    }
    return -1;
}
int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int n = length(arr);
    int x = 10;
    int result = binarySearch_r(arr, 0, n-1, x);
    
    printf("%d ", result);
    printf("%d ", linearSearch(arr, n, x));
}