/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 19:42:17 by kulrike           #+#    #+#             */
/*   Updated: 2021/05/17 20:22:14 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libasm.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main(void)
{
	char *str_ft_strlen = "HHHHhehsfghsthsrthrth";
	char *str_ft_strcpy_dst = "Hello World";
	char *str_ft_strcpy_src = (char *)malloc(sizeof(char) * strlen(str_ft_strcpy_dst));
	char *str_ft_strcmp_dst = "Hello world";
	char *str_ft_strcmp_src = "Hello World";
	int opn = open ("file", O_RDONLY);
	char buff[100];
	char *str_ft_strdup = "this is strdup str";
	char *malloc_test;


	printf("#####################################"ANSI_COLOR_BLUE" START "ANSI_COLOR_RESET"##################################################\n\n");
	printf("################################\n");
	printf("##########"ANSI_COLOR_RED" FT_STRLEN "ANSI_COLOR_RESET"###########\n");
	printf("################################\n");
	printf("\n");
	printf(ANSI_COLOR_GREEN"ft_strlen returns -> %zu\n"ANSI_COLOR_RESET,ft_strlen(str_ft_strlen));
	printf(ANSI_COLOR_YELLOW"strlen returns    -> %zu\n" ANSI_COLOR_RESET,strlen(str_ft_strlen));
	printf("\n");
	printf("################################\n");
	printf("##########"ANSI_COLOR_RED" FT_STRCPY "ANSI_COLOR_RESET"###########\n");
	printf("################################\n");
	printf("\n");
	printf(ANSI_COLOR_GREEN "ft_strcpy returns -> %s\n"ANSI_COLOR_RESET, ft_strcpy(str_ft_strcpy_src, str_ft_strcpy_dst));
	printf(ANSI_COLOR_YELLOW"strcpy returns    -> %s\n"ANSI_COLOR_RESET, strcpy(str_ft_strcpy_src, str_ft_strcpy_dst));
	printf("\n");
	printf("################################\n");
	printf("##########"ANSI_COLOR_RED" FT_STRCMP "ANSI_COLOR_RESET"###########\n");
	printf("################################\n");
	printf("\n");
	printf(ANSI_COLOR_GREEN"ft_strcmp returns -> %d\n"ANSI_COLOR_RESET, ft_strcmp(str_ft_strcmp_src,str_ft_strcmp_dst));
	printf(ANSI_COLOR_YELLOW"strcmp returns    -> %d\n"ANSI_COLOR_RESET, strcmp(str_ft_strcmp_src,str_ft_strcmp_dst));	
	printf("\n");
	printf("################################\n");
	printf("###########"ANSI_COLOR_RED" FT_WRITE "ANSI_COLOR_RESET"###########\n");
	printf("################################\n");
	printf("\n");
	ft_write(1, "ft_write returns this str\n" ,27);
	write(1,"write returns this str\n",24);
	printf("\n");
	printf("################################\n");
	printf("###########"ANSI_COLOR_RED" FT_READ "ANSI_COLOR_RESET"############\n");
	printf("################################\n");
	printf("\n");
	printf(ANSI_COLOR_GREEN"ft_read returns -> %d\n"ANSI_COLOR_RESET, ft_read(opn, buff, 100));
	close(opn);
	opn = open ("file", O_RDONLY);
	printf(ANSI_COLOR_YELLOW"read returns    -> %zd\n"ANSI_COLOR_RESET, read(opn, buff, 100));
	close(opn);
	printf("\n");
	printf("################################\n");
	printf("##########"ANSI_COLOR_RED" FT_STRDUP "ANSI_COLOR_RESET"###########\n");
	printf("################################\n");
	printf("\n");
	printf(ANSI_COLOR_GREEN"ft_strdup returns -> %s\n"ANSI_COLOR_RESET, ft_strdup(str_ft_strdup));
	printf(ANSI_COLOR_YELLOW"strdup returns    -> %s\n"ANSI_COLOR_RESET, strdup(str_ft_strdup));	
	printf("\n");
	printf("######################################"ANSI_COLOR_BLUE" END "ANSI_COLOR_RESET"###################################################\n");
		
	return (0);
}
