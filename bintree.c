#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t val_t;

typedef struct Tree_t {
    val_t val;
    struct Tree_t *left;
    struct Tree_t *right;
} tree_t;

bool tree_is_leaf(tree_t * tree) {
    return ((tree->left == NULL) && (tree->right == NULL));
}

tree_t * tree_new(val_t val) {
    tree_t * tree = (tree_t *)malloc(sizeof(tree_t));
    tree->left = NULL;
    tree->right = NULL;
    tree->val = val;
    return tree;
}

void tree_add_item(tree_t * tree, val_t val) {
    tree_t * ptr = tree;

    tree_t * new = tree_new(val);

    while (!tree_is_leaf(ptr)) {
        if (val > ptr->val) {
            ptr = ptr->right;
        }
        else {
            ptr = ptr->left;
        }
    }
    
    if (val > ptr->val) {
        ptr->right = new;
    }
    else {
        ptr->left = new;
    }
}


