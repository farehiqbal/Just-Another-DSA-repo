#include <iostream>

using namespace std;

template <typename T, std::size_t N>
std::size_t getArraySize(T (&)[N])
{
    return N;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;

}

void printArray(int *array, int length){


    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    
    cout << endl;
}

void combine(int a[], int s, int m, int e)
{
  int* buffer = new int [e+1]; //for the total size of the merged array

  int k = s;
  while(k<=e)
  {
    buffer[k] = a[k];
    k = k+1;
  }

  int i = s;
  int j = m+1;
  k = s;

  while(i<=m && j<=e)
  {
    if(buffer[i] <= buffer[j])
    {
      a[k] = buffer[i];
      i = i+1;
    }
    else
    {
      a[k] = buffer[j];
      j = j+1;
    }
    k = k+1;
  }

  while(i<=m)
  {
    a[k] = buffer[i];
    i = i+1;
    k = k+1;
  }

  while(j<=e)
  {
    a[k] = buffer[j];
    j = j+1;
    k = k+1;
  }

delete[] buffer;
}
//auxiliary function (helper function)
void mrgSort(int a[], int s, int e)
{
    if(s>=e)
    {
      return;
    }

    int m = (s+e)/2;
    mrgSort(a, s, m);
    mrgSort(a, m+1, e);
    combine(a, s, m, e);
}

void mrgSort(int a[], int n) //wrapper function
{
  mrgSort(a, 0, n-1);
}

void insertIth(int a[], int n, int i)
{
  int key = a[i];
  int j = i-1;
  while(j>=0 && a[j]>key)
  {
    a[j+1] = a[j];
    j = j-1;
  }
  a[j+1] = key;
}

void insSort(int a[], int n)
{
  int i = 1;
  while(i<n)
  {
    insertIth(a, n, i);
    i++; //i=i+1;
  }
}

void bubble(int a[], int n)
{
  int i = n-1;
  while(i>0)
  {
    if(a[i]<a[i-1])
    {
      swap(a[i], a[i-1]);
    }
    i--;
  }

}



void bblSort(int a[], int n)
{
  int i = 0;
  while(i<n-1)
  {
    bubble(a, n);
    i++;
  }

}

void bubbleSort(int array[], int size){

    for (int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - 1;j++){

            if(array[j] > array[j+1]){
                swap(array[j], array[j+1]);
            }
        }
    }
    
}


int getSmallest(int array[], int start, int end){
      
    int i = start;
    int j = i;

    while(i <= end){

        if(array[i] < array[j]){
            j = i;
        }

        i++;
    }

    return j;
}


void selectionSort(int array[], int size){

    int currMin = 0; // lets always start with index 0;

    while (currMin < size - 1)
    {
        int smallest = getSmallest(array, currMin, size - 1);
        if(array[currMin] > array[smallest]) swap(array[currMin], array[smallest]);
        currMin++;
    }
    
}

void simpleSorting(int *array, int length){

    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if(array[j] < array[i]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        
    }

    
}





int main(){

    int arr[5] = {9,8,7,6,5};
    // simpleSorting(arr,5);
    selectionSort(arr, 5); 
    // bubbleSort(arr, 5);
    // bblSort(arr, 5);
    // insSort(arr, 5);
    // mrgSort(arr,5);
    printArray(arr, 5);
}