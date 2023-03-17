# More of Malloc and Free

Malloc is an acronym for "memory allocation". It is a function that allocates a block of memory of a given size. The function returns a pointer to the beginning of the allocated block. The allocated block is uninitialized, which means that it contains random data. The function prototype is:

```c
void *malloc(size_t size);
```

## What is calloc?

Calloc is an acronym for "contiguous allocation". It is a function that allocates a block of memory of a given size. The function returns a pointer to the beginning of the allocated block. The allocated block is initialized to zero. The function prototype is:

```c
void *calloc(size_t nmemb, size_t size);
```

## What is realloc?

Realloc is an acronym for "re-allocation". It is a function that changes the size of an allocated block of memory. The function returns a pointer to the beginning of the allocated block. The allocated block is uninitialized, which means that it contains random data. The function prototype is:

```c
void *realloc(void *ptr, size_t size);
```

## What is free?

Free is a function that frees a block of memory that was previously allocated with malloc, calloc or realloc. The function prototype is:

```c
void free(void *ptr);
```

## What is exit?

Exit is a function that terminates the program. The function prototype is:

```c
void exit(int status);
```

## What is difference between stack and heap memory?

The stack is a region of memory that is managed by the operating system. It is used to store the local variables of a function. The stack is a LIFO (Last In First Out) data structure. The heap is a region of memory that is managed by the programmer. It is used to store dynamically allocated memory. The heap is a FIFO (First In First Out) data structure.
