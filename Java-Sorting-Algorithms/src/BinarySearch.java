public class BinarySearch {
    /**
     * Makes a binary search inside a sorted list of unique numbers
     *
     * @param arr   array of sorted unique ints
     * @param left  first index
     * @param right last index
     * @param query number to search for
     * @return
     */
    public static int BinarySearch(int[] arr, int left, int right, int query) {
        // Base case that helps us stop the recursion
        // Good if the query isn't inside the array
        if (left > right) {
            return -1;
        }

        // We find the middle index
        int mid = (left + right) / 2; // = left + (right - left) / 2

        // If the query is at the middle position, we return its index
        if (arr[mid] == query) {
            return mid;
        }

        // If the query is smaller than the middle element, we search in the left half
        if (query < arr[mid]) {
            return BinarySearch(arr, left, mid - 1, query);
        }
        // Or else we search in the right half
        return BinarySearch(arr, mid + 1, right, query);
    }

    public static void main(String[] args) {
        int[] array = { -1, 0, 1, 2, 3, 4, 7, 9, 10, 20 };
        int query = 8;
        int index = BinarySearch(array, 0, array.length - 1, query);
        System.out.println("Index of " + query + " is " + index + ".");
    }
}
