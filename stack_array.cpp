template <typename T>
class Stack {
public:
	T *buf;
	int s_top;
	int cnt;
	Stack(int n) {
		this->cnt = n;
		buf = new T[cnt];
		s_top = -1;
	}
	void push(int n) {
		if (s_top == cnt - 1) {
			return;
		}
		buf[++s_top] = n;
	}
	void pop() {
		s_top--;
	}
	int size() {
		return s_top + 1;
	}
	bool empty() {
		if (s_top == -1)	return 1;
		return 0;
	}
	T top() {
		return buf[s_top];
	}
};