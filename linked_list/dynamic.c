#include <stdio.h>

int main()
{

	// This pointer will hold the
	// base address of the block created
	int* ptr;
	int num_el=10;
	int i;

	// Dynamically allocate memory using malloc()
	ptr = (int*)malloc(num_el * sizeof(int));
    // Memory has been successfully allocated
    printf("Memory allocated for %d integers.\n",num_el);

    // Get the elements of the array
    for (i = 0; i < num_el; ++i) {
        ptr[i] = i + 1;
    }

    // Print the elements of the array
    printf("The elements of the array are: ");
    for (i = 0; i < num_el; ++i) {
        printf("%d, ", ptr[i]);
    }

    // Dynamically re-allocate memory for 15 integers
    num_el=15;
    ptr = realloc(ptr, num_el * sizeof(int));
    printf("\nMemory has been reallocated for %d integers ",num_el);
    for (i = 0; i < num_el; ++i) {
        ptr[i] = i + 1;
    }
    printf("\n");
    printf("The elements of the array are: ");
    for (i = 0; i < num_el; ++i) {
        printf("%d, ", ptr[i]);
    }

    // Dynamically re-allocate memory for 5 integers
    num_el=5;
    ptr = realloc(ptr, num_el * sizeof(int));
    printf("\nMemory has been reallocated for %d integers ",num_el);
    for (i = 0; i < num_el; ++i) {
        ptr[i] = i + 1;
    }
    printf("\n");

    printf("The elements of the array are: ");
    for (i = 0; i < num_el; ++i) {
        printf("%d, ", ptr[i]);
    }

    //Free memory initially allocated
    free(ptr);
    printf("\nMemory has been freed");
    ptr=NULL;
    return 0;
}
