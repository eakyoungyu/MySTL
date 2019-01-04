void merge_sort(int arr[], int size) {
	if (size == 1) {
		return;
	}

	int mid = size / 2;
	merge_sort(arr, mid);
	merge_sort(arr + mid, size - mid);


	//merge
	int i = 0, j = mid;
	int *buf = new int[size];
	int k = 0;
	while (i < mid&&j < size) {
		buf[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
	}
	while (i < mid) {
		buf[k++] = arr[i++];
	}
	while (j < size) {
		buf[k++] = arr[j++];
	}

	for (int i = 0; i < size; i++) {
		arr[i] = buf[i];
	}
}