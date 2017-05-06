/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnarciso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:23:31 by rnarciso          #+#    #+#             */
/*   Updated: 2017/05/05 17:23:34 by rnarciso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DB_H
# define FT_DB_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <strings.h>
# include <string.h>
# include <errno.h>
# include <dirent.h>
# include <unistd.h>
# include "./libft/libft.h"

void	ft_db(void);
void	db_opt(char *ui, DIR *dir);
void	opendatabase(char *ui);
void	showdatabases(char *ui);
void	data_opt(char *ui, char *db);
#endif
