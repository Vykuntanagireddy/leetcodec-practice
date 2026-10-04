#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 20011 // Prime number larger than 2 * numsSize

typedef struct {
    int key;
    int value;
    bool occupied;
} HashEntry;

static inline int hash(int key) {
    int h = key % TABLE_SIZE;
    return (h < 0) ? h + TABLE_SIZE : h;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashEntry* table = (HashEntry*)calloc(TABLE_SIZE, sizeof(HashEntry));
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        
        // 1. Look up complement in hash table
        int h = hash(complement);
        while (table[h].occupied) {
            if (table[h].key == complement) {
                result[0] = table[h].value;
                result[1] = i;
                *returnSize = 2;
                free(table);
                return result;
            }
            h = (h + 1) % TABLE_SIZE; // Linear probing
        }

        // 2. Insert current element (nums[i], i)
        h = hash(nums[i]);
        while (table[h].occupied) {
            h = (h + 1) % TABLE_SIZE;
        }
        table[h].key = nums[i];
        table[h].value = i;
        table[h].occupied = true;
    }

    free(table);
    return result;
}