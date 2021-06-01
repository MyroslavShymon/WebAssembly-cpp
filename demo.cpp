#include <stdio.h>
#include <iostream>
#include <string>
#include <emscripten.h>
#include <chrono>
// #include "Demo/Demo/Source.cpp"

using namespace std;

string JSON = "";

extern "C" {
  void addOne(int* input_ptr, int* output_ptr, int len);
  int add(int a);
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 EM_JS(void, setTime,
     (double time), {
		console.log("time bubble sort = ", time);
   		time_bubble = time;
 });

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
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
class Person
{
private:
  string _name;
  int _age;
public:
  Person(string name, int age) {
    _name = name;
    _age = age;
  }
  // Getter
  string name() {
    return _name;
  }
  int age() {
    return _age;
  }
};


EM_JS(char*, returnName, (int i), {
	let super_arr =	["safsd1","zdfsdf2","sdfsd3","dfgdf4","dfg5","dfgghfnhd6","dfbhdgj7"];
	const greetings = super_arr[i];
	const byteCount = (lengthBytesUTF8(greetings) + 1);
	
	const greetingsPointer = _malloc(byteCount);
		stringToUTF8(greetings, greetingsPointer, byteCount);
	
		return greetingsPointer;
});

void addOne(int* input_ptr, int* output_ptr, int len) {
	auto start = chrono::high_resolution_clock::now();
    const char** arr;
    arr = new const char*[len];    
    for(int i = 0; i < len; i++) 
        arr[i] = returnName(i);
 

	JSON="[";
    bubbleSort(input_ptr, len);

    for (int i = 0; i < len; i++) {
      output_ptr[i] = input_ptr[i];
    }
	Person** persons = new Person * [len];
	for (int i = 0; i < len; i++)
    {
		//   string s = "name" + to_string(input_ptr[i]);
		persons[i] = new Person(arr[i], input_ptr[i]);
		
		string name = persons[i]->name();
		string age = to_string(persons[i]->age());
		JSON.append("{'name':'");
		JSON.append(name);
		JSON.append("','age':'");
		JSON.append(age);
		JSON.append("'},");
    }
	JSON.append("]");
    int n = JSON.length();
    char char_array[n + 1];
    strcpy(char_array, JSON.c_str());
	EM_ASM_({
		JSON_str = UTF8ToString($0);
		console.log('JSON ' + JSON_str);
	}, char_array);
	
    delete []arr;	
	auto end = chrono::high_resolution_clock::now();
  
    // Calculating total time taken by the program.
    double time_taken = 
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  
    time_taken *= 1e-9;
	setTime(time_taken);
}

int add(int a){
	return a + 1;
}

 int main() {
   return 0;
 }