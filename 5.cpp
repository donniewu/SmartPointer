#include <stdio.h>
#include <memory>
#include <vector>

class T {
public:
	T() {}
	~T() {
		printf("T deleted\n");
	}
};

int main()
{
	std::shared_ptr<T> sp(new T);
	std::weak_ptr<T> wp(sp);

	printf("sp: %ld, wp: %ld\n", sp.use_count(), wp.use_count());

	std::shared_ptr<T> sp2(sp);
	printf("sp: %ld, wp: %ld\n", sp.use_count(), wp.use_count());

	return 0;
}
