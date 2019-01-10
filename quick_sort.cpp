template <typename T>
void my_swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
void quick_sort(T arr[], int left, int right) {
	if (left > right) {
		return;
	}

	int pivot = left;
	int i = left + 1, j = right;
	while (i <= j) {
		while (arr[i] <= arr[pivot]) {
			i++;
		}
		while (arr[j] > arr[pivot]) {
			j--;
		}

		if (i < j) {
			my_swap(arr[i], arr[j]);
		}
	}

	my_swap(arr[pivot], arr[j]);
	quick_sort(arr, left, j - 1);
	quick_sort(arr, j + 1, right);
}