#include<stdio.h>
#include<stdlib.h>

typedef struct circular{
	int data;
	struct circular *next;
} circular;

int count(circular *head){
	circular *ptr=head;
	int count=0;
	do{
		(ptr->data==0)?(count=count):(count++);
		ptr=ptr->next;
	}while(ptr!=head);
	return count;
}

circular *endof(circular *head){
	circular *ptr=head;
	while(ptr->next != head)
		ptr=ptr->next;
	return ptr;
}

void insert(circular **head, int data, int pos){
	int k=1;
	int c=count(*head);
	circular *prev=*head, *ptr=*head;
	if(pos > c+1){
		printf("\nThe entering data position is exceeding limit.");
		return;
	}
	while(k<pos){
		prev=ptr;
		ptr=ptr->next;
		k++;
	}
	if(pos==1 && (*head)->data==0){
		(*head)->data = data;
		printf("\n Insertion is done successfully.");
		return;
	}
	circular *newnode=(circular *)malloc(1*sizeof(circular));
	newnode->data = data;
	newnode->next = ptr;
	if(pos==1){
		circular *ptrnew=prev;
		while(ptrnew->next != *head)
			ptrnew=ptrnew->next;
		ptrnew->next=newnode;
		(*head) = newnode;
	}
	else
		prev->next = newnode;
	printf("\n Insertion is done successfully.");
}

void traverse(circular *head){
	circular *ptr=head;
	if(head->data == 0){
		printf("\n Your circular linked list is empty.");
		return;
	}
	printf("\nYour circular linked list conatins = \n");
	do{
		printf("%d\t", ptr->data);
		ptr=ptr->next;
	}while(ptr!=head);
}

void delvalue(circular **head, int val){
	circular *ptr=(*head), *prev=NULL;
	int k=1, c=count(*head);
	circular *last=endof(*head);
	//k=index of every elements traversed in linked list
	do{
		if(ptr->data != val){
			prev=ptr;
			ptr=ptr->next;
			k++;
		}
		else if(ptr->data==val){
			circular *del=ptr;
			if(k!=1)
				prev->next=del->next;
			else if(k==1){
				circular *ptrnew=ptr;
				while(ptrnew->next!=*head) {ptrnew=ptrnew->next;}
				ptrnew->next=del->next;
				(*head)=del->next;
			}
			ptr=ptr->next;
			if(c!=1)	free(del);
			else	del->data=0;
		}
		c=count(*head);
	}while(k<=c);
	printf("\nAll same data values are deleted successfully.");
}

void delpos(circular **head, int pos){
	circular *ptr=*head, *prev=NULL, *del=NULL;
	int k=1, c=count(*head);
	if(pos > c+1){
		printf("The position is exceeding your circular linked list limit.");
		return;
	}
	while(k<pos){
		prev=ptr;
		ptr=ptr->next;
		k++;
	}
	if(pos==1 && c==1){
		(*head)->data = 0;
		(*head)->next = *head;
	}
	else if(c!=1){
		del=ptr;
		if(pos==1){
			circular *ptrnew=ptr;
			while(ptrnew->next != *head)
				ptrnew=ptrnew->next;
			ptrnew->next = del->next;
			(*head) = del->next;
		}
		else{
			prev->next = del->next;
		}
	}
	free(del);
	printf("\nThe deletion is done successfully");
}

int *search(circular *head, int val){
	circular *ptr=head;
	int *arr=malloc(sizeof(int)), found=0, k=1;
	arr[0]=-1;
	//arr = new array for items of multiple occurence
	//found = index of new array for multiple occurence
	//k = index of items in circular linked list
	if(head->data == 0){
		printf("Your linked list is empty");
		return arr;
	}
	do{
		if(ptr->data == val){
			found++;
			arr=realloc(arr, found*sizeof(int));
			arr[found-1]=k-1;
		}
		k++;
		ptr=ptr->next;
	}while(ptr != head);
	arr=realloc(arr, found+1*sizeof(int));
	arr[found]=-1;
	return arr;
}

int main(){
	int ch;
	circular *head = (circular *)malloc(1*sizeof(circular));
	head->data = 0;		head->next = head;
	while(1){
		printf("\nPress 1 to insert, 2 to delete, 3 to traverse, 4 to search, any other to exit.");
		printf("\nEnter your choice = ");
		scanf("%d", &ch);
		if(ch==1){
			int data, pos;
			printf("Enter the data to be inserted = ");
			scanf("%d", &data);
			printf("\nEnter the position to be inserted = ");
			scanf("%d", &pos);
			insert(&head, data, pos);
		}
		else if(ch==2){
			if(head->data == 0){
				printf("Your circular linked list is empty.");
				continue;
			}
			int ch;
			printf("Press 1 to delete by value, 2 to delete by position.");
			printf("\nEnter your choice = ");
			scanf("%d", &ch);
			if(ch==1){
				int data;
				printf("Enter the data value to be deleted = ");
				scanf("%d", &data);
				delvalue(&head, data);
			}
			else if(ch==2){
				int pos;
				printf("Enter the position of data to be deleted = ");
				scanf("%d", &pos);
				delpos(&head, pos);
			}
		}
		else if(ch==3){
			traverse(head);
		}
		else if(ch==4){
			int *arr=NULL, val;
			printf("Enter the data to be searched for = ");
			scanf("%d", &val);
			arr=search(head, val);
			if(arr[0] == -1){
				printf("Your data is not found in the linked list.");
			}
			else{
				printf("Your data is found in list index = ");
				for(int i=0; arr[i]!=-1; i++)
					printf("%d\t", arr[i]);
			}
		}
		else
			break;
	}
	return 0;
}