#include <stdio.h>
#include <stdlib.h>

typedef struct tree 
{
    int key;
    struct tree *left, *right;
} tree;
typedef struct queue_node 
{
    tree *node;
    int hd;
    struct queue_node *next;
} queue_node;

typedef struct hd_node 
{
    int hd;
    int value;
    struct hd_node *next;
} hd_node;

queue_node* create_queue_node(tree *node, int hd) 
{
    queue_node *new_node = (queue_node*)malloc(sizeof(queue_node));
    new_node->node = node;
    new_node->hd = hd;
    new_node->next = NULL;
    return new_node;
}

void enqueue(queue_node **front, queue_node **rear, tree *node, int hd) 
{
    queue_node *new_node = create_queue_node(node, hd);
    if (*rear == NULL) 
    {
        *front = *rear = new_node;
        return;
    }
    (*rear)->next = new_node;
    *rear = new_node;
}

queue_node* dequeue(queue_node **front, queue_node **rear)
{
    if (*front == NULL) return NULL;
    queue_node *temp = *front;
    *front = (*front)->next;
    if (*front == NULL) *rear = NULL;
    return temp;
}

hd_node* create_hd_node(int hd, int value) 
{
    hd_node *new_node = (hd_node*)malloc(sizeof(hd_node));
    new_node->hd = hd;
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void insert_hd_node(hd_node **head, int hd, int value) 
{
    hd_node *new_node = create_hd_node(hd, value);
    
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    if (hd < (*head)->hd) 
    {
        new_node->next = *head;
        *head = new_node;
        return;
    }
    
    hd_node *current = *head;
    while (current->next != NULL && current->next->hd < hd) 
    {
        current = current->next;
    }
    
    if (current->next != NULL && current->next->hd == hd) 
    {
        free(new_node);
        return;
    }
    
    new_node->next = current->next;
    current->next = new_node;
}

void print_hd_list(hd_node *head) 
{
    hd_node *current = head;
    while (current != NULL) 
    {
        printf("%d ", current->value);
        current = current->next;
    }
}

void free_hd_list(hd_node *head) 
{
    while (head != NULL) 
    {
        hd_node *temp = head;
        head = head->next;
        free(temp);
    }
}
void btUpView(tree *root) 
{
    if (root == NULL) return;
    
    queue_node *front = NULL, *rear = NULL;
    
    hd_node *hd_list = NULL;
    
    enqueue(&front, &rear, root, 0);
    
    while (front != NULL) 
    {
        queue_node *current = dequeue(&front, &rear);
        tree *node = current->node;
        int hd = current->hd;
        
        insert_hd_node(&hd_list, hd, node->key);

        if (node->left != NULL) 
        {
            enqueue(&front, &rear, node->left, hd - 1);
        }
        if (node->right != NULL) 
        {
            enqueue(&front, &rear, node->right, hd + 1);
        }
        
        free(current);
    }
    

    print_hd_list(hd_list);
    
    free_hd_list(hd_list);
}
