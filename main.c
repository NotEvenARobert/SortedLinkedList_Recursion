#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct node {

    int data;
    struct node *next;

};

struct node* insert(struct node* list, int intData);
struct node* del(struct node* list, int intData);
void print(struct node *list);
void freeList(struct node* list);
void copy(struct node *q, struct node **s);


int main(void) {
  
    int number = 0, choice = 0;
    struct node *pList = NULL;
    struct node *nList = NULL;

    while(choice != 4) {

        printf("\nDo you want to (1) insert, (2) delete, (3) Copy (4) quit.\n");
        scanf("%d", &choice);
        printf("Your choice is %d\n", choice);

        if(choice == 1) {

            printf("Enter the value to insert\n");
            scanf("%d", &number);
            pList = insert(pList, number);
            // Look at the list.
            printf("Items in linked list: ");
            print(pList);
            printf("\n");
          
        } else if(choice == 2) {

            printf("Enter the value to delete.\n");
            scanf("%d", &number);
            pList = del(pList, number);

            printf("Items in linked list: ");
            print(pList);
            printf("\n");
          
        } else if(choice == 3) {
          
            if(nList) {
              
                freeList(nList);
              
            }  
            copy(pList, &nList); 

            printf("Items in NEW linked list: ");
            print(nList);
            printf("\n");
          
        } else {
          
            break;
          
        }
      
    }

    freeList(nList);
    freeList(pList);
    printf("\nBye..\n");
    return 0;
  
}

void print(struct node *list) {

    if(list == NULL) {
      
        return;
      
    }
    printf("->%d", list->data);
    print(list->next);
  
}

struct node* insert(struct node* list, int intData) {

    if(list == NULL || intData < list->data) {

        struct node* pNew = (struct node*)malloc(sizeof(struct node));
        pNew->data = intData;
        pNew->next = list;
        return pNew;
      
    }

    list->next = insert(list->next, intData);
    return list;
  
}

struct node* del(struct node* list, int intData) {

    if(list == NULL) {
        
        return NULL;
        
    }
    if(list->data == intData) {
        
        struct node* rest = list->next;
        free(list);
        return rest;
        
    }

    list->next = del(list->next, intData);
    return list;
    
}

void copy(struct node *q, struct node **s) {
    
    if(q == NULL) {
        
        *s = NULL;
        return;
        
    }

    *s = (struct node*)malloc(sizeof(struct node));
    (*s)->data = q->data;
    copy(q->next, &((*s)->next));
    
}

void freeList(struct node* list) {

    if(list == NULL) {
        
        return;
        
    }
    freeList(list->next);
    free(list);
    
}
