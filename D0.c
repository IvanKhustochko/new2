#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list 
{
    char word[20];
    struct list *next;
};
struct list* add_to_list(struct list *head, const char *word) 
{
    struct list *new_node = (struct list*)malloc(sizeof(struct list));
    strcpy(new_node->word, word);
    new_node->next = NULL;
    
    if (head == NULL) 
    {
        return new_node;
    }
    
    struct list *current = head;
    while (current->next != NULL) 
    {
        current = current->next;
    }
    current->next = new_node;
    
    return head;
}
void swap_elements(struct list *a, struct list *b) 
{
    char temp[20];
    strcpy(temp, a->word);
    strcpy(a->word, b->word);
    strcpy(b->word, temp);
}

struct list* sort_list(struct list *head) 
{
    if (head == NULL || head->next == NULL) 
    {
        return head;
    }
    
    int swapped;
    struct list *ptr;
    struct list *last = NULL;
    
    do 
    {
        swapped = 0;
        ptr = head;        
        while (ptr->next != last) 
        {
            if (strcmp(ptr->word, ptr->next->word) > 0) 
            {
                swap_elements(ptr, ptr->next);
                swapped = 1;
            }
            ptr = ptr->next;
        }
        last = ptr;
    } while (swapped);
    
    return head;
}

void print_list(struct list *head) 
{
    struct list *current = head;
    while (current != NULL) 
    {
        printf("%s", current->word);
        if (current->next != NULL) 
        {
            printf(" ");
        }
        current = current->next;
    }
    printf("\n");
}

void delete_list(struct list *head) 
{
    struct list *current = head;
    while (current != NULL) 
    {
        struct list *temp = current;
        current = current->next;
        free(temp);
    }
}

int main() 
{
    char input[10000];
    struct list *head = NULL;
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    
    char *token = strtok(input, " .");
    while (token != NULL) 
    {
        head = add_to_list(head, token);
        token = strtok(NULL, " .");
    }
    
    head = sort_list(head);
    
    print_list(head);
    
    delete_list(head);
    
    return 0;
}
