#include <iostream>

using namespace std;

int search(int arr[], int target, int start, int end){

    if (start > end){
        return -1;
    }

    int mid = (start + end) / 2;

    if (arr[mid] == target){
        return mid; 
    }

    if(target < arr[mid]){
        return search(arr, target, start, mid-1);
    }

    return search(arr, target, mid+1, end);
}


int main(){

    int arr = {1};

    cout << search(&arr, 1, 0, 4);
}