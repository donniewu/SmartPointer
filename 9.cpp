#include <stdio.h>
#include <memory>
#include <vector>

class T {
public:
	T() {
		printf("T created\n");
	}
	~T() {
		printf("T deleted\n");
	}
};

void processT(std::shared_ptr<T> sp, int aa)
{
}

int except()
{
	throw "WTF";

	return 0;
}

int main()
{
	try {
		//processT(std::shared_ptr<T>(new T), except());
		processT(std::make_shared<T>(), except());
	} catch (...) {
	}

	return 0;
}
