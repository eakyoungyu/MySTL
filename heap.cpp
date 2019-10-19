//#include <iostream>
//using namespace std;
//int const MAX = 100001;
//void my_swap(int& a, int& b) {
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//class Heap {
//private:
//	int data[MAX];
//	int size;
//	int root;
//public:
//	Heap():size(0), root(1){}
//	int get_size() {
//		return size;
//	}
//	bool is_empty() {
//		return (size == 0);
//	}
//	void inHeap(int target) {
//		if (target == root)	return;
//		int parent = target / 2;
//		if (data[target] > data[parent]) {
//			my_swap(data[target], data[parent]);
//			inHeap(parent);
//		}
//	}
//	void push(int n) {
//		// ���� �������� �ְ�, �θ�� ���ϸ鼭 �ø�
//		data[++size] = n;
//		inHeap(size);
//	}
//	void delHeap(int target) {
//		if (target * 2 > size)	return; // target�� leaf node��
//		int lchild = target * 2;
//		int rchild = target * 2 + 1;
//		int change = lchild;
//		if (rchild <= size) {
//			change = (data[lchild] < data[rchild]) ? rchild : lchild;
//		}
//
//		if (data[target] < data[change]) {
//			my_swap(data[target], data[change]);
//			delHeap(change);
//		}
//	}
//	void pop() {
//		//���� ������ ���Ҹ� root�� �ְ�, �ڽİ� ���ϸ鼭 ����(�� ū �ڽ��� �ø�)
//		data[root] = data[size--];
//		delHeap(root);
//	}
//	int top() {
//		return data[root];
//	}
//};
//int main(void) {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	Heap heap;
//	int N, x;
//	cin >> N;
//	while (N--) {
//		cin >> x;
//		if (x == 0) {
//			if (heap.is_empty()) {
//				cout << 0 << '\n';
//			}
//			else {
//				cout << heap.top() << '\n';
//				heap.pop();
//			}
//		}
//		else {
//			heap.push(x);
//		}
//	}
//
//	return 0;
//}