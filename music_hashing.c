#include <stdio.h>

#define TABLE_SIZE 10
#define N 8

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void initializeTable(int table[]) {
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = -1;
}

void displayTable(int table[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] == -1)
            printf("Index %d : EMPTY\n", i);
        else
            printf("Index %d : %d\n", i, table[i]);
    }
}

void insert(int table[], int key) {
    int index = hashFunction(key);
    int original = index;
    int collisions = 0;

    while (table[index] != -1) {
        collisions++;
        index = (index + 1) % TABLE_SIZE;
        if (index == original) {
            printf("Hash table is full.\n");
            return;
        }
    }

    table[index] = key;

    printf("\nInserting %d -> Hash Index = %d\n", key, original);
    printf("Collisions = %d\n", collisions);
    displayTable(table);
}

int hashSearch(int table[], int key, int *operations) {
    int index = hashFunction(key);
    int start = index;
    *operations = 0;

    while (table[index] != -1) {
        (*operations)++;
        if (table[index] == key)
            return index;

        index = (index + 1) % TABLE_SIZE;
        if (index == start)
            break;
    }
    return -1;
}

int linearSearch(int arr[], int n, int key, int *comparisons) {
    *comparisons = 0;

    for (int i = 0; i < n; i++) {
        (*comparisons)++;
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    int songIDs[N] = {105, 210, 315, 420, 525, 630, 735, 840};
    int searchIDs[N] = {105, 210, 315, 420, 525, 630, 735, 840};
    int table[TABLE_SIZE];

    initializeTable(table);

    printf("MUSIC APPLICATION - HASHING ASSIGNMENT\n");
    printf("Division Method with Linear Probing\n");
    printf("Table Size = %d\n", TABLE_SIZE);

    printf("\n========== INSERTION ==========\n");
    for (int i = 0; i < N; i++)
        insert(table, songIDs[i]);

    printf("\n========== SEARCH COMPARISON ==========\n");
    printf("ID\tHash Result\tHash Operations\tLinear Comparisons\n");

    int totalHash = 0, totalLinear = 0;

    for (int i = 0; i < N; i++) {
        int hashOps, linearOps;
        int hashIndex = hashSearch(table, searchIDs[i], &hashOps);
        int linearIndex = linearSearch(songIDs, N, searchIDs[i], &linearOps);

        totalHash += hashOps;
        totalLinear += linearOps;

        printf("%d\tIndex %d\t\t%d\t\t%d\n",
               searchIDs[i], hashIndex, hashOps, linearOps);
    }

    printf("\nTotal Hash Operations = %d\n", totalHash);
    printf("Average Hash Operations = %.2f\n", (double)totalHash / N);
    printf("Total Linear Comparisons = %d\n", totalLinear);
    printf("Average Linear Comparisons = %.2f\n", (double)totalLinear / N);

    printf("\nLoad Factor = %d / %d = %.2f\n", N, TABLE_SIZE,
           (double)N / TABLE_SIZE);

    return 0;
}
