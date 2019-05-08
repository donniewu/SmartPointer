#include <stdio.h>
#include <memory>
#include <vector>

class Node1;

class Node {
public:
	Node(const std::string &name) {
		m_name = name;
	}

	~Node() {
		printf("%s destruct\n", m_name.c_str());
	}

	void setNext(std::shared_ptr<Node> node) {
		m_next = node;
	}

	void setSpecialNext(Node* special_next) {
		m_special_next_raw = special_next;
	}

	void setSpecialNext(std::shared_ptr<Node> special_next) {
		m_special_next_shared = special_next;
	}

	void setSpecialNext(std::weak_ptr<Node> special_next) {
		m_special_next_weak = special_next;
	}

private:
	std::string m_name;
	std::shared_ptr<Node> m_next;

	Node* m_special_next_raw;
	std::shared_ptr<Node> m_special_next_shared;
	std::weak_ptr<Node> m_special_next_weak;
};

int main()
{
	std::shared_ptr<Node> nodeA(new Node("A"));
	std::shared_ptr<Node> nodeB(new Node("B"));
	std::shared_ptr<Node> nodeC(new Node("C"));

	nodeA->setNext(nodeB);
	nodeC->setNext(nodeB);
	//nodeB->setSpecialNext(nodeA.get()); // 看似可以但可能還是有 dangling 的狀況
	//nodeB->setSpecialNext(nodeA); // loop reference, memory leak
	//nodeB->setSpecialNext(std::weak_ptr<Node>(nodeA)); // ok
	return 0;
}
