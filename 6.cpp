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

	for (int i = 1; i < 6; i++) {
		std::thread(&run, sp, i).detach();
	}

	sp = nullptr;

	while (wp.expired() == false) {
		printf("wp use_count %ld\n", wp.use_count());
		sleep(1);
	}
	return 0;
}
