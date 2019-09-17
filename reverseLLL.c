/*
Developer: Hamed Mirlohi
Date: Sep16th 2019
In this C program, we are reversing any given Linked List. the O complexity
of following program is O(n)
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* build_LLL(struct node* head, const int d)
{
    // no node situation
    if(head == NULL)
    {
        head = (struct node*)malloc(sizeof(head));
        head->next = NULL;
        head->data = d;
        return head;
    }
    struct node* tmp = head;
    head = (struct node*)malloc(sizeof(head));
    head->data = d;
    head->next = tmp;
    return head;
}

void display_LLL(const struct node* head)
{
    if(head != NULL)
    {
        display_LLL(head->next);
        printf("data: %d\n",head->data);
    }
}

struct node* reverseLLL(struct node* head)
{
    // no node or single node situation
    if(head == NULL || head->next == NULL)
        return head;
    // two node situation
    if(head->next->next == NULL)
    {
        struct node* current = head->next;
        current->next = head;
        head->next = NULL;
        return current;
    }
    // more than 2 node situation
    struct node* prev = head;
    struct node* current = head->next;
    struct node* forward = head->next->next;
    
    while(forward != NULL)
    {
        current->next = prev;
        prev = current;
        current = forward;
        forward = forward->next;
    }
    // fix the last node to point to one last
    current->next = prev;
    // head is tail now
    head->next = NULL;
    // return the last node on the list to represent head
    return current;
}

int main(void)
{
    struct node* head = NULL;
    head = build_LLL(head, 10);
    head = build_LLL(head, 20);
    head = build_LLL(head, 30);
    head = build_LLL(head, 40);
    head = build_LLL(head, 50);
    head = build_LLL(head, 60);
    head = build_LLL(head, 70);
    
    
    display_LLL(head);
    
    printf("Reversing: ------------------\n");
    
    head = reverseLLL(head);
    display_LLL(head);
    
    
}
