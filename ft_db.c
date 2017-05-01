#include "ft_db.h"

void	opendatabase(char *ui)
{
	char *db;
	FILE *fp;
	struct dirent *dp;
	DIR *dir;
	char read[100];
	char *path;
	
	system("clear");
	path = ft_strjoin(getcwd(NULL, 0), "/databases/");
	db = (char *)malloc(sizeof(char) * 20);
	printf("%s\n", "Enter Database Name");
	scanf("%s", db);
	dir = opendir(ft_strjoin(path, db));
	db = ft_strjoin(db, "/");
	printf("%s\n", "(1)Open Data : (2)Add Data");
	scanf("%s", ui);
	if (atoi(ui) == 1)
	{
		if(dir != NULL)
		{
			while ((dp = readdir(dir)) != NULL)
			if (strcmp(dp->d_name, ".") && strcmp(dp->d_name, ".."))
				printf("%s\n", dp->d_name);
			closedir(dir);
		}
		printf("%s\n", "Which Data?");
		scanf("%s", ui);
		fp = fopen(ft_strjoin(path, ft_strjoin(db, ui)), "r");
		fseek(fp, SEEK_SET, 0);
		fread(read, 20, 1, fp);
		printf("%s\n", read);
		fclose(fp);
	}
	if (atoi(ui) == 2)
	{
		printf("%s\n", "Enter Name");
		scanf("%s", ui);
		fp = fopen(ft_strjoin(ft_strjoin(ft_strjoin(path, db), ui), ".txt"), "w");
		printf("%s\n", "Enter Value");
		scanf("%s", ui);
		fprintf(fp, "%s", ui);
		fclose(fp);

	}
}

void	showdatabases(char *ui)
{
	struct	dirent *dp;
	DIR *dir;
	int status;
	char *path;

	system("clear");
	path = ft_strjoin(getcwd(NULL, 0), "/databases/");
	dir = opendir(path);
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
		status = rmdir(ft_strjoin(path, ui));
	}
	else if (atoi(ui) == 3)
		ft_db();
}

void	createdatabase(char *ui)
{
	int dir;
	char * path;

	system("clear");
	path = ft_strjoin(getcwd(NULL, 0), "/databases/");
	printf("%s\n", "Enter Name");
	scanf("%s", ui);
	dir = mkdir(ft_strjoin(path, ui) , 0777);
	ft_db();
}

void	ft_db(void)
{
	char *ui;

	system("clear");
	ui = (char *)malloc(sizeof(char) * 20);
	bzero(ui, 20);
	printf("%s\n", "(1)Show Databases : (2)Create New Database");
	scanf("%s", ui);
	if (atoi(ui) == 1)
		showdatabases(ui);
	else if (atoi(ui) == 2)
		createdatabase(ui);
}
