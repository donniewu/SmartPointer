#include <stdio.h>
#include <memory>
#include <vector>

auto customDeleter1 = [](int *a) {
	printf("customDeleter1\n");
	delete a;
};

auto customDeleter2 = [](int *a) {
	printf("customDeleter2\n");
	delete a;
};


int main()
{
	std::shared_ptr<int> sp1(new int, customDeleter1);
	std::shared_ptr<int> sp2(new int, customDeleter2);

	std::vector<std::shared_ptr<int>> v{sp1, sp2};

	return 0;
}
