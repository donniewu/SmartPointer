#include <stdio.h>
#include <memory>
#include <vector>
#include <unistd.h>
#include <thread>

class T {
public:
	T() {}
	~T() {
		printf("T deleted\n");
	}

	void setNum(int num) {
		m_num = num;
	}

	int getNum() {
		return m_num;
	}

private:
	int m_num;
};

void run(std::shared_ptr<T> sp, int sleep)
{
	printf("%d start sleep\n", sleep);
	::sleep(sleep);
	printf("%d wake up\n", sleep);
}

int main()
{
	std::shared_ptr<T> sp(new T);
	std::weak_ptr<T> wp(sp);

	printf("sp: %ld, wp: %ld\n", sp.use_count(), wp.use_count());

	sp.get()->setNum(100);

	for (int i = 1; i < 3; i++) {
		std::thread(&run, sp, i).detach();
	}

	sp = nullptr;

	while (wp.expired() == false) {
		printf("wp use_count %ld\n", wp.use_count());

		/*
		auto sp = wp.lock();
		//*/

		/*
		sleep(5);
		auto sp = wp.lock();
		if (sp == NULL) {
			printf("wp expired\n");
			break;
		}
		//*/

		///*
		sleep(5);
		std::shared_ptr<T> sp(wp);
		//*/
		printf("%d\n", sp.get()->getNum());
		sleep(1);
	}

	return 0;
}
