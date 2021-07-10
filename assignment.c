#include<stdlib.h>
#include<stdio.h>
#include<time.h>
char garbage;
int no_of_students;
int size = 0;

typedef struct
{
    char name[30];
    int birthdate[3];        //element #0 =day  element #2=month    element #3=year
    int score; //score of last year of the student
    int ID;
}student;



struct Node {
	struct Node* next;
        student stu;

};

struct Node* head = NULL;
struct Node* tail = NULL;

void gather_data(struct Node* node)
{

    printf("enter the student %i name: ", size + 1);
	scanf("%c", &garbage, 1);
	scanf("%[^\n]", &node->stu.name, 20);
	printf("enter the student %i ID: ", size + 1);
	scanf("%d", &node->stu.ID);
	printf("enter the student %i score: ", size + 1);
	scanf("%d", &node->stu.score);
	for (int i = 0; i < 3; i++)
    {
        scanf("%d", &node->stu.birthdate[i]);
    }
	printf("the data of student %d has been entered sucessfuly\n\n", size + 1);



}
void printlist()
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


void insert_linkedlist(int index)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
   gather_data(new_node);
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
	    else if ( index == size +1 )
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
			
	size++;
	return;
}


int main()
{
	int key;
	printf("The size of structure %d\n", sizeof(student));
	printf("The size of node %d\n", sizeof(struct Node));
	int pos;
	printf("enter the number of students to create your list initially: ");
	scanf("%d", &no_of_students);



    
	for (int i = 0; i < no_of_students; i++)
	{
		insert_linkedlist(size+1);

	}
	printf("the list before insertion\n");
	for (struct Node* temp2 = head; temp2 != NULL; temp2 = temp2->next)
	{

		printlist();
	}
	while (1)
	{

		printf("type 1 to insert: \n type 2 to exit: \n");
		scanf("%d", &key);

		switch (key)
		{
		case 1:
		{
		    printf("Enter 1 to insert at head, or %i to insert at tail or other in between\n", size+1);
			printf("Enter the index:");
			scanf("%d", &pos);
			insert_linkedlist(pos);
			printlist();
			break;
		}
		case 2:
		{
			printf("the list after insertion \n ");
			printlist();
			return 0;
		}
		
		}
		



	}
	
}
