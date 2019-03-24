#define HASH_SIZE 1000007
void mystrcpy(char *des, char *src);
bool mystrcmp(char *s1, char *s2);
int hash_function(char n[20]) {
	int i = 0;
	int hash = 31;
	while (n[i]) {
		hash = ((hash << 5) + hash + n[i]) % HASH_SIZE;
		i++;
	}
	return hash;
}
struct Node {
	char name[20];
	Node *link;
	Node() :link(0) {}
	void init(char name[20]) {
		mystrcpy(this->name, name);
	}
};
struct HashMap {
	Node *bucket[HASH_SIZE];
	void init() {
		for (int i = 0; i < HASH_SIZE; i++) {
			bucket[i] = 0;
		}
	}
	void insert(char name[20]) {
		Node *nnode = new Node();
		nnode->init(name);
		int key = hash_function(name);
		nnode->link = bucket[key];
		bucket[key] = nnode;
	}
	bool find(char name[20]) {
		int key = hash_function(name);
		for (Node *itr = bucket[key]; itr != 0; itr = itr->link) {
			if (mystrcmp(name, itr->name))	return true;
		}
		return false;
	}
};

void mystrcpy(char *des, char *src) {
	int i = 0;
	while (1) {
		des[i] = src[i];
		if (!src[i])	return;
		i++;
	}
}
bool mystrcmp(char *s1, char *s2) {//같으면 false 반환
	int i = 0;
	while (1) {
		if (s1[i] != s2[i])	return true;
		if (!s1[i])			return false;
		i++;
	}
}