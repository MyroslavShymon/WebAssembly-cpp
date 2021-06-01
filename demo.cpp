#include <stdio.h>
#include <iostream>
#include <string>
#include <emscripten.h>
#include <chrono>
// #include "Demo/Demo/Source.cpp"

using namespace std;

string JSON = "";

extern "C" {
  void sort(int len);
  int add(int a);
}


 EM_JS(void, setTime,
     (double time), {
		console.log("time bubble sort = ", time);
   		time_bubble = time;
 });

 
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

void swap(Person &a, Person &b){
    Person temp = a;
    a = b;
    b = temp;
}
// A function to implement bubble sort
void bubbleSort(Person *a[], const int size){
     for (int i = 0; i < size-1; i++){     
     for (int j = 0; j < size-i-1; j++){
           if (a[j]->age() > a[j+1]->age())
              swap(a[j], a[j+1]);
       }
    }
}

EM_JS(char*, returnName, (int i), {
  let super_arr = [];
      users.forEach((user) => {
        super_arr.push(user.name);
      });
	const greetings = super_arr[i];
	const byteCount = (lengthBytesUTF8(greetings) + 1);
	
	const greetingsPointer = _malloc(byteCount);
		stringToUTF8(greetings, greetingsPointer, byteCount);
	
		return greetingsPointer;
});

void sort(int len) {
	auto start = chrono::high_resolution_clock::now();
    const char** arr;
    arr = new const char*[len];    
    for(int i = 0; i < len; i++) 
        arr[i] = returnName(i);

  Person** persons = new Person * [len];
	for (int i = 0; i < len; i++)
  {
	  persons[i] = new Person(arr[i], EM_ASM_DOUBLE({
      let super_arr_num = [];
      users.forEach((user) => {
        super_arr_num.push(user.age);
      });
     return super_arr_num[$0];
   }, i));
  }

	JSON="[";
    bubbleSort(persons, len);
	for (int i = 0; i < len; i++)
    {
		
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