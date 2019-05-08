#include <stdio.h>
#include <memory>

class Investment
{
public:
	Investment() {}

	virtual ~Investment() {
		printf("Investment destruct\n");
	}
};

class Stock : public Investment
{
public:
	Stock() {}

	~Stock() {
		printf("Stock destruct\n");
	}
};

class Bond: public Investment
{
public:
	Bond() {}

	~Bond() {
		printf("Bond destruct\n");
	}
};

auto deleteInvestment = [](Investment* in) {
	printf("custom delete investment\n");
	delete in;
};

// c++14 回傳型別可以改用 auto:
// auto makeInvestment(const std::string &type) {
std::unique_ptr<Investment, decltype(deleteInvestment)> makeInvestment(const std::string &type) {
	std::unique_ptr<Investment, decltype(deleteInvestment)> in(nullptr, deleteInvestment);

	if (type == "stock") {
		in.reset(new Stock());
	} else if (type == "bond") {
		in.reset(new Bond());
	}

	return in;
}

int main()
{
	printf("makeInvestment start\n");
	auto in1 = makeInvestment("stock");
	printf("makeInvestment finish\n");

	return 0;
}
