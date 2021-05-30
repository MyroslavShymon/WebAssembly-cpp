#include <stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<emscripten.h>
// #include "Demo/Demo/Source.cpp"

using namespace std;

extern "C" {
    int getNUM(int num);
	  void addOne(int* input_ptr, int* output_ptr, int len);
    void fstr(string path);
}

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

void addOne(int* input_ptr, int* output_ptr, int len) {
	ofstream personsStream;
	personsStream.open("pretty.txt");
	if (!personsStream.is_open())
	{
		cout << "Not open\n";
	}
	else {
		Person** persons = new Person * [len];
    personsStream << "[" << "\n";
    for (int i = 0; i < len; i++)
    {
      string s = "name" + to_string(input_ptr[i]);
      persons[i] = new Person(s, i);
    }

    for (int i = 0; i < len; i++)
    {
      cout << "persons[" << i << "] name = " << persons[i]->name() << " age = " << persons[i]->age() << "\n";
      personsStream << "{ name:'" << persons[i]->name() << "'; age: '" << persons[i]->age() << "';" << "\n";
    }
    personsStream.close();

    for (int i = 0; i < len; i++) {
      output_ptr[i] = input_ptr[i] + 1;
    }
	}
}

int main() {

    return 0;
}