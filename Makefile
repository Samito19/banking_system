CC=gcc
CFLAGS=-g -D__USE_FIXED_PROTOTYPES__ -ansi -std=c99

main: main.c
	$(CC) $(CFLAGS) -o banking_app main.c modules/ui/ui.c modules/auth/login/login_window.c modules/auth/register/register_window.c && ./banking_app
clean: 
	rm -f banking_app
