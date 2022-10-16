#include<stdio.h>
#include<stdlib.h>

struct node {
    int coef, exp;
    struct node *next;
};

void insert(struct node **head, int coef, int exp){
	struct node *newnode=malloc(1*sizeof(struct node));
	struct node *ptr=*head;
	newnode->coef = coef;
	newnode->exp = exp;
	newnode->next = NULL;
	while(ptr->next != NULL){
		ptr=ptr->next;
	}
	ptr->next = newnode;
}

void traverse(struct node *head){
	struct node *ptr=head->next;
	printf("\nThe polynomial representation is = ");
	while(ptr!=NULL){
		(ptr->exp > 1) ? (printf("%d.x^%d", ptr->coef, ptr->exp)) : ( (ptr->exp==1) ? (printf("%d.x", ptr->coef)) : (printf("%d", ptr->coef)) );
		if(ptr->next != NULL)
			printf(" + ");
		ptr=ptr->next;
	}
}

int main(){
	int coef, exp;
	char ch;
	struct node *head=malloc(1*sizeof(struct node));
	head->coef = 0;
	head->exp = 0;
	head->next = NULL;
	do{
		printf("\nEnter the coefficient = ");
		scanf("%d", &coef);
		printf("Enter the exponent = ");
		scanf("%d", &exp);
		insert(&head, coef, exp);
		printf("Want to enter more additive items (y/n) = ");
		scanf("%s", &ch);
	}while(ch=='y');
	traverse(head);
	return 0;
}