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
	std::shared_ptr<T> sp1(new T);
	auto sp2(sp1);

	printf("sp1 pointer: %p, sp2 pointer %p\n", sp1.get(), sp2.get());
	printf("sp1: %ld, sp2: %ld\n", sp1.use_count(), sp2.use_count());

	return 0;
}
