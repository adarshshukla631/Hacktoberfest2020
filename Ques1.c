/*1) Define a structure named “musician” that contains following data members
a. name, registration number, age, number of national level performances,
number of state level performances, and number of local community
performances.
b. Define the following function to perform the mention tasks.
i. input_data() : to input the data of a musician.
ii. output_data(): to output the data of a musician.
iii. popularityRating() : to calculate the popularity rating using the formula
popularity rating = 10* (number of national level performances) + 5 *
(number of state level performances) + 2 * (number of local
community performances)
c. Define an array of structure for 5 musicians to perform the above tasks.*/

#include<stdio.h>
#include<stdlib.h>
struct musician
{
	char name[20],regno[10];
	int age,nnl,nsl,ncl;
}musicians[5];
float popularityRating(int x,int y,int z)
{
	return(10*x+5*y+2*z);
}
void input(int i)
{
	printf("Enter the name : ");
	scanf("%s",musicians[i].name);
	printf("Enter the registration number : ");
	scanf("%s",musicians[i].regno);
	printf("Enter the age of musician : ");
	scanf("%d",&musicians[i].age);
	printf("Enter the number of national level performances : ");
	scanf("%d",&musicians[i].nnl);
	printf("Enter the number of state level performances : ");
	scanf("%d",&musicians[i].nsl);
	printf("Enter the number of local community performances : ");
	scanf("%d",&musicians[i].ncl);
	printf("\n");
}
void output_data(int i)
{
	printf("Name : %s",musicians[i].name);
	printf("\nRegistration Number : %s",musicians[i].regno);
	printf("\nAge: %d",musicians[i].age);
	printf("\nNumber of national level performances : %d",musicians[i].nnl);
	printf("\nNumber of state level performances : %d",musicians[i].nsl);
	printf("\nNumber of local community performances : %d",musicians[i].ncl);
	printf("\nPopularity Rating : %f\n",popularityRating(musicians[i].nnl,musicians[i].nsl,musicians[i].ncl));
}
int main()
{
	int i,n,choice;
	while(1)
	{
		printf("1.Save_data\n2.Show_data\n3.Exit\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :
				i=0;
				printf("Enter the value of n : ");
				scanf("%d",&n);
				while(i<n)
				{
					printf("\nEnter the details of %d musician\n",i+1);
					input(i);
					i++;
				}	
			break;
			case 2 :
				i=0;
				while(i<n)
				{
					output_data(i);
					i++;
				}
			break;
			case 3 :
				exit(1);
			break; 
		}
	}
	return 0;
}
