template<typename T>
class Queue {
public:
	struct Node {
		T data;
		Node *next;
		Node(T data) :next(NULL), data(data) {}
	};

	Node *head;
	Node *tail;
	int q_size;
	Queue(): head(NULL), tail(NULL), q_size(0){}
	
	void push(T data) {
		Node *nnode = new Node(data);
		if (empty()) {
			head = nnode;
			tail = nnode;
		}
		else {
			tail->next = nnode;
			tail = nnode;
		}
		q_size++;
	}
	void pop() {
		Node *dnode = head;
		head = dnode->next;
		delete(dnode);
		q_size--;
	}
	T front() {
		return head->data;
	}
	T back() {
		return tail->data;
	}
	bool empty() {
		if (q_size == 0)	return 1;
		return 0;
	}
	int size() {
		return q_size;
	}
};