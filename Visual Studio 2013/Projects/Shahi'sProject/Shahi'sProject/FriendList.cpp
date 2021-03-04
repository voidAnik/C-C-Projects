#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Users{

	char name[30];
	char location[20];
	int birthyear;
	struct Users *nextFriend;
	struct Users *next;
};

typedef struct Users node;

node *users = NULL;

void allUsers(){

	if (users->next == NULL){

		printf("There are no users!\n");
	}
	else{
		node *temp = users->next;
		while (temp != NULL){

			printf("%s\t", temp->name);
			node *temp2 = temp->nextFriend;
			while (temp2 != NULL){
				printf("%s\t", temp2->name);
				temp2 = temp2->nextFriend;
			}
			printf("\n");
			temp = temp->next;
		}
	}
}

void addUser(node *newUser){

	if (newUser->birthyear <= 2005){

		newUser->next = users->next;
		users->next = newUser;
	}
	else{

		printf("The user is not atleast 13\n");
		free(newUser);
	}
}

void addFriend(node *user1, node *user2){

	node *mainUser1 = NULL, *mainUser2 = NULL;
	node *temp = users->next;
	while ( temp != NULL){

		if ((strcmp(user2->name, temp->name) == 0) && (strcmp(user2->location, temp->location) == 0) && (user2->birthyear == temp->birthyear)){
			mainUser2 = temp;
		}
		else if ((strcmp(user1->name, temp->name) == 0) && (strcmp(user1->location, temp->location) == 0) && (user1->birthyear == temp->birthyear)){
			mainUser1 = temp;
		}
		if ((mainUser1 != NULL) && (mainUser2 != NULL)){
			break;
		}
		temp = temp->next;
	}
	temp = mainUser1->nextFriend;
	while ( temp != NULL){

		printf("test: %d\n", strcmp(user2->name, temp->name));
		if ((strcmp(user2->name, temp->name) == 0) && (strcmp(user2->location, temp->location) == 0) && (user2->birthyear == temp->birthyear)){

			printf("They are already friends\n");
			return;
		}
		temp = temp->nextFriend;
	}



	user1->nextFriend = mainUser2->nextFriend;
	mainUser2->nextFriend = user1;

	user2->nextFriend = mainUser1->nextFriend;
	mainUser1->nextFriend = user2;

}

int countFriends(node *user){

	int count = 0;
	node *temp = user->nextFriend;
	while (temp != NULL)
	{
		count++;
		temp = temp->nextFriend;
	}

	return count;
}

node* mostFriends(){

	node *maxFU = users->next;
	int max = 0;

	for (node *temp = users->next; temp != NULL; temp = temp->next){

		int noOfFrnd = countFriends(temp);
		if (noOfFrnd > max){

			max = noOfFrnd;
			maxFU = temp;
		}
	}

	return maxFU;
}

int totalUsers(){

	int count = 0;
	node *temp = users->next;
	while (temp != NULL){
		count++;
		temp = temp->next;
	}

	return count;
}

node* getUsers(){

	return users;
}

void removeUser(node *user){
	node *temp1 = users->next;
	while ( temp1 != NULL){

		node *temp2 = temp1;
		for (node *temp3 = temp1->nextFriend; temp3 != NULL; temp3 = temp3->nextFriend, temp2 = temp2->nextFriend){

			if ((strcmp(user->name, temp3->name) == 0) && (strcmp(user->location, temp3->location) == 0) && (user->birthyear == temp3->birthyear)){

				temp2->nextFriend = temp3->nextFriend;
				free(temp3);
				break;
			}
			temp1 = temp1->next;
		}
	}

	temp1 = users;
	node *temp2 = users->next;

	while ( temp2 != NULL){

		if ((strcmp(user->name, temp2->name) == 0) && (strcmp(user->location, temp2->location) == 0) && (user->birthyear == temp2->birthyear)){

			temp1->next = temp2->next;
			free(temp2);
			break;
		}
		temp2 = temp2->next;
		temp1 = temp1->next;
	}


}

void commonFriends(node *user1, node *user2){

	node *mainUser1 = NULL, *mainUser2 = NULL;
	node *commonFriends = (node*)malloc(sizeof(node));
	commonFriends->next = NULL;
	node *temp = users->next;
	while ( temp != NULL){

		if ((strcmp(user2->name, temp->name) == 0) && (strcmp(user2->location, temp->location) == 0) && (user2->birthyear == temp->birthyear)){
			mainUser2 = temp;
		}
		else if ((strcmp(user1->name, temp->name) == 0) && (strcmp(user1->location, temp->location) == 0) && (user1->birthyear == temp->birthyear)){
			mainUser1 = temp;
		}
		if ((mainUser1 != NULL) && (mainUser2 != NULL))
			break;
		temp = temp->next;
	}
	node *temp1 = mainUser1->nextFriend;
	while ( temp1 != NULL){
		node *temp2 = mainUser2->nextFriend;
		while ( temp2 != NULL ){

			if ((strcmp(temp1->name, temp2->name) == 0) && (strcmp(temp1->location, temp2->location) == 0) && (temp1->birthyear == temp2->birthyear)){

				node *temp3 = (node*)malloc(sizeof(node));
				strcpy_s(temp3->name, temp1->name);
				strcpy_s(temp3->location, temp1->location);
				temp3->birthyear = temp1->birthyear;
				temp3->next = commonFriends->next;
				commonFriends->next = temp3;
			}
			temp2 = temp2->nextFriend;
		}
		temp1 = temp1->nextFriend;
	}
	if (commonFriends->next == NULL){
		printf("No Common Friends\n");
		return;
	}
	printf("Common Friends between %s and %s: ", user1->name, user2->name);
	for (node *temp = commonFriends->next; temp != NULL; temp = temp->next)
		printf("%s\t", temp->name);
	printf("\n");
}

void OldestFriends(){

	printf("\n\nName\t\tOldest friend\n\n");
	node *temp1 = users->next;
	while ( temp1 != NULL ){

		node *dummy = temp1->nextFriend;
		if (dummy != NULL){
			for (node *temp2 = temp1->nextFriend; temp2 != NULL; temp2 = temp2->nextFriend){

				if (dummy->birthyear > temp2->birthyear)
					dummy = temp2;
			}
			printf("%s\t\t%s\n", temp1->name, dummy->name);
		}
		else{

			printf("%s\t\tNo friends\n", temp1->name);
		}
		temp1 = temp1->next;

	}

}

void optionDisplay(){

	printf("\n\nEnter 1 to see all users\n");
	printf("Enter 2 to add an user\n");
	printf("Enter 3 to add friends\n");
	printf("Enter 4 to see total users\n");
	printf("Enter 5 to see user who has maximum friends\n");
	printf("Enter 6 to remove an user\n");
	printf("Enter 7 to see oldest friends\n");
	printf("Enter 8 to see common friends\n\n");
}


node* setUserAndGet(){

	node *user = (node*)malloc(sizeof(node));
	getchar();
	printf("Name: ");
	gets_s(user->name);
	printf("Location: ");
	gets_s(user->location);
	printf("Birthyear: ");
	scanf_s("%d", &user->birthyear);

	user->nextFriend = NULL;

	return user;
}


void selection(){

	int option;
	node *temp, *temp1, *temp2;
	do{

		optionDisplay();
		scanf_s("%d", &option);

	    if (option == 1)
		{
			allUsers();
		}
		else if (option == 2)
		{
			temp = setUserAndGet();
			addUser(temp);
		}
		else if (option == 3)
		{
			printf("For first friend\n");
			temp1 = setUserAndGet();

			printf("For second friend\n");
			temp2 = setUserAndGet();

			addFriend(temp1, temp2);
		}

		else if (option == 4)
		{
			printf("\n\nTotal Users: %d\n\n", totalUsers());
		}
		else if (option == 5)
		{
			printf("\n\nName: %s\n\n", mostFriends()->name);
		}
		else if (option == 6)
		{
			temp = setUserAndGet();
			removeUser(temp);
		}
		else if (option == 7)
		{
			OldestFriends();
		}
		else if (option == 8)
		{
			printf("For first friend\n");
			temp1 = setUserAndGet();

			printf("For second friend\n");
			temp2 = setUserAndGet();
			commonFriends(temp1, temp2);
		}
		else
		{
			printf("Invalid Option!\n");
		}
	} while (option != 0);
}

void main() {

	users = (node*)malloc(sizeof(node));
	users->next = NULL;

	selection();

}