#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_USERNAME_LENGTH 11
#define MAX_PASSWORD_LENGTH 20
#define EQUAL 0

bool validate_credentials(char*, char*);

/* This module is responsible for handling user login */
bool login_window(){
	
	/*Collect user's username */
	char *username = malloc(MAX_USERNAME_LENGTH * sizeof(char));
	printf("Enter your username: ");
	fgets(username, MAX_USERNAME_LENGTH, stdin);	
	username[strcspn(username, "\n")] = '\0'; 	/* Clean the username string by removing the newline character */

	/* Collect user's password */
	char *password = malloc(MAX_PASSWORD_LENGTH * sizeof(char));
	printf("Enter your password: ");
	fgets(password, MAX_PASSWORD_LENGTH, stdin);
	password[strcspn(password, "\n")] = '\0'; 
	
	bool valid_credentials = validate_credentials(username, password);
	
	/* Free array's space in memory */
	free(username);
	free(password);
	
	return valid_credentials; 
}

// TODO Eventually this function will take care of validating the credentials entered by user with the database 
bool validate_credentials(char *username, char *password){
	if ((strcmp(username, "Sami") == EQUAL) && (strcmp(password, "Sami") == EQUAL))
		return true;
	return false;
}
