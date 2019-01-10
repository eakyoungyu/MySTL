#include <iostream>
#include <queue>
using namespace std;
int main(void) {
	priority_queue<int> pq;

	pq.push(1);
	pq.push(232);

	cout << "==";
	cout << pq.top() << endl;

	return 0;
}