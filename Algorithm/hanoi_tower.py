def hanoiMove(n, source, auxiliary, destination, hanoi_tower):
    # Base case, we just move the disk from the source to the destination
    if n == 1:
        # We pop the disk from the source and append it to the destination
        hanoi_tower[destination].append(hanoi_tower[source].pop())
        print(hanoi_tower)
        return
    # First recursive call, we move the n-1 disks from the source to the auxiliary
    hanoiMove(n-1, source, destination, auxiliary, hanoi_tower)
    hanoi_tower[destination].append(hanoi_tower[source].pop())
    print(hanoi_tower)
    # Second recursive call, we move the n-1 disks from the auxiliary to the source
    hanoiMove(n-1, auxiliary, source, destination, hanoi_tower)

n = 5 # Number of disks
source = 'A' # Original source rod for the disks
auxiliary = 'B' # Middle rod
destination = 'C' # Destination rod
# We then initialise the hanoi_tower dictionary with the number of disks
hanoi_tower = {
    'A': [i for i in range(n, 0, -1)],
    'B': [],
    'C': []
}
print("Initial state :", hanoi_tower) # Print the initial state of the hanoi_tower
hanoiMove(n, source, auxiliary, destination, hanoi_tower) # Solve the puzzle