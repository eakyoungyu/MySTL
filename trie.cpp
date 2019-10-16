#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int const MAX_WORD = 26;
int charToInt['z' + 1];
char intToChar[26];
struct Node {
	bool isWord;
	Node* nxt[MAX_WORD];
	Node() :isWord(false) {
		memset(nxt, 0, sizeof(nxt));
	}
};
struct Trie {
	Node* root;
	Trie() {
		root = new Node();
	}
	void add(string str) {
		Node* cur = root;
		for (int i = 0; str[i]; i++) {
			int idx = charToInt[str[i]];
			if (!cur->nxt[idx]) {
				cur->nxt[idx] = new Node();
			}
			cur = cur->nxt[idx];
		}
		cur->isWord = true;
	}
	
	bool find(string str) {
		Node* cur = root;
		for (int i = 0; str[i]; i++) {
			int idx = charToInt[str[i]];
			if (!cur->nxt[idx]) {
				return false;
			}
			cur = cur->nxt[idx];
		}
		return (cur->isWord) ? true : false;
	}
	bool remove(string str) { //return true: success to remove
		Node* cur = root;
		for (int i = 0; str[i]; i++) {
			int idx = charToInt[str[i]];
			if (!cur->nxt[idx]) {
				return false;
			}
			cur = cur->nxt[idx];
		}
		if (cur->isWord) {
			cur->isWord = false;
			return true;
		}
		return false;
	}
	void list(Node *cur, int& ret, string curWord) {
		if (cur->isWord) {
			ret++;
			//print curWord
		}
		for (int i = 0; i < MAX_WORD; i++) {
			if (cur->nxt[i]) {
				list(cur->nxt[i], ret, curWord += intToChar[i]);
			}
		}
	}
};
void init() {
	for (int i = 0; i < 26; i++) {
		charToInt[i + 'a'] = i;
		intToChar[i] = 'a' + i;
	}
}
int main(void) {
	init();

	return 0;
}