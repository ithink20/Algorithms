/*
    @author: vikasc
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *p;

int m, n;
struct node *head1 = NULL, *head2 = NULL, *t_head = NULL;
struct node *list_head = NULL;

struct node* constructNode(int val) {
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = val;
    t->next = NULL;
    return t;
}

struct node *insertNode(struct node *head, struct node *new_node) {
    if (head == NULL) {
        head = new_node;
        list_head = head;
        p = head;
    } else {
        p->next = new_node;
        p = new_node;
    }
    return list_head;
}

void display(struct node *start) {
    struct node *temp = start;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Transpose(struct node *start2) {
    struct node *temp = start2, *prev = start2;
    struct node *transposed_list = NULL;
    int count = n, rows = m, cols = n;

    while (cols) {
        struct node *new_node1 = constructNode(temp->data);
        t_head = insertNode(t_head, new_node1);
        transposed_list = t_head;
        while (rows != 1) {
            while (count) {
                temp = temp->next;
                count -= 1;
            }
            struct node *new_node1 = constructNode(temp->data);
            t_head = insertNode(t_head, new_node1);
            rows -= 1;
            count = n;
            // printf("%d ", temp->data);
        }
        cols -= 1;
        temp = prev->next;
        prev = prev->next;
        rows = n;
    }
}

int count = 0;
void prod(struct node *p, struct node *q) {
    // display(p);
    // display(q);
    int i, j, element = 0;
    
    for (i = 0; i < n; i++) {
        element += p->data * q->data;
        p = p->next;
        q = q->next;
	}
    count += 1;
    printf("%d ", element);
    if (count == n) {
        printf("\n");
        count = 0;
    }
}

void multTwoList(struct node *start1, struct node *start2) {
    // display(start1);
    // display(start2);

    struct node *temp1 = NULL, *temp2 = NULL, *s1 = start1, *s2 = start2;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            struct node *new_node1 = constructNode(s1->data);
            temp1 = insertNode(temp1, new_node1);
            s1 = s1->next;
        }
        for (int k = 0; k < m; ++k)
        {
            for (int j = 0; j < n; ++j) {
                struct node *new_node2 = constructNode(s2->data);
                temp2 = insertNode(temp2, new_node2);
                s2 = s2->next;
            }
            // display(temp1);
            // display(temp2);
            prod(temp1, temp2);
            temp2 = NULL;
        }
        s2 = start2;
        temp1 = NULL;
    }
}

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m * n; ++i) {
        int val;
        scanf("%d", &val);
        struct node *new_node = constructNode(val);
        head1 = insertNode(head1, new_node);
    }
    // display(head1);
    for (int i = 0; i < m * n; ++i) {
        int val;
        scanf("%d", &val);
        struct node *new_node = constructNode(val);
        head2 = insertNode(head2, new_node);
    }
    // display(head2);
    Transpose(head2);
    display(t_head);
    multTwoList(head1, t_head);
    return 0;
}