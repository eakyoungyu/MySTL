#define HASH_SIZE 200007
int hash_function(int n) {
	n = (n > 0) ? n : -n;
	return n % HASH_SIZE;
}
struct Node {
	int val;
	Node *nxt;
	Node(int val) :val(val), nxt(0) {}
};
struct HashMap {
	Node *bucket[HASH_SIZE];
	void init() {
		for (int i = 0; i < HASH_SIZE; i++) {
			bucket[i] = 0;
		}
	}
	void insert(int n) {
		int key = hash_function(n);
		Node *nnode = new Node(n);
		nnode->nxt = bucket[key];
		bucket[key] = nnode;
	}
	Node* find(int n) {
		int key = hash_function(n);
		return bucket[key];
	}
};