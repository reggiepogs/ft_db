#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <strings.h>
#include <string.h>
#include <errno.h>

void	showdatabases(void)
{
	
}

void	createdatabase(char *ui)
{
	printf("%s\n", "Enter Name");
	scanf("%s" ui);

}

int	main(void)
{
	char *ui;

	ui = (char *)malloc(sizeof(char) * 20);
	bzero(ui, 20);
	printf("%s\n", "(1)Show Databases : (2)Create New Database");
	scanf("%s", ui);
	if (atoi(ui) == 1)
		showdatabases();
	else if (atoi(ui) == 2)
		createdatabase();

}
