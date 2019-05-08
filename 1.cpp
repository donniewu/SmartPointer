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

std::unique_ptr<Investment> makeInvestment(const std::string &type) {
	if (type == "stock") {
		//return std::make_unique<Stock>(); //c++14
		return std::unique_ptr<Stock>(new Stock());
	} else if (type == "bond") {
		//return std::make_unique<Bond>(); //c++14
		return std::unique_ptr<Bond>(new Bond());
	}

	return NULL;
}

int main()
{
	printf("makeInvestment start\n");
	auto in1 = makeInvestment("stock");
	auto in2 = makeInvestment("bond");
	printf("makeInvestment finish\n");

	return 0;
}
