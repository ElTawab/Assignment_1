#include<stdlib.h>
#include<stdio.h>
char garbage;
typedef struct
{
    char name[30];
    int ID;
    int birthdate[3];        //element #0 =day  element #2=month    element #3=year
    int score;              //score of last year of the student
}student;
int size_array=0;
void gather_data(student* node, int no_of_nodes)
{
    printf("enter the student %i name: ", no_of_nodes + 1);
    scanf("%c", &garbage, 1);
    scanf("%[^\n]", &node->name, 20);
    printf("\nenter the student %i ID: ", no_of_nodes + 1);
    scanf("%d", &node->ID);
    printf("enter the student %i score: ", no_of_nodes + 1);
    scanf("%d", &node->score);
    printf("please enter the birth date day/month/year\n");
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &node->birthdate[i]);
    }
    printf("the data of student %i has been entered sucessfuly\n", no_of_nodes + 1);
}
void insert_array(int index,student* stud)
{
    for (int i = 0; i <= size_array- index; i++)//shifting the elements after the insertion index.
    {
        *(stud + size_array + 1 - i) = *(stud + size_array- i);
    }
    gather_data(stud + index, index);
    size_array++;
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
int main()
{
     //Represents number of students.
    printf("Please enter the number of students initially registered on system\n");
    scanf("%d", &size_array);
    student* stud;//The head pointer
    stud = (student*)malloc(size_array);//Reserve dynamic array of initial size N
    int pos2; //The index of the element the will be inserted in the array
    for (int i = 0; i < size_array; i++)//A for loop to access The array elements
    {
        gather_data(stud + i, i);
    }
   printlist_array(stud);
    printf("please enter the insertion index from 0 to %d where 0 is the first element and %d is the last.\n", size_array, size_array);
    scanf("%d", &pos2);
    

   if (pos2 > size_array || pos2 < 0)
    {
        printf("Invalid insertion you must enter a value from 0 to %d\n", size_array);
        return 0;
    }
   insert_array(pos2,stud);
   printlist_array(stud);
    return 0;
}