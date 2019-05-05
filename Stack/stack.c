// Stack data structure

// A stack is a linear data structure that
// serves as a collection of elements with -
// three main operations.

// PUSH - which adds an elements

// POP - which removes the most recently added element

// Peek - which returns the top element

// LIFO - Last In First out

/** Stack implementation using an array **/

#include <stdio.h>
#include <stdlib.h>

// Data structure for stack

struct stack
{
    int maxsize;  // define max

    int top;

    int *items;
};

// utility function to initialize

struct stack* newStack(int capacity)
{
    struct stack *point = (struct stack*)malloc(sizeof(struct stack));

    point->maxsize = capacity;

    point->top = -1;

    point->items = (int*)malloc(sizeof(int) * capacity);
};

// utility function to return the size of the stack

int size(struct stack *point)
{
    return point->top + 1;

}

// utility function to check if the stack is empty or not

int isEmpty(struct stack *point)
{

    return point->top == -1; // or return size(point) == 0;

}


// utility function to check if the stack is full or not

int isFull(struct stack *point)
{
    return point->top == point->maxsize -1;  //  or return size(point) == point->maxsize;
}


// Utility function to add an element x in the stack

void push(struct stack *point, int x)
{
    // check if stack is already full, then inserting an element would lead into stack overflow !

    if(isFull(point))
    {
        printf("Stack Overflow");

        exit(EXIT_FAILURE);
    }

    printf("Inserting %d\n",x);

    point->items[++point->top] = x;
}


// utility function to return top element in a stack

int peek(struct stack *point)
{

    // check for empty stack

    if(!isEmpty(point))
    {
        return point->items[point->top];
    }
    else
    {
        exit(EXIT_FAILURE);
    }
}


// utility function to pop top element from the stack

int pop(struct stack *point)
{
    // check for stack underflow

    if(isEmpty(point))
    {
        printf("Stack Underflow");

        exit(EXIT_FAILURE);
    }

    printf("Removing %d\n", peek(point));

    return point->items[point->top--];
}


int main()
{
    // Create a stack of capacity 5

    struct stack *point = newStack(5);

    push(point, 3);
    push(point, 2);
    push(point, 1);

    printf("Top element is %d\n", peek(point));
    printf("Stack size is %d\n", size(point));

    pop(point);
    pop(point);
    pop(point);


    if(isEmpty(point))
        printf("Stack is empty");
    else
        printf("Stack is not empty");


    return 0;
}

