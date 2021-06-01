#include "../include/functions.h"
#include "../include/globals.h"
#include "../include/User.h"

void formJSON(User* users[], int len) {
	std::string stringToFormJson = "[";
	for (int i = 0; i < len; i++)
	{
		std::string name = users[i]->name();
		std::string age = std::to_string(users[i]->age());
		stringToFormJson.append("{'name':'");
		stringToFormJson.append(name);
		stringToFormJson.append("','age':'");
		stringToFormJson.append(age);
		stringToFormJson.append("'},");
	}
	stringToFormJson.append("]");
	JSON = stringToFormJson;
	int n = stringToFormJson.length();
	char char_array[n + 1];
	strcpy(char_array, stringToFormJson.c_str());
	EM_ASM_({
	  JSON_str = UTF8ToString($0);
	  console.log('JSON ' + JSON_str);
	}, char_array);
}

EM_JS(void, setTime,
	(double time), {
	   console.log("time bubble sort in cpp = ", time);
	   time_bubble = time;
	});

EM_JS(char*, returnName, (int i), {
	  let names = [];
	  users.forEach((user) => {
		names.push(user.name);
	  });
	  const greetings = names[i];
	  const byteCount = lengthBytesUTF8(greetings) + 1;

	  const greetingsPointer = _malloc(byteCount);
	  stringToUTF8(greetings, greetingsPointer, byteCount);

	  return greetingsPointer;
	});
