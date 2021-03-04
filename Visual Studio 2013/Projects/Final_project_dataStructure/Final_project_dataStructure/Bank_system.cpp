////Library including
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//////////////////////////

//Structure for person info
struct info{
	char name[50];
	char id[20];
	char join_year[50];
	char phone[50];
	char email[50];
	char type[50];
	float salary;
};

//Structure for LIST
struct node{
	struct info employee;
	struct node *next;

}*head;

//Creating new node
struct node* create_node()
{
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->next = NULL;
	return temp;
}

//checking validity (if digit or not)
int isValid(char data[])
{
	for (int i = 0; i < strlen(data); i++)
	{
		if (!isdigit(data[i]))
		{
			return 0;
		}
	}
	return 1;

}

//Checking if id is already used once
int isUsed(char id[])
{
	struct node *temp = head;
	while (temp != NULL)
	{
		if (strcmp(temp->employee.id, id) == 0)
		{
			return 1;
		}
	}
	return 0;
}
//Method for adding information
void add()
{
	struct node *temp = create_node();

	printf("\nEmployee name::");
	gets_s(temp->employee.name);

	while (1)//Checking ID validation
	{
		printf("\nEmployee id:(Should be five numbers):");
		gets_s(temp->employee.id);
		if (strlen(temp->employee.id) != 5 || !isValid(temp->employee.id))
		{
			puts("WRONG ID TYPE!! :-(");
		}
		/*else if (isUsed(temp->employee.id))
		{
			puts("This ID is already used!");
		}*/
		else
		{
			break;
		}
	}

	while (true)//Checking Number validation
	{
		printf("\nEmployee Phone number:(Should be 11 digit numbers):");
		gets_s(temp->employee.phone);
		if (strlen(temp->employee.phone) != 11 || !isValid(temp->employee.phone))
		{
			puts("WRONG NUMBER TYPE!! :-(");
		}
		else
		{
			break;
		}
	}
	printf("\nEmployee Email address :: ");
	gets_s(temp->employee.email);

	while (true)//Checking Year validation
	{
		printf("\nemployee join year::");
		gets_s(temp->employee.join_year);
		if (strlen(temp->employee.join_year) != 4 || !isValid(temp->employee.join_year))
		{
			puts("WRONG TYPE!! :-(");
		}
		else
		{
			break;
		}
	}
	while (true)//Checking Class type validation
	{
		printf("\nemployee Class type:(1st,2nd.3rd):");
		gets_s(temp->employee.type);
		if (strcmp(temp->employee.type, "1st") == 0)
		{
			temp->employee.salary = 80000;
			break;
		}
		else if (strcmp(temp->employee.type, "2nd") == 0)
		{
			temp->employee.salary = 45000;
			break;
		}
		else if ((strcmp(temp->employee.type, "3rd") == 0))
		{
			temp->employee.salary = 15000;
			break;
		}
		else
		{
			puts("WRONG CLASS TYPE!! :-(");
		}
	}

	if (head == NULL)
	{
		head = temp;
		head->next = NULL;
	}
	else
	{
		temp->next = head;
		head = temp;
	}
	puts("New employee added in DATABASE successfully!!!");
}

void print(struct info employee)
{
	printf("Name:");
	puts(employee.name);
	printf("ID:");
	puts(employee.id);
	printf("Email:");
	puts(employee.email);
	printf("Contact Number:");
	puts(employee.phone);
	printf("Joined year:");
	puts(employee.join_year);
	printf("Salary per month:");
	printf(" %.2fTK\n", employee.salary);

}

//Showing Information
void show()
{
	struct node *temp = head;
	int number = 0;
	puts("1st Class employee:");
	while (temp != NULL)
	{
		if (strcmp(temp->employee.type, "1st") == 0)
		{
			printf(" %d.\n", ++number);
			print(temp->employee);
		}
		temp = temp->next;
	}
	puts("\n2nd Class employee:");
	number = 0;
	temp = head;
	while (temp != NULL)
	{
		if (strcmp(temp->employee.type, "2nd") == 0)
		{
			printf(" %d.\n", ++number);
			print(temp->employee);
		}
		temp = temp->next;
	}
	puts("\n3rd Class employee:");
	number = 0;
	temp = head;
	while (temp != NULL)
	{
		if (strcmp(temp->employee.type, "3rd") == 0)
		{
			printf(" %d.\n", ++number);
			print(temp->employee);
		}
		temp = temp->next;
	}
}

//Searching employee information by ID
void searchById(char id[])
{
	struct node *temp = head;
	while (temp != NULL)
	{
		if (strcmp(temp->employee.id, id) == 0)
		{
			puts("Searched Information:");
			print(temp->employee);
			break;
		}
	}
}

//showing all in same joined year
void searchByYear(char year[])
{
	struct node *temp = head;
	while (temp != NULL)
	{
		if (strcmp(temp->employee.join_year, year) == 0)
		{
			print(temp->employee);
		}
	}
}

//Removing an employee's information from DATABASE
void deletee(char id[])
{
	struct node *temp = head;
	struct node *prev = head;

	while (temp != NULL)
	{
		if (strcmp(temp->employee.id, id) == 0)
		{
			print(temp->employee);
			int sure;
			puts("Sure to delete this info.");
			puts("1.YES.");
			puts("2.NO.");
			scanf_s("%d", &sure);
			getchar();
			if (sure == 1)
			{
				if (strcmp(head->employee.id, id) == 0)
				{
					head = temp->next;
					free(temp);
				}
				else
				{
					prev->next = temp->next;
					free(temp);
				}
				puts("Deleted info successfully");
				break;
			}
			if (sure == 2)
			{
				break;
			}
		}
		prev = temp;
		temp = temp->next;
	}
}

void main()
{
	char choice[50];
	while (true)
	{
		puts("|||||||||||||||||||||||||||||||\n");
		puts("Type 'add' to add new employee informations in DATABASE!");
		puts("Type 'show' to show all employee list in the bank!");
		puts("Type 'search' to search any employee info from the bank!");
		puts("Type 'delete' to delete an employee from DATABASE");
		puts("Type 'exit' to exit from the DATABASE");
		puts("|||||||||||||||||||||||||||||||\n");

		scanf_s("%s", &choice, sizeof(choice));
		getchar();
		if (strcmp(choice, "add") == 0)
		{
			add();
			puts("");
		}
		else if (strcmp(choice, "show") == 0)
		{
			show();
			puts("");
		}
		else if (strcmp(choice, "search") == 0)
		{
			puts("1.Search by ID.");
			puts("2.Search by joined Year(Show all in same year).");
			int search_choice;
			scanf_s("%d", &search_choice);
			getchar();
			if (search_choice == 1)
			{
				printf("Enter ID to search:");
				char temp_id[20];
				gets_s(temp_id);
				searchById(temp_id);
			}
			else if (search_choice == 2)
			{
				printf("Enter Year to search:");
				char temp_year[10];
				gets_s(temp_year);
				searchByYear(temp_year);
			}
			else
			{
				puts("Invalid choice!");
			}
			puts("");
		}
		else if (strcmp(choice, "delete") == 0)
		{
			printf("Enter ID to search and delete:");
			char temp_id[20];
			gets_s(temp_id);
			deletee(temp_id);
		}
		else if (strcmp(choice, "exit") == 0)
		{
			puts("BYE!");
			exit(1);
		}
		else
		{
			puts("Invalid choice!");
		}
	}
}