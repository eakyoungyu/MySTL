int swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
void quick_sort(int arr[], int left, int right) {
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
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[pivot], arr[j]);
	quick_sort(arr, left, j - 1);
	quick_sort(arr, j + 1, right);
}