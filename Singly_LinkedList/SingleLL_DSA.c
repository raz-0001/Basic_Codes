#include<stdio.h>
#include<stdlib.h>
struct node {
    float data;
    struct node *next;
};

void countlist(struct node **head) {
    int count=0;
    struct node *ptr;
    ptr=(*head)->next;
    while(ptr!=NULL) {
        count++;
        ptr=ptr->next;
    }
    (*head)->data=count;
    ptr=NULL;
    return;
}

void traverse(struct node *head) {
    struct node *ptr;
    ptr=head->next;
    if(ptr==NULL) {
        printf("No elements found in linked list");
        return;
    }
    else {
    	printf("\nYour linked list elements = \n");
        while(ptr!=NULL) {
            printf("%f\t",ptr->data);
            ptr=ptr->next;
        }
    }
    ptr=NULL;
    return;
}

void insert(struct node **head, float data, int pos) {
    int k=1;
    struct node *ptr, *prev;
    ptr=(*head)->next;
    prev=(*head);
    countlist(head);
    if((*head)->data!=0) {
        if(pos>((*head)->data)+1) {
            printf("\nPosition exceeding as your list contains %d elements", (int)((*head)->data));
            return;
        }
    }
    while(k<pos) {
        prev=ptr;
        ptr=ptr->next;
        k++;
	}
    struct node *newnode=(struct node *)malloc(1*sizeof(struct node));
    prev->next=newnode;
    newnode->data=data;
    newnode->next=ptr;
    countlist(head);
    printf("\nInsertion done successfully.");
    ptr=NULL;	prev=NULL;
    return;
}

void deldata(struct node **head, float data) {
    int k=1;
    struct node *ptr, *prev;
    prev=*head;
    ptr=(*head)->next;
    while(ptr!=NULL) {
        if(ptr->data==data) {
            struct node *del;
            del=ptr;
            prev->next=ptr->next;
            ptr=ptr->next;
            free(del);
        }
        else if(ptr->data!=data) {
            prev=ptr;
            ptr=ptr->next;
        }
        else {
            printf("\nNo such element found.");
            return;
        }
    }
    countlist(head);
    printf("\nDeletion done successfully.");
    ptr=NULL;	prev=NULL;
    return;
}

void delpos(struct node **head, int pos) {
    struct node *ptr, *prev;
    ptr=(*head)->next;
    prev=*head;
    int k=1;
    countlist(head);
    if(ptr==NULL) {
        printf("\nLinked list is empty.");
        return;
    }
    else if(pos>((*head)->data)) {
        printf("\nPosition exceeding as your list contains %d elements", (int)(*head)->data);
        return;
    }
    while(k<pos && ptr!=NULL) {
        prev=ptr;
        ptr=ptr->next;
        k++;
    }
    prev->next=ptr->next;
    countlist(head);
    printf("\nDeletion done successfully.");
    ptr=NULL;	prev=NULL;
    return;
}

void reverse(struct node **head) {
	struct node *ptr=NULL, *s=NULL, *r=NULL;
	ptr=(*head)->next;
	if(ptr==NULL) {
		printf("\nYour list is empty.");
		return;
	}
	while(ptr!=NULL) {
		s=r;
		r=ptr;
		ptr=ptr->next;
		r->next=s;
	}
	(*head)->next=r;
	printf("\nYour linked list is reversed successfully.");
	ptr=NULL;	s=NULL;	r=NULL;
	return;
}

int main() {
    int ch;
    struct node *head=(struct node *)malloc(1*sizeof(struct node));
    head->data=0;
    head->next=NULL;
    while(1) {
        printf("\nPress 1 to traverse, 2 to insert, 3 to delete, 4 to count elements, 5 to reverse, any other to exit");
        printf("\nEnter your choice = ");
        scanf("%d",&ch);
        if(ch==1)
            traverse(head);
        else if(ch==2) {
            float data;
            int pos;
            printf("\nEnter the data to be inserted = ");
            scanf("%f",&data);
            printf("\nEnter the position to be inserted (>=1) = ");
            scanf("%d",&pos);
            insert(&head, data, pos);
        }
        else if(ch==3) {
            int choice;
            printf("\nPress 1 to delete by data, 2 to delete by position");
            printf("\nEnter your choice = ");
            scanf("%d",&choice);
            if(choice==1) {
                float data;
                printf("\nEnter the data to be deleted = ");
                scanf("%f",&data);
                deldata(&head, data);
            }
            else if(choice==2) {
                int pos;
                printf("\nEnter the position of data to be deleted = ");
                scanf("%d",&pos);
                delpos(&head, pos);
            }
            else
                printf("\nInvalid choice.");
        }
        else if(ch==4) {
            countlist(&head);
            printf("\nNo. of elements found = %d", (int)head->data);
        }
        else if(ch==5) {
        	reverse(&head);
		}
        else
            break;
    }
    return 0;
}