import java.time.Instant;
import java.time.Duration;

public class Main {
    public static void main(String[] args) {
        int size = 10000;

        // Selection Sort
        int selection_array[] = ArrayUtils.generateRandomArray(size);
        ArrayUtils.printArray(selection_array, "selection_array");
        Instant selection_start = Instant.now();
        ArrayUtils.selectionSort(selection_array);
        Instant selection_end = Instant.now();
        ArrayUtils.printArray(selection_array, "selection_array");
        ArrayUtils.verifySorted(selection_array);

        // Insertion Sort
        int insertion_array[] = ArrayUtils.generateRandomArray(size);
        ArrayUtils.printArray(insertion_array, "insertion_array");
        Instant insertion_start = Instant.now();
        ArrayUtils.insertionSort(insertion_array);
        Instant insertion_end = Instant.now();
        ArrayUtils.printArray(insertion_array, "insertion_array");
        ArrayUtils.verifySorted(insertion_array);

        // Bubble Sort
        int bubble_array[] = ArrayUtils.generateRandomArray(size);
        ArrayUtils.printArray(bubble_array, "bubble_array");
        Instant bubble_start = Instant.now();
        ArrayUtils.bubbleSort(bubble_array);
        Instant bubble_end = Instant.now();
        ArrayUtils.printArray(bubble_array, "bubble_array");
        ArrayUtils.verifySorted(bubble_array);

        // Merge Sort
        int merge_array[] = new int[] { 4, 1, 3, 2, 0, -1, 7, 10, 9, 20 };
        ArrayUtils.printArray(merge_array, "merge_array");
        Instant merge_start = Instant.now();
        ArrayUtils.mergeSort(merge_array, 0, merge_array.length - 1);
        Instant merge_end = Instant.now();
        ArrayUtils.printArray(merge_array, "merge_array");
        ArrayUtils.verifySorted(merge_array);

        // quick-sort Sort
        int quick_sort_array[] = new int[] { 1, 8, 3, 9, 4, 5, 7 };
        ArrayUtils.printArray(quick_sort_array, "quick_sort_array");
        Instant quick_sort_start = Instant.now();
        ArrayUtils.quick_sortSort(quick_sort_array, 0, quick_sort_array.length - 1);
        Instant quick_sort_end = Instant.now();
        ArrayUtils.printArray(quick_sort_array, "quick_sort_array");
        ArrayUtils.verifySorted(quick_sort_array);

        // Timers
        System.out.println("selectionSort execution time : " +
                Duration.between(selection_start, selection_end));
        System.out.println("insertionSort execution time : " +
                Duration.between(insertion_start, insertion_end));
        System.out.println("bubbleSort execution time : " +
                Duration.between(bubble_start, bubble_end));
        System.out.println("mergeSort execution time : " +
                Duration.between(merge_start, merge_end));
        System.out.println("quick_sortSort execution time : " + Duration.between(quick_sort_start, quick_sort_end));
    }
}