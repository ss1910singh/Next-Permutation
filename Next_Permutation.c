#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int* nums, int start, int end) {
    while (start < end) {
        swap(&nums[start], &nums[end]);
        start++;
        end--;
    }
}

void nextPermutation(int* nums, int Size) {
    int i = Size - 2;
    while (i >= 0 && nums[i] >= nums[i+1]) {
        i--;
    }
    if (i >= 0) {
        int j = Size - 1;
        while (j >= 0 && nums[i] >= nums[j]) {
            j--;
        }
        swap(&nums[i], &nums[j]);
    }
    reverse(nums, i + 1, Size - 1);
}

int main() {

    int i,size;
    printf("Enter number of element in array:-");
    scanf("%d",&size);
    int nums[size];
    printf("Enter elements of array:-");
    for(i=0;i<size;i++)
    {
       scanf("%d",&nums[i]);  
    }
    nextPermutation(nums,size);
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    return 0;
}
