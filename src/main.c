#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "modules/ui/ui.h"
#include "modules/auth/login/login_window.h"
#include "modules/auth/register/register_window.h"

#define EQUAL 0
#define GREEN_COLOR "\033[0;32m"
#define RED_COLOR "\033[0;31m"
#define WHITE_COLOR "\033[0m"

int main(){
	window_header();
	printf("\n");

	printf("Would you like to register an account or login (register/login/quit): ");
	const int max_answer_len = 9;		// Since register is the longest word with 8 letters we use its length for safety + \0
	char *user_answer = malloc(max_answer_len * sizeof(char));
	fgets(user_answer, max_answer_len, stdin);
	user_answer[strcspn(user_answer, "\n")] = '\0';

	bool valid_credentials;
	
	/* Leave the program if user chooses quit */
	if (strcmp(user_answer, "quit") == EQUAL) {
		printf("Thank you for using your services, hope to see you soon !\n");
		return 0;
	} else if (strcmp(user_answer, "register") == EQUAL) {
		printf("Let's get you registered!\n");
		register_window();
	} else if (strcmp(user_answer, "login") == EQUAL) {
		printf("\n");
		valid_credentials = login_window();
		char *color= (valid_credentials) ? GREEN_COLOR : RED_COLOR;
		printf("Credentials are %s %s %s\n", color, valid_credentials ? "valid" : "invalid", WHITE_COLOR);
	} else {
		printf("%sPlease choose a valid option ! %s\n", RED_COLOR, WHITE_COLOR);
	}
	
	sleep(5);
	system("clear");
	window_header();

	return 0;
}
