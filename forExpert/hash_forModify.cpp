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
	Node *prev, *nxt;
	void init(char *data) {
		m_strcpy(this->data, data);
		nxt = prev = 0;
	}
};
struct HashMap {
	Node *bucket_head[HASH_SIZE];
	Node *bucket_tail[HASH_SIZE];
	void init() {
		for (int i = 0; i < HASH_SIZE; i++) {
			bucket_head[i] = new Node();
			bucket_tail[i] = new Node();
			bucket_head[i]->nxt = bucket_tail[i];
			bucket_tail[i]->prev = bucket_head[i];
		}
	}
	
	void insert(char str[20]) {
		Node *nnode = new Node();
		nnode->init(str);
		int key = hash_function(str);
		
		nnode->prev = bucket_tail[key]->prev;
		nnode->nxt = bucket_tail[key];
		bucket_tail[key]->prev->nxt = nnode;
		bucket_tail[key]->prev = nnode;
	}

	Node* find(char str[20]) {
		int key = hash_function(str);
		return bucket_head[key]->nxt;
	}
};