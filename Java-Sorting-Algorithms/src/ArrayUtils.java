import java.util.Arrays;
import java.util.Random;

public class ArrayUtils {

    /**
     * Returns an array of int of size "size". Each int could be from 0-999.
     *
     * @param size the size of the desired array.
     * @return arr an array of randomized int from 0 to 999
     */
    public static int[] generateRandomArray(int size) {
        int[] arr = new int[size]; // Generate an array of specified size.
        Random random = new Random(); // Initiate randomization.

        for (int i = 0; i < size; i++) { // We go through all the created array
            arr[i] = random.nextInt(1000); // 0 - 999
        }

        return arr;
    }

    /**
     * Print an array name and its values.
     *
     * @param arr      an array of int.
     * @param var_name a string containing the table name.
     */
    public static void printArray(int[] arr, String var_name) {
        System.out.println("Table name : " + var_name); // Prints the array name.
        System.out.println(Arrays.toString(arr)); // Prints an array values.
    }

    /**
     * Method for swapping elements x and y
     *
     * @param arr an array of int
     * @param x   index of first element to swap
     * @param y   index of second element to swap
     */
    static void swap(int[] arr, int x, int y) {
        int temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }

    /**
     * Verify if an array has been correctly sorted.
     *
     * @param array an array of supposedly sorted int.
     */
    public static void verifySorted(int[] arr) {
        int size = arr.length; // Define the array size for loops.
        int i; // Loop index
        boolean sorted = true; // Boolean for verifying if the array is sorted.
        for (i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                sorted = false;
            }
        }
        if (sorted)
            System.out.println(
                    "The array is sorted.");
        else
            System.err.println("ERROR, ARRAY NOT SORTED");
    }

    /**
     * Sort an array using the selection sorting method.
     * Basically, we start at the left side of the array.
     * Then we go further right looking for a smaller value.
     * If we found one, we swap it. And we keep going.
     *
     * @param arr an array to sort.
     */
    public static void selectionSort(int[] arr) {
        int size = arr.length; // Loop limit
        int i, j; // Loop indexes
        int min_index; // Index of the min value found
        int temp; // Temp for swapping

        for (i = 0; i < size - 1; i++) {
            min_index = i; // We consider the first value to be the lowest.
            for (j = i + 1; j < size; j++) { // We loop through the rest of the tab
                if (arr[j] < arr[min_index]) { // If we find a lower value...
                    min_index = j; // We replace the old min_index with the index of the newly found lower value
                }
            }
            // We then swap the two values
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }

    /**
     * Sort an array using the insertion sorting method.
     * Basically we take a value and put it in the right place on the left.
     * We keep pushing the sorted part of the array further right.
     *
     * @param arr an array to sort.
     */
    public static void insertionSort(int[] arr) {
        int size = arr.length; // Loop limit
        int i, j; // Loop indexes
        int temp; // Temp for storing the current value to place on the left half.
        for (i = 1; i < size; i++) {
            temp = arr[i];
            j = i - 1;
            while (j >= 0 && arr[j] > temp) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = temp;
        }
    }

    /**
     * Sort an array using the bubble sorting method.
     * Basically, we start from the left and compare neighboring values.
     * The goal is to push the bigger values to the right.
     * First part of the array to be sorted : The right.
     *
     * @param arr
     */
    public static void bubbleSort(int[] arr) {
        int size = arr.length; // Loop limit
        int i, j; // Loop indexes
        int temp; // Temp variable for swapping
        for (i = 0; i < size; i++) {
            for (j = 0; j < size - i - 1; j++) {
                // If a value to the right is lower, we swap. -> Bigger values go to the right.
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    /**
     * Sort an array using the merge sorting method (with recursion).
     * We take an array and consider smaller and smaller part of it.
     * When we're the smallest, we sort them using the merge function.
     *
     * @param arr   an array of int
     * @param left  the first index
     * @param right the last index
     */
    public static void mergeSort(int[] arr, int left, int right) {
        if (left < right) { // If the considered part has more than 1 element
            int mid = left + (right - left) / 2; // Calculate mid-point

            // We use recursion to recursively split the array
            mergeSort(arr, left, mid); // Left part of the array
            mergeSort(arr, mid + 1, right); // Right part of the array

            // When we are done, we merge the result back in order.
            merge(arr, left, mid, right);
        }
    }

    /**
     * Merging results of shrunk array in order.
     *
     * @param arr   an array of int
     * @param left  first index
     * @param mid   mid index
     * @param right right index
     */
    public static void merge(int[] arr, int left, int mid, int right) {
        // Build temp array to avoid modifying the original contents
        int[] temp = new int[right - left + 1];

        int i = left;
        int j = mid + 1;
        int k = 0;

        // While both sub-arrays have values, then try and merge them in sorted order.
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k] = arr[i];
                i++;
                k++;
            } else {
                temp[k] = arr[j];
                j++;
                k++;
            }
        }

        // We then add the remaining values if there's any left.
        while (i <= mid) {
            temp[k] = arr[i];
            i++;
            k++;
        }
        while (j <= right) {
            temp[k] = arr[j];
            j++;
            k++;
        }

        // And we replace the values of the original array
        for (i = left; i <= right; i++) {
            arr[i] = temp[i - left];
            // We need to decrement left because temp array might be a smaller part inside
            // the input array and the indexes would not correspond.
        }
    }

    /**
     * Sort an array using the quick-sort algorithm.
     *
     * @param arr   an array
     * @param left  the first index
     * @param right the last index
     */
    public static void quick_sortSort(int[] arr, int left, int right) {
        if (left < right) { // Base case
            // Partition array around pivot.
            // Lower values to the left of the pivot.
            // Higher values to the right of the pivot.
            int array_partition = partition(arr, left, right);

            // Repeat the algorithm on the left part after the pivot
            quick_sortSort(arr, left, array_partition - 1);
            // Repeat the algorithm on the right part after the pivot.
            quick_sortSort(arr, array_partition + 1, right);
        }
    }

    /**
     * Partition an array part.
     * Takes a pivot (last index), put values around accordingly, repeat.
     * Lower values to the left of the pivot.
     * Higher values to the right of the pivot.
     *
     * @param arr   an array
     * @param left  the first index
     * @param right the last index
     * @return index of pivot position
     */
    public static int partition(int[] arr, int left, int right) {

        // Choose the pivot to be the last element of the array
        int pivot = arr[right];
        // Index of smaller element, starts below the array.
        int i = (left - 1);

        for (int j = left; j < right; j++) { // We go through the array except the pivot.
            if (arr[j] < pivot) { // If we find a lower value

                i++; // We increment the index of the smaller element
                swap(arr, i, j); // We swap it with the current element
            }
        }
        // In the end, we put the pivot to the right position at the right of the last
        // swapped element.
        swap(arr, (i + 1), right);
        return (i + 1);
    }

    /**
     * Sort an array using the heap-sort.
     * Basically sorting a binary tree using a max heap and removing element
     * one by one.
     *
     * @param arr
     */
    public static void heap_sortSort(int[] arr) {
        int size = arr.length;
        int x = size / 2 - 1; // Last non-leaf node
        // Parent of i'th node is (i-1)/2 => ((n-1)-1)/2 = N/2-1
        // We take the parent of the last leaf, meaning (N-1)'th node
        int y = size - 1; // Last element of the array

        // We create a max heap of our data starting from the last element
        // that have at least one leaf children. And we go up.
        while (x >= 0) {
            heapify(arr, size, x);
            x--;
        }

        // Swap the root with the last node, and then heapify once again
        while (y >= 0) {
            swap(arr, 0, y);
            // When we heapify again, we do it with one less value
            // That's because the last one was just sorted
            heapify(arr, y, 0);
            y--;
        }
    }

    /**
     * Build a max heap out of a binary tree.
     *
     * @param arr  an array
     * @param size the size of the array
     * @param i    the index of the parent node
     */
    public static void heapify(int[] arr, int size, int i) {
        int largest = i; // Selected node index
        int left = i * 2 + 1; // Index of left child of i
        int right = left + 1; // Index of right child of i

        // If there is still child values AND
        // If the left child is bigger, swap the largest value;
        if (left < size && arr[left] > arr[largest]) {
            largest = left;
        }
        // If there is still child values AND
        // If the right child is bigger, swap the largest value
        if (right < size && arr[right] > arr[largest]) {
            largest = right;
        }

        // If there was a bigger child down the line
        if (largest != i) {
            swap(arr, i, largest); // Swap the two values
            // Recursively continue with the largest element
            heapify(arr, size, largest);
        }
    }
}
