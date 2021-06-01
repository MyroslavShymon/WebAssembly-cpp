#ifndef __USER_H__
#define __USER_H__

class User {
private:
	std::string _name;
	int _age;
public:
	User(std::string name, int age);
	// Getter
	std::string name() {
		return _name;
	}
	int age() {
		return _age;
	}
};

#endif