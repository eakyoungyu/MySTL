#define HASH_SIZE 200007
int hash_function(char *str) {
	int hash = 5831;
	int i = 0;
	while (str[i]) {
		hash = (((hash << 5) + hash) + str[i]) % HASH_SIZE;
		i++;
	}
	return hash;
}
void m_strcpy(char *des, char *src) {
	int i = 0;
	while (src[i]) {
		des[i] = src[i];
		i++;
	}
	des[i] = src[i];
	return;
}
struct Node {
	char data[20];
	Node *nxt;
	void init(char *data) {
		m_strcpy(this->data, data);
		nxt = 0;
	}
};
struct HashMap {
	Node *bucket[HASH_SIZE];
	void init() {
		for (int i = 0; i < HASH_SIZE; i++) {
			bucket[i] = 0;
		}
	}
	void insert(char str[20]) {
		int key = hash_function(str);
		Node *nnode = new Node();
		nnode->init(str);
		nnode->nxt = bucket[key];
		bucket[key] = nnode;
	}
	Node* find(char str[20]) {
		int key = hash_function(str);
		return bucket[key];
	}
};