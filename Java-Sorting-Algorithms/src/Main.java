import java.time.Instant;
import java.time.Duration;

public class Main {
    public static void main(String[] args) {
        int size = 5;

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

        // Timers
        System.out.println("selectionSort execution time : " + Duration.between(selection_start, selection_end));
        System.out.println("insertionSort execution time : " + Duration.between(insertion_start, insertion_end));
        System.out.println("bubbleSort execution time : " + Duration.between(bubble_start, bubble_end));
    }
}