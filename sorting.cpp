#include <iostream>
using namespace std;
int const MAX = 1001;
int nums[MAX];
int N;
void my_swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}
void bubble_sort(int nums[]) {
	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (nums[j] > nums[j + 1]) {
				my_swap(nums[j], nums[j + 1]);
			}
		}
	}
}
void selection_sort(int nums[]) {
	for (int i = 0; i < N - 1; i++) {
		int select = i;
		for (int j = i + 1; j < N; j++) {
			select = (nums[select] > nums[j]) ? j : select;
		}
		my_swap(nums[select], nums[i]);
	}
}
void insertion_sort(int nums[]) {
	for (int i = 0; i < N; i++) {
		int tmp = nums[i];
		int j;
		for (j = 0; j < i; j++) {
			if (nums[i] < nums[j]) {
				break;
			}
		}
		for (int k = i; k > j; k--) {
			nums[k] = nums[k - 1];
		}
		nums[j] = tmp;
	}
}
void merge_sort(int nums[], int size) {
	if (size == 1)	return;
	int nxtSize = size / 2;
	
	//divide
	merge_sort(nums, nxtSize);
	merge_sort(nums + nxtSize, size - nxtSize);

	//merge
	int *buf = new int[size];
	int i, j, k;
	k = i = 0;
	j = nxtSize;
	while (i < nxtSize && j < size) buf[k++] = (nums[i] < nums[j]) ? nums[i++] : nums[j++];
	while (i < nxtSize)	buf[k++] = nums[i++];
	while (j < size)	buf[k++] = nums[j++];

	for (int i = 0; i < size; i++) {
		nums[i] = buf[i];
	}
}
void quick_sort(int nums[], int s, int e) {
	//degenerate case
	if (s > e)	return; //s>=eµµ µÈ´Ù

	//divide --> pivot
	int pivot = s;
	int i, j;
	i = s + 1;
	j = e;
	while (i <= j) {
		while (nums[i] <= nums[pivot])	i++;
		while (nums[j] > nums[pivot])	j--;
		if (i < j) {
			my_swap(nums[i], nums[j]);
		}
	}

	my_swap(nums[pivot], nums[j]);
	quick_sort(nums, s, j - 1);
	quick_sort(nums, j + 1, e);
}
int main(void) {
	//freopen("my_input.txt", "r", stdin);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	//bubble_sort(nums);
	//selection_sort(nums);
	//insertion_sort(nums);
	//merge_sort(nums, N);
	quick_sort(nums, 0, N - 1);

	for (int i = 0; i < N; i++) {
		cout << nums[i] << '\n';
	}
	return 0;
}