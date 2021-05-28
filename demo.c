#include <stdio.h>
// #include <iostream>
#include <emscripten.h>
// using namespace std;

// extern "C" {
//     int getNUM(int num);
//     int addTwoInts (int a, int b);
//     int* Func(int* Array, int size);
//     void addOne(int* input_ptr, int* output_ptr, int len);
// }

// int* Func(int* Array, int size)
// {
//     cout<<"Array"<<Array<<"\n";
//     int *new_array = new int[size];
//     for(int i = 0; i < size; i++) {
//         cout<<"Array[i] = "<<Array[i]<<"\t"<< i <<"\t" << size <<"\n";
//         new_array[i] = Array[i] + 1;
//     }
//     return new_array;
// }

// int addTwoInts (int a, int b) {
//     return a + b;
// }

void addOne(int* input_ptr, int* output_ptr, int len){
	int i;
	for(i = 0; i < len; i++)
    	output_ptr[i] = input_ptr[i] + 1;
}

int getNUM(int num){
    return num+1;
}

int main() {
    return 0;
}