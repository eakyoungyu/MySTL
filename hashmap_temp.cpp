#include <iostream>
using namespace std;
int const HASH_MAX = 100;
int const MAX = 100001;
int N, M;
int A[MAX], B[MAX];
int abs(int a) {
	return a < 0 ? -a : a;
}
int hash_function(int value) {
	return abs(value)%HASH_MAX;
}
class HashTable {
public:
	typedef struct Node {
		int data;
		Node *next;
		Node(int data):data(data), next(NULL){}
	}Node;

	Node *bucket[HASH_MAX];
	HashTable() {
		for (int i = 0; i < HASH_MAX; i++) {
			bucket[i] = NULL;
		}
	}

	void insert(int value) {
		int key = hash_function(value);
		Node *nnode = new Node(value);

		if (bucket[key] == NULL) {
			bucket[key] = nnode;
			return;
		}
		
		nnode->next = bucket[key];
		bucket[key] = nnode;
	}
	Node *find(int value) {
		int key = hash_function(value);

		if (bucket[key] == NULL) {
			return NULL;
		}

		for (Node *n = bucket[key]; n != NULL; n = n->next) {
			if (n->data == value)	return n;
		}
		return NULL;
	}

	//void printAll() {
	//	cout << "==================\n";
	//	for (int i = 0; i < HASH_MAX; i++) {
	//		cout << i << ": ";
	//		if (bucket[i] == NULL) {
	//			cout << "NULL\n";
	//			continue;
	//		}
	//		for (Node *n = bucket[i]; n != NULL; n = n->next) {
	//			cout << n->data << " ";
	//		}
	//		cout << '\n';
	//	}
	//}
};
