#include <bits/stdc++.h>
using namespace std;

/*

root node = 1
binary heap - at-max two child of a node
balanced full binary tree - so complexity would be log(N).

left child of i th node = 2 * i;
right child of i th node = 2 * i + 1;

parent of a node at index i = base(i/2)

for a heap of size N
leaf nodes are at positions = N/2 + 1, N/2 + 2, ...


*/


// Time complexity - O(logN)
void max_heapify(int arr[], int index, int N) {
	if(index > N) return;
	int left = 2*index;
	int right = 2*index + 1;
	int largest = index;

	if(left <= N && arr[left] > arr[index]) {
		largest = left;
	}

	if(right <=N && arr[right] > arr[largest]) {
		largest = right;
	}

	if(largest != index) {
		swap(arr[largest], arr[index]);
		max_heapify(arr, largest, N);
	}
}

// build max-heap in bottom-up manner from leaf nodes
// time complexity - O(N/2)
// amortized complexity - O(N)
void build_maxHeap(int arr[], int N) {
	for(int i = N/2; i >= 1; i++) {
		max_heapify(arr, i, N);
	}
}


void min_heapify(int arr[], int index, int n) {
	if(index > n) return;
	int left = 2*index;
	int right = 2*index + 1;
	int smallest = index;

	if(left <= n && arr[left] < arr[smallest]) smallest = left;
	if(right <= n && arr[right] < arr[smallest]) smallest = right;

	if(smallest != index) {
		swap(arr[smallest], arr[index]);
		min_heapify(arr, smallest, n);
	}
}

void build_minHeap(int arr[], int n) {
	for(int i = n/2; i >=1 ;i--) {
		min_heapify(arr, i, n);
	}
}


void heap_sort(int arr[], int n) {
	int heap_size = n;
	build_maxHeap(arr, n);
	for(int i = n; i >= 2; i--) {
		swap(arr[1], arr[i]);
		heap_size -= 1;
		max_heapify(arr, 1, heap_size);
	}
}



int main() {
	int n;
	cin >> n;
	int arr[n+1];
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	// build_maxHeap(arr, n);
	// for(int i = 1; i <= n; i++) {
	// 	cout << arr[i] << " ";
	// }  cout << endl;

	// build_minHeap(arr, n);
	// for(int i = 1; i <= n; i++) {
	// 	cout << arr[i] << " ";
	// } cout << endl;

	heap_sort(arr, n);
	for(int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
	} cout << endl;
	return 0;
}