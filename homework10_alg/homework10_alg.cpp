// homework10_alg.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <stdlib.h>

#define T char
#define true 1 == 1
#define false 1 != 1

typedef int boolean;

//------------------------------------------------------//
typedef struct Node {
    T data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} Stack;

void init(Stack* stack) {
    stack->head = NULL;
    stack->size = 0;
};

//------------------------------------------------------//

typedef struct TwoLinkNode {
    T data;
    struct TwoLinkNode* next;
    struct TwoLinkNode* prev;
} TwoLinkNode;

typedef struct {
    struct TwoLinkNode* head;
    struct TwoLinkNode* tail;
    int size;
} TwoLinkList;

void initTwoLinkList(TwoLinkList* lst) {
    lst->head = NULL;
    lst->tail = NULL;
    lst->size = 0;
}

//------------------------------------------------------//

boolean push(Stack* stack, T value) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    if (tmp == NULL) {
        printf("Stack oveflov \n");
        return false;
    }
    tmp->data = value;
    tmp->next = stack->head;
    stack->head = tmp;
    stack->size++;
    return true;
}

T pop(Stack* stack) {
    if (stack->size == 0) {
        printf("Stack is empty");
        return -1;
    }
    Node* tmp = stack->head;
    T data = stack->head->data;
    stack->head = stack->head->next;
    free(tmp);
    stack->size--;
    return data;
}

void printOneLinkCharNode(Node* n) {
    if (n == NULL) {
        printf(" ");
        return;
    }
    printf("%c", n->data);
}

void printOneLinkCharStack(Stack* stack) {
    Node* current = stack->head;
    if (current == NULL) {
        printOneLinkCharNode(current);
    }
    else {
        do
        {
            printOneLinkCharNode(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d\n", stack->size);
}

//------------------------------------------------------//

boolean enqueue(TwoLinkList* queue, T value) {
    TwoLinkNode* tmp = (TwoLinkNode*)malloc(sizeof(TwoLinkNode));
    if (tmp == NULL) {
        printf("Out of memory \n");
        return false;
    }
    tmp->data = value;
    tmp->next = NULL;
    tmp->prev = queue->tail;

    if (queue->tail != NULL)
    {
        queue->tail->next = tmp;
    }
    if (queue->head == NULL)
    {
        queue->head = tmp;
    }

    queue->tail = tmp;
    queue->size++;
    return true;
}

T dequeue(TwoLinkList* queue) {
    if (queue->size == 0) {
        printf("Stack is empty");
        return -1;
    }
    TwoLinkNode* tmp = queue->head;
    T data = queue->head->data;
    queue->head = queue->head->next;

    if (queue->head != 0)
    {
        queue->head->prev = NULL;
    }
    if (tmp == queue->tail)
    {
        queue->tail = NULL;
    }

    free(tmp);
    queue->size--;
    return data;
}

void printTwoLinkCharNode(TwoLinkNode* n) {
    if (n == NULL) {
        printf(" ");
        return;
    }
    printf("%c", n->data);
}

void printTwoLinkCharList(TwoLinkList* lst) {
    TwoLinkNode* current = lst->head;
    if (current == NULL) {
        printTwoLinkCharNode(current);
    }
    else {
        do
        {
            printTwoLinkCharNode(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d\n", lst->size);
}

//------------------------------------------------------//

int main()
{
    Stack* st = (Stack*)malloc(sizeof(Stack));
    TwoLinkList* q = (TwoLinkList*)malloc(sizeof(TwoLinkList));

    /*init(st);
    push(st, '(');
    push(st, 'a');
    push(st, '+');
    push(st, 'b');
    push(st, ')');*/

    initTwoLinkList(q);
    enqueue(q, '(');
    enqueue(q, 'a');
    enqueue(q, '+');
    enqueue(q, 'b');
    enqueue(q, ')');

    printTwoLinkCharList(q);

    free(st);
    free(q);
    return 0;
}
