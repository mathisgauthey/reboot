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
            System.out.println("The array is sorted.");
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
     *
     * @param arr
     */
    public static void bubbleSort(int[] arr) {
        int size = arr.length;
        int i, j;
        int temp;
        for (i = 0; i < size; i++) {
            for (j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

}