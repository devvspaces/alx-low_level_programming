#include <stdio.h>
#include <stdlib.h>

// Override the rand function
int rand() {
    static int sequence[] = {8, 8, 7, 8, 9, 23, 74};
    static int index = 0;
    
    // Return the next number from the sequence
    int number = sequence[index];
    
    // Move to the next index
    index = (index + 1);
    
    return number;
}
