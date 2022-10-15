#include<stdio.h>
#include<stdlib.h>
int main(){
	double *ptr1, *ptr2, x, numtr, dentr, sum=0;
	int i, j, size;
	
	printf("Enter no. of elements of array = ");
	scanf("%d", &size);	
	ptr1=(double *)malloc(size*sizeof(double));
	//ptr1 = x array
	ptr2=(double *)malloc(size*sizeof(double));
	//ptr2 = y array
	printf("Enter elements in x array = ");
	for(i=0;i<size;i++){
		scanf("%lf", &ptr1[i]);
	}
	printf("Enter elements in y array = ");
	for(i=0;i<size;i++){
		scanf("%lf", &ptr2[i]);
	}
		
	printf("Now enter value of x given in question = ");
	scanf("%lf",&x);
	
	for(i=0;i<size;i++){
		numtr=ptr2[i];
		//initialising numtr with 1st element of y array everytime
		dentr=1;
		//initialising dentr with 1 everytime
		for(j=0;j<size;j++){
			if(i!=j){
				numtr=numtr*(x-ptr1[j]);
				dentr=dentr*(ptr1[i]-ptr1[j]);
			}
		}
		sum+=numtr/dentr;
	}
	printf("\nFinal LANGRANG I.F value = %lf", sum);
	free(ptr1);
	free(ptr2);
	return 0;
}