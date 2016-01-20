#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <errno.h>
#include <inttypes.h>

#define BUFFER_SIZE 32

typedef struct Item {
    int8_t val;
    struct Item *next;
    struct Item *prev;
} item_t;

typedef struct Queue {
    item_t *head;
    item_t *last;
    uint8_t length;
} queue_t;

item_t *item_t_create(int8_t value) {
    item_t *item = (item_t *)malloc(sizeof(item_t));
    item->val = value;
    item->next = NULL;
    item->prev = NULL;
    return item;
}

void queue_enqueue(int8_t value, queue_t *queue) {
    item_t *new = item_t_create(value);
    if (queue->head == NULL) {
        queue->head = new;
        queue->last = new;
        return;
    }

    new->prev = queue->last;
    queue->last->next = new;
    queue->last = new;

    return;
}

int8_t queue_dequeue(queue_t *queue) {
    int8_t returnval = -1;
    if (queue->length>0) {
        returnval = queue->head->val;
        queue->head = queue->head->next;
        free(queue->head->prev);
        queue->head->prev = NULL;
    }
    return returnval;
}

queue_t *queue_create() {
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));;
    queue->length=0;
    queue->head = NULL;
    queue->last = NULL;
    return queue;
}

void queue_free(queue_t *queue) {
    while (queue->length>0) {
        queue_dequeue(queue);
    }
    free(queue);
}

void add_to_queue(queue_t *queue) {
    int8_t val = 0;
    errno = 0;
    bool is_success = false;
    while (!is_success) {
        printf("What is the value of your number? ");
        scanf("%",SCNd8,&val);
        if (errno == 0) {
            is_success = true;
        }
    }
    
    queue_enqueue(val,queue);
}

int main(int argc, char **argv) {
    char in_char = ';';
    queue_t *queue = queue_create();
    while (in_char != 'q') {
        printf("Queue length is %i\n",queue->length);
        printf("a: add an item to the queue\n");
        printf("d: remove an item from the queue\n");
        printf("p: print the queue\n");
        printf("q: quit\n");
        printf("Your choice: ");
        scanf(" %c",&in_char);
        scanf ("%*[^\n]"); scanf ("%*c");
        
        switch (in_char) {
            case 'a': add_to_queue(queue); break;
        }
    }
    
    queue_free(queue);
    return 0;
}
