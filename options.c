/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnarciso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:23:39 by rnarciso          #+#    #+#             */
/*   Updated: 2017/05/05 21:55:31 by rnarciso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	db_opt(char *ui, DIR *dir)
{
	int					status;
	char				*path;
	struct dirent		*dp;

	path = ft_strjoin(getcwd(NULL, 0), "/databases/");
	printf("%s\n", "(1)Open Database : (2)Delete Database : (3)Return");
	scanf("%s", ui);
	while (atoi(ui) < 1 || atoi(ui) > 3)
	{
		printf("Invalid Option\n");
		printf("(1)Open Database : (2)Delete Database : (3)Return\n");
		scanf("%s", ui);
	}
	if (atoi(ui) == 1)
		opendatabase(ui);
	else if (atoi(ui) == 2)
	{
		printf("%s\n", "Which Database?");
		scanf("%s", ui);
		path = ft_strjoin(path, ui);
		dir = opendir(path);
		if (dir == 0)
		{
			printf("Failed to Remove Database\n(1)Return : (2)Exit\n");
			scanf("%s", ui);
			while (atoi(ui) < 1 || atoi(ui) > 2)
			{
				printf("Invalid Option\n(1)Return : (2)Exit\n");
				scanf("%s", ui);
			}
			if (atoi(ui) == 1)
				showdatabases(ui);
			else
				exit(0);
		}
		while ((dp = readdir(dir)) != NULL)
		{
			if (strcmp(dp->d_name, ".") && strcmp(dp->d_name, ".."))
				status = remove(ft_strjoin(ft_strjoin(path, "/"), dp->d_name));
		}
		closedir(dir);
		status = rmdir(path);
		if (status == -1)
		{
			printf("Failed to Remove Database\n(1)Return : (2)Exit\n");
			scanf("%s", ui);
			while (atoi(ui) < 1 || atoi(ui) > 2)
			{
				printf("Invalid Option\n(1)Return : (2)Exit\n");
				scanf("%s", ui);
			}
			if (atoi(ui) == 1)
				showdatabases(ui);
			else
				exit(0);
		}
		else
		{
			printf("Delete Successful\n(1)Main Menu : (2)Exit\n");
			scanf("%s", ui);
			while (atoi(ui) < 1 || atoi(ui) > 2)
				printf("Invalid Option\n(1)Main Menu : (2)Exit\n");
			if (atoi(ui) == 1)
				ft_db();
			else
				exit(0);
		}
	}
	else if (atoi(ui) == 3)
		ft_db();
}

void	add_data(char *ui, char *path, char *db)
{
	FILE	*fp;

	printf("%s\n", "Enter Name");
	scanf("%s", ui);
	while (strlen(ui) > 20)
	{
		printf("Name too long\nEnter Name\n");
		scanf("%s", ui);
	}
	while (strchr(ui, '.'))
	{
		printf("Invalid Name\n");
		scanf("%s", ui);
	}
	fp = fopen(ft_strjoin(ft_strjoin(ft_strjoin(path, db), ui), ".txt"), "r");
	if (fp != NULL)
	{
		printf("Data already exist\n");
		add_data(ui, path, db);
	}
	fclose(fp);
	fp = fopen(ft_strjoin(ft_strjoin(ft_strjoin(path, db), ui), ".txt"), "w");
	printf("%s\n", "Enter Value");
	scanf("%s", ui);
	while (strlen(ui) > 20)
	{
		printf("Value too long\nEnter Value\n");
		scanf("%s", ui);
	}
	fprintf(fp, "%s", ui);
	fclose(fp);
	if (fp != NULL)
		printf("Data Creation Successful\n(1)Add New Data : (2)Main Menu\n");
	else
		printf("Data Creation Failed\n(1)Try Again : (2)Main Menu\n");
	scanf("%s", ui);
	while (atoi(ui) < 1 || atoi(ui) > 2)
	{
		printf("Invalid Option\n(1)Add New Data : (2)Main Menu\n");
		scanf("%s", ui);
	}
	if (atoi(ui) == 1)
		add_data(ui, path, db);
	else
		ft_db();
}

void	searchdata(char *ui, char *path, char *db)
{
	FILE	*fp;
	char	*read;

	read = (char *)malloc(sizeof(char) * 20);
	printf("%s\n", "Search for which Data?");
	scanf("%s", ui);
	ui = ft_strjoin(ui, ".txt");
	fp = fopen(ft_strjoin(path, ft_strjoin(db, ui)), "r");
	if (fp == NULL)
	{
		printf("Invalid Name\n");
		searchdata(ui, path, db);
	}
	fseek(fp, SEEK_SET, 0);
	while (fscanf(fp, "%s", read) != EOF)
		printf("%s\n", read);
	fclose(fp);
	printf("(1)Search : (2)Main Menu\n");
	scanf("%s", ui);
	while (atoi(ui) < 1 || atoi(ui) > 2)
	{
		printf("Invalid Option\n(1)Search : (2)Main Menu\n");
		scanf("%s", ui);
	}
	if (atoi(ui) == 1)
		searchdata(ui, path, db);
	else if (atoi(ui) == 2)
		ft_db();
}

void	data_opt(char *ui, char *db)
{
	FILE	*fp;
	char	*path;
	int		status;
	char	*read;

	read = (char *)malloc(sizeof(char) * 20);
	status = 0;
	path = ft_strjoin(getcwd(NULL, 0), "/databases/");
	printf("(1)Search Data : (2)Add Data : (3)Edit Data : ");
	printf("(4)Delete Data : (5)Main Menu : (6)Exit\n");
	scanf("%s", ui);
	while (atoi(ui) < 1 || atoi(ui) > 6)
	{
		printf("Invalid Option\n(1)Search Data : (2)Add Data : ");
		printf("(3)Edit Data : (4)Delete Data : (5)Main Menu : (6)Exit\n");
		scanf("%s", ui);
	}
	if (atoi(ui) == 1)
		searchdata(ui, path, db);
	if (atoi(ui) == 2)
	{
		db = ft_strjoin(db, "/");
		add_data(ui, path, db);
	}
	else if (atoi(ui) == 3)
	{
		printf("Which Data?\n");
		scanf("%s", ui);
		ui = ft_strjoin(ui, ".txt");
		fp = fopen(ft_strjoin(path, ft_strjoin(db, ui)), "r");
		if (fp == NULL)
		{
			printf("This Data does not exist\n(1)Add Data : (2)Main Menu\n");
			scanf("%s", ui);
			while (atoi(ui) < 1 || atoi(ui) > 2)
			{
				printf("Invalid Option\n(1)Add Data : (2)Main Menu\n");
				scanf("%s", ui);
			}
			if (atoi(ui) == 1)
				add_data(ui, path, db);
			else
				ft_db();
		}
		fseek(fp, SEEK_SET, 0);
		while (fscanf(fp, "%s", read) != EOF)
			printf("Current Data : %s\nReplace with?\n", read);
		fclose(fp);
		fp = fopen(ft_strjoin(ft_strjoin(path, db), ui), "w");
		scanf("%s", ui);
		while (strlen(ui) > 20)
		{
			printf("Value too long\nEnter Value\n");
			scanf("%s", ui);
		}
		fseek(fp, SEEK_SET, 0);
		fprintf(fp, "%s", ui);
		fclose(fp);
		printf("(1)Main Menu : (2)Exit\n");
		scanf("%s", ui);
		while (atoi(ui) < 1 || atoi(ui) > 2)
		{
			printf("Invalid Option\n(1)Main Menu : (2)Exit\n");
			scanf("%s", ui);
		}
		if (atoi(ui) == 1)
			ft_db();
		else
			exit(0);
	}
	else if (atoi(ui) == 4)
	{
		printf("Remove which Data?\n");
		scanf("%s", ui);
		ui = ft_strjoin(ui, ".txt");
		status = remove(ft_strjoin(ft_strjoin(path, db), ui));
		if (status == 0)
			printf("Delete Succesful\n(1)Main Menu : (2)Exit\n");
		else
			printf("Delete Failed\n(1)Main Menu : (2)Exit\n");
		scanf("%s", ui);
		while (atoi(ui) < 1 || atoi(ui) > 2)
		{
			printf("Invalid Option\n(1)Main Menu : (2)Exit\n");
			scanf("%s", ui);
		}
		if (atoi(ui) == 1)
			ft_db();
		else
			exit(0);
	}
	else if (atoi(ui) == 5)
		ft_db();
	else
		exit(0);
}
