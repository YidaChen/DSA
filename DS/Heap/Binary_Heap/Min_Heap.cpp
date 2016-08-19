#include <stdio.h>
#include <malloc.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

class MinHeap {
    
    int capacity;
    int *arr;
public:
    int size;
    MinHeap(int capacity){
        this->capacity = capacity;
        size = 0;
        arr = (int*)malloc(sizeof(int)*capacity);
    }
    int parent(int i){ return (i-1)/2; }
    int left(int i){ return 2*i+1; }
    int right(int i){ return 2*i+2; }
    
    void heapifyUp(int i){
        
        int p = parent(i);
        
        while(i > 0 && arr[i] < arr[p]){
            
            swap(&arr[i], &arr[p]);
            i = p;
            p = parent(i);
        }
    }
    
    void insert(int key){
        
        if(size == capacity) return;
        
        int i = size++;
        arr[i] = key;
        
        heapifyUp(i);
    }
    
    void heapifyDown(int i){
        
        int l = left(i);
        
        while(l < size){
            
            if(arr[l] > arr[l+1] && l+1 < size){ //find min child
                l++;    
            }
            if(arr[i] <= arr[l]) return;
            
            swap(&arr[i], &arr[l]);
            i = l;
            l = left(i);
        }
    }
    
    int remove(int index){
        
        if(size == 0) return NULL;
        
        int item = arr[index];
        
        arr[index] = arr[--size];
        heapifyDown(index);
        
        return item;
    }
    
    int extract(){ return remove(0); }
};

int main(){
   
    MinHeap h(11);
    h.insert(3);
    h.insert(2);
    h.remove(1);
    h.insert(15);
    h.insert(5);
    h.insert(45);

    while(h.size > 0){
        printf("%d ", h.extract());
    }
}