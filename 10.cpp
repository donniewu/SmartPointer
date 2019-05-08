#include <stdio.h>
#include <memory>
#include <vector>
#include <unistd.h>

class T {
public:
	T() {
		printf("T created\n");
		m_big = new char [100*1024*1024];
	}
	~T() {
		printf("T deleted\n");
		delete [] m_big;
	}
private:
	//int m_a[1024*1024*1024];
	char *m_big;

};

int main()
{
	///*
	std::shared_ptr<T> big(new T);
	//*/

	/*
	//Notice: m_big 還是會被放掉，只是 m_a 沒辦法被放掉
	//auto big = std::make_shared<T>();
	//*/

	std::weak_ptr<T> wb(big);
	big = nullptr;
	sleep(10);

	return 0;
}
