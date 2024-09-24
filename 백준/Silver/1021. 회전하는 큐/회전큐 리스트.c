#include <stdio.h>

typedef struct node {
    int value;
    struct node *next;
    struct node *prev;
} Node;

int n, m;
Node nodes[50];
int targets[50];

void init() {
    nodes[0].value = 1;
    nodes[0].prev = &nodes[n - 1];
    for (int i = 1; i < n; i++) {
        nodes[i].value = i + 1;
        nodes[i - 1].next = &nodes[i];
        nodes[i].prev = &nodes[i - 1];
    }
    nodes[n - 1].next = &nodes[0];
}

void disconnect_node(int target) {
    Node *cur = &nodes[0];
    while (cur->value != target) {
        cur = cur->next;
    }
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
}

int main() {
    int result = 0;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d", &targets[i]);
    }
    init();
    Node *cur = &nodes[0];
    for (int i = 0; i < m; i++) {
        int target = targets[i];

        Node *left = cur;
        int left_count = 0;

        Node *right = cur;
        int right_count = 0;

        while (left->value != target) {
            left = left->prev;
            left_count++;
        }
        while (right->value != target) {
            right = right->next;
            right_count++;
        }

        if (right_count > left_count) {
            result += left_count;
        }
        else {
            result += right_count;
        }
        cur = right->next;
        disconnect_node(target);
    }
    printf("%d", result);
}
