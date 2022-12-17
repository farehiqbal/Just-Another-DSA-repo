// log n insertion & deletion complexity, because it takes time to swap, the number of swaps depend on height of tree.
// the height is log n. Thus O(1) - O(log n).

// 3 applications.
// heapsort, mst, priority qeuue.

// i- 1 / 2 gives paren node.
// 2*i + 1 gives left child
// 2*i + 2 gives rght child.



#include <iostream>

using namespace std;

class MinHeap{
    public:
    int* heap;
    int size;
    int capacity;

    MinHeap(int _capacity){

        heap = new int[_capacity];
        capacity = _capacity;
        size = 0;
    }

    void swap(int* i, int* j){
        
        int temp = *i;
        *i = *j;
        *j= temp;
        
    }

    void printHeap(){
        for (int i = 0; i < size; i++){
            cout << heap[i] << " ";
        }
        cout << endl;
        
    }

    int parent(int index){
        return (index - 1) / 2;
    }

    int leftChild(int index){
        return (2* index + 1);
    }

    int rightChild(int index){
        return (2 * index + 2);
    }

    int LinearSearch(int key){
        
        int i = 0;
        
        for (; i < size; i++)
        {
            if(heap[i] == key) return i;
        }

        return -1;
        
    }

    void deleteByValue(int key){

        int index = LinearSearch(key);

        deleteByIndex(index);
    }

    void deleteByIndex(int index){
        
        heap[index] = -1;
        while(index != 0 && heap[parent(index) > heap[index]]){
            swap(&heap[index], &heap[parent(index)]);
            index = parent(index);
        }

        removeMin();

    }

    void insert(int key){
        
        // case : when heap is full
        if(size == capacity){
            cout <<"Heap overflow";
            return;
        }

        // inserting simply at the end of heap. Insert from left ro right to keep the property
        // of complete binary tree.

        size++;
        int index = size - 1;
        heap[index] = key;

        // now lets keep the min heap unviolated (if it was violated).

        while(index != 0 && heap[parent(index) > heap[index]]){

            swap(&heap[index], &heap[parent(index)]);
            index = parent(index);
        } 
    }

    // This method simply reforms the binary tree, after it has been distorted due to some operations.
    void MinHeapify(int index){

        int left = leftChild(index);
        int right = rightChild(index);
        int smallest = index;
       
        if (left < size && heap[left] < heap[index])
        smallest = left;
       
        if (right < size && heap[right] < heap[smallest])
        smallest = right;
       
        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            MinHeapify(smallest);
        }
    }


    // function that returns the minimum element(root) in heap & reforms min-heap.

    int removeMin(){
        
        // no element
        if(size <= 0) return -1;

        // one one element
        if(size == 1){
            size--;
            return heap[0];
        }

        // if there is more than 1 element, remove and reform (heapify) the tree.
        int min = heap[0]; // root
        heap[0] = heap[size - 1];
        size--;
        MinHeapify(0);

        return min;
    }

    // There are two ways to store the sorted value.
    // 1. Either make new array and keep storing the deleted values.
    // 2. Place the newly deleted value at the end of the same array, since the lsat value is duplicate.
    void heapSort(){
        
        int temp[capacity];
        for (int i = 0; i < capacity; i++)
        {
            temp[i] = removeMin();
            cout << temp[i] << " ";
        }
        
    }

    void heapSortV2(){

    }


    
};

int main(){

    MinHeap heap(7);

    heap.insert(5);
    heap.insert(8);
    heap.insert(2);
    heap.insert(7);
    heap.insert(10);
    heap.insert(1);

    heap.printHeap();
    // cout << heap.LinearSearch(2);

    cout << heap.removeMin();
    cout << heap.removeMin();
    // heap.heapSort();
}