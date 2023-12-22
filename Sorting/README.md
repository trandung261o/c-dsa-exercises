            typedef struct element {
                int key;
            } element;
            
            void swap(element *a, element *b) {
                element tmp = *a;
                *a = *b;
                *b = tmp;
            }
            
            void insertion_sort(element list[], int n) {
                element next;
                int i, j;
                for (i=1; i<n; i++) {
                    next = list[i];
                    for (j=i-1; j>=0 && list[j].key > next.key; j--) {
                        list[j+1] = list[j];
                    }
                    list[j+1] = next;
                }
            }
            
            void selection_sort(element a[], int n) {
                int i, j, min;
                element tmp;
                for (i=0; i<n-1; i++) {
                    min = i;
                    for (j=i+1; j<n; j++) {
                        if (a[j].key < a[min].key)
                            min = j;
                    }
            
                    tmp = a[i];
                    a[i] = a[min];
                    a[min] = tmp;
                }
            }
            
            void heapify(element list[], int root, int n) {
                int child = 2*root;
                int rootkey = list[root].key;
                while (child <= n) {
                    if (child < n && list[child].key < list[child+1].key) 
                        child++;
            
                    if (list[child].key < rootkey) break;
                    else {
                        swap(&list[child/2], &list[child]);
                        child *= 2;
                    }
                }
            }
            
            void quick_sort(element list[], int left, int right) {
                int i, j, pivot;
                if (left < right) {
                    i = left; j = right+1; 
                    pivot = list[left].key;
                    do {
                        do i++; while (i <= right && list[i].key < pivot);
                        do j--; while (j >= left && list[j].key > pivot);
                        if (i < j) swap(&list[i], &list[j]);
                    } while (i < j);
            
                    swap(&list[left], &list[j]);
                    quick_sort(list, left, j-1);
                    quick_sort(list, j+1, right);
                }
            }
            
            void heap_sort(element list[], int n) {
                //build max heap
                for (int i = n/2; i>0; i--) 
                    heapify(list, i, n);
            
                for (int i=n; i>1; i--) {
                    swap(&list[i], &list[1]);
                    heapify(list, 1, i-1);
                }
            }
            
            void merge(element arr[], int left, int mid, int right) {
                int i, j, k;
                int n1 = mid - left + 1;
                int n2 = right - mid;
                element arr_left[n1], arr_right[n2];
                for (i=0; i<n1; i++) arr_left[i] = arr[left+i];
                for (j=0; j<n2; j++) arr_right[j] = arr[mid+1 +j];
                i = j = 0; k = left;
                while (i<n1 && j<n2) {
                    if (arr_left[i].key <= arr_right[j].key) {
                        arr[k] = arr_left[i];
                        i++;
                    } else {
                        arr[k] = arr_right[j];
                        j++;
                    }
                    k++;
                }
            
                while (i<n1) {
                    arr[k] = arr_left[i];
                    i++; k++;
                }
                while (j<n2) {
                    arr[k] = arr_right[j];
                    j++; k++;
                }
            }
            
            void merge_sort(element a[], int left, int right) {
                if (left < right) {
                    int mid = (left + right)/2;
                    merge_sort(a, left, mid);
                    merge_sort(a, mid+1, right);
                    merge(a, left, mid, right);
                }
            }

##### Exercise 1: 
    Write a program that takes three positive integers n, m, and M as input. 
    Generate n positive integers, a1, a2, ..., an, randomly within the range from m to M. 
    Save the data to a file named arr-n.txt with the following format:
    -Line 1: Write the positive integer n (1 ≤ n ≤ 106).
    -Line 2: Write a1, a2, ..., an. Separate the numbers by a space.

##### Exercise 2:  Sorting a Sequence of Positive Integers using Selection Sort 
    Write a program to input a sequence of positive integers a1, a2, …, an 
    and sort this sequence in non-decreasing order using the selection sort algorithm.
    Input (stdin)
    -Line 1: A positive integer n (1 ≤ n ≤ 10^6)
    -Line 2: Positive integers a1, a2, …, an (1 ≤ ai ≤ 10^6)
    4
    5 4 3 4 1 2
    Output (stdout)
    Print the sequence sorted in non-decreasing order, with elements separated by a space.
    1 2 3 4 4 5

##### Exercise 3:  Sorting a Sequence of Positive Integers using Insertion Sort 
    Write a program to input a sequence of positive integers a1, a2, …, an 
    and sort this sequence in non-decreasing order using the selection sort algorithm.
    Input (stdin)
    -Line 1: A positive integer n (1 ≤ n ≤ 10^6)
    -Line 2: Positive integers a1, a2, …, an (1 ≤ ai ≤ 10^6)
    4
    5 4 3 4 1 2
    Output (stdout)
    Print the sequence sorted in non-decreasing order, with elements separated by a space.
    1 2 3 4 4 5

##### Exercise 4:  Sorting a Sequence of Positive Integers using Bubble Sort 
    Write a program to input a sequence of positive integers a1, a2, …, an 
    and sort this sequence in non-decreasing order using the selection sort algorithm.
    Input (stdin)
    -Line 1: A positive integer n (1 ≤ n ≤ 10^6)
    -Line 2: Positive integers a1, a2, …, an (1 ≤ ai ≤ 10^6)
    4
    5 4 3 4 1 2
    Output (stdout)
    Print the sequence sorted in non-decreasing order, with elements separated by a space.
    1 2 3 4 4 5
