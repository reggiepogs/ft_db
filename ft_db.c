/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnarciso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:23:15 by rnarciso          #+#    #+#             */
/*   Updated: 2017/05/05 22:11:48 by rnarciso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	opendatabase(char *ui)
{
	char			*db;
	FILE			*fp;
	struct dirent	*dp;
	DIR				*dir;
	char			*read;
	char			*path;
	int				i;

	read = (char *)malloc(sizeof(char) * 20);
	path = ft_strjoin(getcwd(NULL, 0), "/databases/");
	db = (char *)malloc(sizeof(char) * 20);
	printf("%s\n", "Enter Database Name");
	scanf("%s", db);
	dir = opendir(ft_strjoin(path, db));
	if (dir == NULL)
	{
		printf("No Database Found by that name\n");
		printf("(1)Try Again : (2)Main Menu\n");
		scanf("%s", ui);
		if (atoi(ui) == 1)
			opendatabase(ui);
		else if (atoi(ui) == 2)
			ft_db();
	}
	if (dir != NULL)
	{
		printf("\n%s:\n", db);
		db = ft_strjoin(db, "/");
		while ((dp = readdir(dir)) != NULL)
		{
			i = 0;
			if (strcmp(dp->d_name, ".") && strcmp(dp->d_name, ".."))
			{
				while (dp->d_name[i] != '.')
				{
					putchar(dp->d_name[i]);
					i++;
				}
				fp = fopen(ft_strjoin(path, ft_strjoin(db, dp->d_name)), "r");
				fseek(fp, SEEK_SET, 0);
				while (fscanf(fp, "%s", read) != EOF)
					printf(" = %s\n", read);
				fclose(fp);
			}
		}
		ft_putchar('\n');
		closedir(dir);
	}
	data_opt(ui, db);
}

void	showdatabases(char *ui)
{
	struct dirent	*dp;
	DIR				*dir;
	int				ifempty;

	ifempty = 0;
	dir = opendir(ft_strjoin(getcwd(NULL, 0), "/databases/"));
	if (dir != NULL)
	{
		printf("\nDatabases:\n");
		while ((dp = readdir(dir)) != NULL)
			if (strcmp(dp->d_name, ".") && strcmp(dp->d_name, ".."))
			{
				printf("%s\n", dp->d_name);
				ifempty++;
			}
		printf("\n");
		closedir(dir);
		if (ifempty == 0)
		{
			printf("No Database Saved\n");
			ft_db();
		}
	}
	db_opt(ui, dir);
}

void	createdatabase(char *ui)
{
	int		dir;
	char	*path;

	path = ft_strjoin(getcwd(NULL, 0), "/databases/");
	printf("%s\n", "Enter Name");
	scanf("%s", ui);
	while (strlen(ui) > 20)
	{
		printf("Name too long\nEnter Name\n");
		scanf("%s", ui);
	}
	dir = mkdir(ft_strjoin(path, ui), 0777);
	if (dir == -1)
	{
		printf("Name already exist\n");
		createdatabase(ui);
	}
	ft_db();
}

void	ft_db(void)
{
	char	*ui;

	ui = (char *)malloc(sizeof(char) * 20);
	bzero(ui, 20);
	printf("%s\n", "(1)Show Databases : (2)Create New Database : (3)Exit");
	scanf("%s", ui);
	while (atoi(ui) < 1 || atoi(ui) > 3)
	{
		printf("Invalid Option\n");
		printf("(1)Show Databases : (2)Create New Database : (3)Exit\n");
		scanf("%s", ui);
	}
	if (atoi(ui) == 1)
		showdatabases(ui);
	else if (atoi(ui) == 2)
		createdatabase(ui);
	else if (atoi(ui) == 3)
		exit(0);
	else
		ft_db();
}
