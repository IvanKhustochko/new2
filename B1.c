size_t totalMemoryUsage(list *head) 
{
    size_t total = 0;

    list *current = head;
    
    while (current != NULL) 
    {
        total += current->size;
        current = current->next;
    }
    
    return total;
}