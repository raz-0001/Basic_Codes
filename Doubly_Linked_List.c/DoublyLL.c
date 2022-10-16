#include<stdio.h>
#include<stdlib.h>

struct doubly{
	int data;
	struct doubly *prev;
	struct doubly *next;
};

void count(struct doubly **head){
	int count=0;
	struct doubly *ptr=NULL;
	ptr=*head;
	while(ptr != NULL){
		count++;
		ptr=ptr->next;
	}
	(*head)->data = count;
}

void traverse(struct doubly *head){
	struct doubly *ptr=head->next;
	if(head->next != NULL){
		printf("\nYour doubly linked list contains = ");
		while(ptr!=NULL){
			printf("%d\t", ptr->data);
			ptr=ptr->next;
		}
	}
	else
		printf("\nYour doubly linked list is empty.");
	return;
}

void insert(struct doubly **head, int data, int pos){
	struct doubly *ptr=*head;
	int k=1;
	count(head);
	if( pos > (((*head)->data)+1) ){
		printf("\nEntered position value is exceeding the limit");
		return;
	}
	while(ptr!=NULL && k<pos){		
		k++;
		ptr=ptr->next;
	}
	struct doubly *newnode=malloc(1*sizeof(struct doubly));
	newnode->data = data;
	newnode->prev = ptr;
	newnode->next = ptr->next;
	if(ptr->next != NULL)
		ptr->next->prev = newnode;
	ptr->next = newnode;
	printf("\nInsertion is done successfully");
	count(head);
	return;
}

int *search(struct doubly **head, int item){
	struct doubly *ptr=(*head)->next;
	int *loc=malloc(1*sizeof(int)), index=0, found=1;
	loc[0]=0;
	//loc = array of index of same item found multiple times
	//index = variable for index of loc array
	//found = index of items in doubly linked list
	if((*head)->data == 0){
		printf("\nYour doubly linked list is empty.");
		free(loc);
		return NULL;
	}
	while(ptr != NULL){
		if(ptr->data == item){
			index++;
			loc=realloc(loc, index*sizeof(int));
			loc[index-1] = found;
			found++;
		}
		else
			found++;
		ptr = ptr->next;	
	}
	if(loc[0] == 0)
		return NULL;
	else{
		loc=realloc(loc, (index+1)*sizeof(int));
		loc[index]=0;
		return loc;
	}
}

void delpos(struct doubly **head, int pos){
	count(head);
	struct doubly *ptr=*head;
	struct doubly *del=NULL;
	int k=1;
	if((*head) -> data == 0){
		printf("\nYour doubly linked list is empty");
		return;
	}
	while(k<pos && ptr!=NULL){
		ptr=ptr->next;
		k++;
	}
	del=ptr->next;
	if(del->next != NULL){
		del->next->prev = ptr;
		ptr->next = del->next;
	}
	else
		ptr->next = NULL;
	free(del);
	printf("\nDeletion is done successfully");
	count(head);
	return;
}

void delvalue(struct doubly **head, int value){
	count(head);
	struct doubly *ptr=(*head) -> next;
	struct doubly *del=NULL;
	if((*head)-> data == 0){
		printf("\nYour doubly linked list is empty.");
		return;
	}
	while(ptr!=NULL){
		if(ptr->data == value){
			del=ptr;
			if(ptr->next != NULL){
				ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
			}
			else{
				ptr->prev->next = NULL;
			}
			ptr=ptr->next;
			free(del);
		}
		else
			ptr=ptr->next;
	}
	printf("\nDeletion is done successfully");
	count(head);
	return;
}

int main(){
	int ch;
	struct doubly *head=malloc(1*sizeof(struct doubly));
	head->data = 0;
	head->prev = NULL;
	head->next = NULL;
	while(1){
		printf("\nPress 1 to Insert, 2 to Search, 3 to Delete, 4 to Traverse, any other to exit.");
		printf("\nEnter your choice = ");
		scanf("%d", &ch);
		if(ch==1){
			int data;		int pos;
			printf("\nEnter the data to be inserted = ");
			scanf("%d", &data);
			printf("Enter the position of data to be inserted = ");
			scanf("%d", &pos);
			insert(&head, data, pos);
		}
		else if(ch==2){
			int item;
			int *arr=NULL, i=0;
			printf("\nEnter your item to be searched = ");
			scanf("%d", &item);
			arr = search(&head, item);
			if(arr == NULL){
				printf("\nNo such entered item is found.");
			}
			else{
				printf("\nThe entered item is found in position = ");
				while(arr[i] != 0){
					printf("%d\t", arr[i]);
					i++;
				}
			}
		}
		else if(ch==3){
			int choice, pos;
			int value;
			printf("\nPress 1 to delete by position, 2 to delete by value");
			printf("\nEnter your choice = ");
			scanf("%d", &choice);
			if(choice==1){
				printf("Enter the position of the data to be deleted = ");
				scanf("%d", &pos);
				delpos(&head, pos);
			}
			else if(choice==2){
				printf("\nEnter the value of item to be deleted = ");
				scanf("%d", &value);
				delvalue(&head, value);
			}
		}
		else if(ch==4){
			struct doubly *ptr=head->next;
			printf("\nYour doubly linked list contains = ");
			while(ptr!=NULL){
				printf("%d\t", ptr->data);
				ptr=ptr->next;
			}
		}
		else
			break;
	}
	return 0;	
}
