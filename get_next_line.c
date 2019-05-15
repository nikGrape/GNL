/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 21:56:03 by vinograd          #+#    #+#             */
/*   Updated: 2019/05/14 19:24:19 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int i;

	i = 0;
	*line = (char*)malloc(BUFF_SIZE);
	while ((read(fd, &(*line)[i], 1) > 0) && i < BUFF_SIZE - 1)
	{
		if ((*line)[i] == '\n')
			break;
		i++;
	}
	(*line)[i - 1] = '\0';
	return (1);
}

int main()
{
	int i;
	int n;
	char *p;
	n = 0;
	i = open("text.txt", O_RDONLY);
	get_next_line(i, &p);
	while (n++ < 5)
	{
		get_next_line(i, &p);
		printf("%s\n", p);
	}
}

