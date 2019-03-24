
struct Node {
	int data;
	Node *next, *prev;
	Node(int data):data(data), next(0), prev(0){}
	Node():next(0), prev(0){}
	void init(int data) {
		this->data = data;
	}
};
Node *my_new();
class DLL {
public:
	Node *head, *tail;
	DLL() {
		head = my_new();
		tail = my_new();
		head->next = tail;
		tail->prev = head;
	}
	void insert(int val) {
		//tail 바로 앞에 연결
		//4개 꽂기
		Node *nnode = my_new();
		nnode->init(val);

		nnode->next = tail;
		nnode->prev = tail->prev;
		tail->prev->next = nnode;
		tail->prev = nnode;
	}
	void erase(int val) {
		//2개 지우기
		for (Node *itr = head->next; itr != tail; itr = itr->next) {
			if (itr->data == val) {
				Node *temp = itr;		//itr을 지우면 안된다
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				//delete(temp);
			}
		 }
	}
	void clear() {
		head->next = tail;
		tail->prev = head;
	}
};
Node memory[10000];
int midx = 0;
Node *my_new() {
	return &memory[midx++];
}
