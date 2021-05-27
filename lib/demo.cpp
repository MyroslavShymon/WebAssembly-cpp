#include <stdio.h>
#include <iostream>
#define NUM_VALS 8
using namespace std;

extern "C" {
    int getNUM();
    int* bubbleSort2(int arr[], int n);
    float sum_up(float vals[], int size);
    int sumArrayInt32 (int *array, int length);
    int sum();
    int* getOffset();
}

 
int numbers[NUM_VALS];
 
int sum()
{
    int result = 0;
   
    for(int i=0; i < NUM_VALS; i++) {
        result += numbers[i];
    }
    return result;
}
 
int* getOffset() {
  return &numbers[0]; 
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)    
     
    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}

int* bubbleSort2(int arr[], int n)
{
    int arr2[1] = {4};
    // cout << "arr= "<<arr << "n= "<< n;
    cout<<"bubbleSort2";
    return arr2;
}


int getNUM(){
    return 32;
}
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
float sum_up(float vals[], int size) {
    cout<<"array sended is = "<<vals<<"\n";
  float res = 0;
  for(int i=0; i<size; i++)
    res += vals[i];
  return res;
}

int sumArrayInt32 (int *array, int length) {
    int total = 0;

    for (int i = 0; i < length; ++i) {
        total += array[i];
    }

    return total;
}

float addNums (float *buffer, int bufSize) {
    float total = 0;

    for (int i=0; i<bufSize; i++) {
        total+= buffer[i];
    }

    return total;
}

int main() {
 float vals[] = {1., 2., 3.};
float res_val = sum_up(vals, 3);
cout<<"res_val"<<res_val<<"\n";
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    cout<<"Sorted array: \n";
    printArray(arr, n);
    return 0;
}