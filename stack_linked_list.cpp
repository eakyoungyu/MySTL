template <class T>
class Stack {
public:
	struct Node {
		T data;
		Node *next;
		Node(T data):data(data), next(NULL){}
	};

	Node *head;
	int s_size;
	Stack(): head(NULL), s_size(0) {}

	void push(T val) {
		Node *nnode = new Node(val);
		if (empty()) {
			head = nnode;
		}
		else {
			nnode->next = head;
			head = nnode;
		}
		s_size++;
	}
	void pop() {
		Node *dnode = head;
		head = dnode->next;
		delete(dnode);
		s_size--;
	}
	bool empty() {
		if (s_size == 0)	return 1;
		return 0;
	}
	T top() {
		return head->data;
	}
	int size() {
		return s_size;
	}
};