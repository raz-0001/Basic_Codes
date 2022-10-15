#include<stdio.h>
#include<stdlib.h>
void traverse(int arr[], int size){
	//size = no. of elements user inputs in the array
	printf("Your array elements are = \n");
	for(int i=0;i<size;i++)
		printf("%d ", arr[i]);
}

void insert(int arr[], int size, int *size1, int key, int loc){
	//size = total size of array including free space
	//size1 = no. of elements user inputs in the array
	if(arr[size-1]!=0)
		printf("\nThe array is already full");
	else{
		for(int i=*size1;i>loc;i--)
			arr[i]=arr[i-1];
		arr[loc]=key;
		printf("\nInsertion done successfully");
		*size1=*size1+1;
	}		
}

int *search(int arr[], int size, int key){
	//size = no. of elements user inputs in the array
	int found=0;
	int *ptr2=(int *)malloc(1*sizeof(int));
	for(int i=0;i<size;i++){
		if(arr[i]==key){
			found+=1;
			ptr2=(int *)realloc(ptr2, found*sizeof(int));
			ptr2[found-1]=i;
		}
	}
	ptr2[found]=100000;
	if(found==0)
		return NULL;
	else
		return ptr2;
}

void del(int arr[], int *size, int key){
	//size = no. of elements user inputs in the array
	int *found, i=0, j, a=0;
	found=search(arr, *size, key);
	if(found==NULL)
		printf("Entered element not found. No deletion.");
	else{
		while(found[i]!=100000){
			for(j=found[i]-a;j<*size-1;j++)
				arr[j]=arr[j+1];
			i++;	a++;
			arr[*size-1]=0;
			*size=*size-1;
		}
		printf("\nDeletion done successfully");
	}
}

int *catenate(int arr[], int *size, int *size2, int arr1[], int *size1){
	//arr = previously build array
	//size = no. of elements user inputs in the array
	//size2 = total size of array including free space
	//arr1 = newly build array to concatenate
	//size1 = no. of elements in new created array
	*size2=(*size2)+(*size1);
	arr=(int *)realloc(arr, (*size2)*sizeof(int));
	int i, j;
	for(i=*size,j=0; i<(*size+*size1) && j<*size1; i++,j++)
		arr[i]=arr1[j];
	*size=(*size)+(*size1);
	printf("\nNew formed array = \n");
	for(i=0;i<(*size);i++)
		printf("%d ",arr[i]);
	return arr;
}

void reverse(int arr[], int size){
	int i=0, temp;
	for(i=0; i<size/2; i++){
		temp=arr[i];
		arr[i]=arr[size-i-1];
		arr[size-1-i]=temp;
	}
	printf("\nYour new array is reversed = \n");
	for(i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
}

int *merge(int arr[], int *size1, int *size, int arrn[], int size2){
//arr = previously build array
//size1 = previously build array size
//size = total previously build array size including free space
//arrn = newly build array to merge
//size2 = size of newly build array to merge
	int i=0, j=0, k=0, *ptrn, found=0, *ptrin=(int *)malloc(1*sizeof(int));
	//ptrn = pointer of the new merged array
	//ptrin = pointer of the intersecting elements array
	//i = counter for previously build array
	//j = counter for newly build array which is to be merged
	//k = counter for merged array
	ptrin[0]=100000;
	//manually seting the 1st element of intersecting array = 100000
	ptrn=(int *)malloc((*size1+size2)*sizeof(int));
	while(i<*size1 || j<size2 || k<((*size1)+size2)){
		if(i<*size1 && j<size2){
			if(arr[i]<arrn[j]){
				ptrn[k]=arr[i];
				k++;	i++;
			}		
			else if(arrn[j]<arr[i]){
				ptrn[k]=arrn[j];
				j++;	k++;
			}
			else if(arr[i]==arrn[j]){
				ptrn[k]=arr[i];
				found++;
				ptrin=(int *)realloc(ptrin, found*sizeof(int));
				ptrin[found-1]=arr[i];
				i++;	j++;	k++;
			}
		}
		else if(i==*size1 && j<size2){
			ptrn[k]=arrn[j];
			j++;	k++;
		}
		else if(j==size2 && i<*size1){
			ptrn[k]=arr[i];
			i++;	k++;
		}
		else
			break;
	}
	if(found==0 && ptrin[found]==100000)
		printf("\nNo intersection elements found.");
	else{
		printf("The intersection elements are = ");
		for(int i=0;i<found;i++){
			printf("%d ", ptrin[i]);
		}
	}
	printf("\nYour merged array = ");
	for(i=0;i<k;i++)
		printf("%d ",ptrn[i]);
	printf("\nMerge is successfull");
	*size1=(*size1)+size2-found;
	*size=(*size)+size2-found;
	free(arr);		free(ptrin);
	return ptrn;
}

int main(){
	int n, n2, i, ch, count=0;
	printf("Enter size of array to be created = ");
	scanf("%d",&n);
	//n = total mem. alloc. for array including vacant space
	int *ptr=(int *)malloc(n*sizeof(int));
	//ptr = pointer of the main array
	printf("Enter no. of array elements u want to enter = ");
	scanf("%d",&n2);
	//n2 = no. of elements user wants to enter
	printf("Enter array elements = ");
	for(i=0;i<n2;i++)
		scanf("%d",&ptr[i]);
	while(count<(n-n2)){		//making all array[<vacant index>] = 0
		ptr[n2+count]=0;
		count++;
	}
	while(1){
		printf("\n1 to traverse, 2 to insert, 3 to search, 4 to delete, 5 to concatenate, 6 to reverse, 7 to merge, press any key to exit");
		printf("\nEnter your choice = ");
		scanf("%d",&ch);
		if(ch==1){
			traverse(ptr, n2);
		}
		else if(ch==2){
			int key, pos;
			printf("Enter the element to be inserted = ");
			scanf("%d",&key);
			printf("Enter the array index where element to be inserted = ");
			scanf("%d",&pos);
			insert(ptr, n, &n2, key, pos);
		}
		else if(ch==3){
			int key, *found, i=0;
			printf("Enter the element to be searched for = ");
			scanf("%d",&key);
			found=search(ptr, n2, key);
			if(found==NULL)
				printf("\nEntered element is not found.");
			else{
				printf("\nThe element is found in entered array index = ");
				while(found[i]!=100000){
					printf("%d ",found[i]);
					i++;
				}
			}
			free(found);
		}
		else if(ch==4){
			int key;
			printf("Enter the element to be deleted = ");
			scanf("%d",&key);
			del(ptr, &n2, key);
		}
		else if(ch==5){
			int n1, *ptr1;
			printf("Enter no. of elements of new array = ");
			scanf("%d",&n1);
			//n1 = new array creating memory space
			ptr1=(int *)malloc(n1*sizeof(int));
			printf("\nEnter elements of new array = ");
			for(int i=0;i<n1;i++){
				scanf("%d",&ptr1[i]);
			}
			ptr=catenate(ptr, &n2, &n, ptr1, &n1);
		}
		else if(ch==6){
			reverse(ptr, n2);
		}
		else if(ch==7){
			int i, *ptr2, size3;
			//ptr2 = new array created which is to be merged
			//size3 = new created merged array size
			printf("\nEnter no. of element of new array which is to be merged = ");
			scanf("%d",&size3);
			printf("\nEnter elements in the new array which is to be merged = ");
			ptr2=(int *)malloc(size3*sizeof(int));
			for(i=0;i<size3;i++){
				scanf("%d", &ptr2[i]);
			}
			ptr=(int *)merge(ptr, &n2, &n, ptr2, size3);
			free(ptr2);
		}
		else
			break;
	}
	
	free(ptr);
	
	return 0;
}