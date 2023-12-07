class BST {

    // Node class
    class Node {
        int value; // It has a value
        Node left, right; // And two child items

        public Node(int item) {
            value = item; // Default value is given during construction
            left = null; // Default child are null
            right = null; // Default child are null
        }
    }

    // A BST has a root value (the value at the top)
    Node root;

    // By default, we define it to be null
    BST() {
        root = null;
    }

    /**
     * This function add a value to our BST
     *
     * @param value a value to add to our BST
     */
    void buildBST(int value) {
        root = insertNode(root, value);
    }

    /**
     * Insert a node at the correct position
     *
     * @param root  the root of the BST from where we begin going down the tree
     * @param value a value to add to the BST
     * @return
     */
    Node insertNode(Node root, int value) {

        // If there's no node, we create it
        if (root == null) {
            root = new Node(value);
            return root;
        }

        // If there's one, we compare its child to the value
        if (value < root.value) { // And insert it to the left...
            root.left = insertNode(root.left, value);
        } else if (value > root.value) { // And insert it to the or right...
            root.right = insertNode(root.right, value);
        }

        // We return the original root value at the end
        return root;
    }

    /**
     * Transform a sorted BST into an array
     *
     * @param root the root value of the BST
     * @param arr  an array of int
     * @param i    an index for populating the array
     * @return
     */
    int updateArrayFromTree(Node root, int[] arr, int i) {
        // If the root isn't null
        if (root != null) {
            // We go to the left
            i = updateArrayFromTree(root.left, arr, i);
            // When we arrive at the top left leaf, we add the value to our arr
            arr[i++] = root.value;
            // And then we explore the right part
            i = updateArrayFromTree(root.right, arr, i);
        }
        // We always return i to keep increasing the index of our array overwrite
        return i;
    }

    /**
     * Transforms an array into a BST object
     *
     * @param arr an array of int
     */
    void arrayToTree(int arr[]) {
        for (int i = 0; i < arr.length; i++) {
            buildBST(arr[i]);
        }
    }

    public static void main(String[] args) {
        BST tree = new BST();
        int array[] = { 5, 4, 7, 2, 11 };
        ArrayUtils.printArray(array, "Unsorted array");
        tree.arrayToTree(array);
        tree.updateArrayFromTree(tree.root, array, 0);
        ArrayUtils.printArray(array, "Sorted Array");
    }
}