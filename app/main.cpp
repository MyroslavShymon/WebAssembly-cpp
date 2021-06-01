#include <stdio.h>
#include <iostream>
#include <emscripten.h>
#include <chrono>

#include "../src/User.cpp"
#include "../src/sorts.cpp"
#include "../src/globals.cpp"
#include "../src/functions.cpp"

using namespace std;

extern "C" {
	void sort(int len);
}

void sort(int len) {
	auto start = chrono::high_resolution_clock::now();

	User** users = new User * [len];
	const char** names_array = new const char* [len];

	for (int i = 0; i < len; i++)
		names_array[i] = returnName(i);

	for (int i = 0; i < len; i++)
	{
		users[i] = new User(names_array[i], EM_ASM_DOUBLE({
		  let ages = [];
		  users.forEach((user) => {
			ages.push(user.age);
		  });
		  return ages[$0];
			}, i));
	}

	bubbleSort(users, len);

	formJSON(users, len);

	delete[]names_array;
	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program.
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;
	setTime(time_taken);
}

int main() {
	return 0;
}