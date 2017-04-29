#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <strings.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <unistd.h>
#include "./libft/libft.h"

void	opendatabase(char *ui)
{
	char *db;

	db = (char *)malloc(sizeof(char) * 20);
	printf("%s\n", "Enter Database Name");
	scanf("%s", db);

}

void	showdatabases(char *ui)
{
	struct	dirent *dp;
	DIR *dir = opendir("/nfs/2016/r/rnarciso/ft_db_github/databases");
	int status;

	if(dir != NULL)
	{
		while ((dp = readdir(dir)) != NULL)
			if (strcmp(dp->d_name, ".") && strcmp(dp->d_name, ".."))
				printf("%s\n", dp->d_name);
		closedir(dir);
	}
	printf("%s\n", "(1)Open Database : (2)Delete Database : (3)Return");
	scanf("%s", ui);
	if (atoi(ui) == 1)
	{
		opendatabase(ui);
	}
	else if (atoi(ui) == 2)
	{
		printf("%s\n", "Which Database?");
		scanf("%s", ui);
		status = rmdir(ft_strjoin("/nfs/2016/r/rnarciso/ft_db_github/databases/", ui));
	}
}

void	createdatabase(char *ui)
{
	int dir;

	printf("%s\n", "Enter Name");
	scanf("%s", ui);
	dir = mkdir(ft_strjoin("/nfs/2016/r/rnarciso/ft_db_github/databases/", ui) , 0777);
}

void	ft_db(void)
{
	char *ui;

	ui = (char *)malloc(sizeof(char) * 20);
	bzero(ui, 20);
	printf("%s\n", "(1)Show Databases : (2)Create New Database");
	scanf("%s", ui);
	if (atoi(ui) == 1)
		showdatabases(ui);
	else if (atoi(ui) == 2)
		createdatabase(ui);
	ft_db();

}
