//Abdelrahman Hany Shaheen  sec:02    B.N.:48
//Abdelrahman Mohamed Farid   sec:02  B.N :45
//Mohamed Yasser Mohamed ALi    sec:03   B.N:49
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
char garbage;
int no_of_students;
int size_linkedlist = 0;
int size_array=0;

typedef struct
{
    char name[30];
    int ID;
    int birthdate[3];        //element #0 =day  element #2=month    element #3=year
    int score;              //score of last year of the student
}student;



struct Node {
	struct Node* next;
        student stu;

};

struct Node* head = NULL;
struct Node* tail = NULL;

void gather_data_linkedlist(struct Node* node)
{
  
    printf("enter the student %i name: ", size_linkedlist + 1);
	scanf("%c", &garbage, 1);
	scanf("%[^\n]", &node->stu.name, 20);
	printf("enter the student %i ID: ", size_linkedlist + 1);
	scanf("%d", &node->stu.ID);
	printf("enter the student %d score: ", size_linkedlist + 1);
	scanf("%d", &node->stu.score);
	for (int i = 0; i < 3; i++)
    {
        scanf("%d", &node->stu.birthdate[i]);
    }
		printf("the data of student %d has been entered sucessfuly\n\n", size_linkedlist + 1); 
}
  void gather_data_array(student* element, int no_of_elements) 
  {
   printf("enter the student %i name: ", no_of_elements + 1);
    scanf("%c", &garbage, 1);
    scanf("%[^\n]", &element->name, 20);
    printf("\nenter the student %i ID: ", no_of_elements + 1);
    scanf("%d", &element->ID);
    printf("enter the student %i score: ", no_of_elements + 1);
    scanf("%d", &element->score);
    printf("please enter the birth date day/month/year\n");
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &element->birthdate[i]);
    }
	printf("the data of student %d has been entered sucessfuly\n\n", no_of_elements + 1); 
   
}
void printlist_linkedlist()
{
	int j = 1;
	for (struct Node* temp2 = head; temp2 != NULL; temp2 = temp2->next)
	{
		printf("the student %i name is %s \n", j, temp2->stu.name);

		printf("the student %i ID is %i \n", j, temp2->stu.ID);

		printf("the student %i score is %i \n", j, temp2->stu.score);
        printf(" the student %i birthdate: %d /",j, temp2->stu.birthdate[0]);
        printf(" %d /", temp2->stu.birthdate[1]);
        printf(" %d \n", temp2->stu.birthdate[2]);
		j++;
	}
}
void printlist_array(student* stud)
{
	for (int i = 0; i < size_array; i++)//loop to print the array elements before insertion the counter is incremented by 1 as considering the new insertion
    {
        printf("student %d name: %s\n", i + 1, (stud + i)->name);
        printf("student %d ID: %d\n", i + 1, (stud + i)->ID);
        printf("student %d score: %d\n", i + 1, (stud + i)->score);
        printf("student %d birthdate: %d /", i + 1, (stud + i)->birthdate[0]);
        printf(" %d /", (stud + i)->birthdate[1]);
        printf(" %d \n", (stud + i)->birthdate[2]);
    }
}

void insert_linkedlist(int index)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
   gather_data_linkedlist(new_node);
	if (head == NULL)
	{
		printf("the list has zero node only then :\n ");
		head = new_node;
		tail = head;
		tail->next = NULL;
	}

	else
	{
	    if ( index == 1)
	    {
	        new_node->next = head;
	     	head = new_node;
	    }
	    else if ( index == size_linkedlist+1 )
	    {
	    tail->next = new_node;
		tail = tail->next;
	    }
	    else
	    {
		struct Node* temp = head;
			for (int i = 1; i < (index-1); i++)
			{
				temp = temp->next;
			}

			new_node->next = temp->next;
			temp->next = new_node;
	    }
	}
			
	size_linkedlist++;
	return;
}

void insert_array(int index,student* stud)
{
    for (int i = 0; i <= size_array- index; i++)//shifting the elements after the insertion index.
    {
        *(stud + size_array + 1 - i) = *(stud + size_array- i);
    }
    gather_data_array(stud + index, index);
    size_array++;
}


int main()
{
	int track;
	printf("The size of structure %d\n", sizeof(student));
	printf("The size of node %d\n", sizeof(struct Node));	
	printf(" press 1 for linkedlist\n press 2 for array");
	scanf("%d",&track);
	switch ( track)
	{
	case 1:
	{
	int key;
	int pos;
	printf("enter the number of students to create your list initially: ");
	scanf("%d", &no_of_students);


    
	for (int i = 0; i < no_of_students; i++)
	{
		insert_linkedlist(size_linkedlist+1);

	}
	printf("the list before insertion\n");
	for (struct Node* temp2 = head; temp2 != NULL; temp2 = temp2->next)
	{

		printlist_linkedlist();
	}
	while (1)
	{

		printf("type 1 to insert: \n type 2 to exit: \n");
		scanf("%d", &key);

		switch (key)
		{
		case 1:
		{
		    printf("Enter 1 to insert at head, or %i to insert at tail or other in between\n", size_linkedlist+1);
			printf("Enter the index:");
			scanf("%d", &pos);
			if (pos > size_linkedlist+1 || pos < 1)
			{
				printf("Invalid insertion you must enter a value from 0 to %d\n", size_linkedlist+1);
				continue;
			}		
			insert_linkedlist(pos);
			printlist_linkedlist();
			break;
		}
		case 2:
		{
			printf("the list after insertion \n ");
			printlist_linkedlist();
			return 0;
		}
		
		}
		



	}
	break;	
	}
	
	case 2:
	{
		int key2;
	
    
	printf("Please enter the number of students initially registered on system\n");
    scanf("%d", &size_array);
    student* stud;//The head pointer
    stud = (student*)malloc(size_array);//Reserve dynamic array of initial size N
    int pos2; //The index of the element the will be inserted in the array
    for (int i = 0; i < size_array; i++)//A for loop to access The array elements
    {
        gather_data_array(stud + i, i);
    }
   printlist_array(stud);
  
   while(1)
   {
   printf("type 1 to insert: \n type 2 to exit: \n");
   scanf("%d",&key2);
   switch (key2)
   {
	   case 1:
	   {
		   printf("please enter the insertion index from 0 to %d where 0 is the first element and %d is the last.\n", size_array, size_array);
			scanf("%d", &pos2);
    

			if (pos2 > size_array || pos2 < 0)
			{
			printf("Invalid insertion you must enter a value from 0 to %d\n", size_array);
			continue;
			}
	
			insert_array(pos2,stud);
			printlist_array(stud);
			break;
	   }
    
    case 2:
	{
		printf("the list after insertion \n ");
			printlist_array(stud);
			return 0;
	}
	
   }
 
	
   }
	}
	
break;
}
}
