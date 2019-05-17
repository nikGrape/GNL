/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 21:56:03 by vinograd          #+#    #+#             */
/*   Updated: 2019/05/16 23:01:27 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int len;
	char *p_n;
	char *tmp;
	char *str;
	char buf[BUFF_SIZE + 1];
	int ret;
	
	ret = 0;
	len = 0;
	str = ft_strnew(1);
	while (read(fd, buf, BUFF_SIZE) > 0)
	{	
		buf[BUFF_SIZE] = '\0';
		
		tmp = str;
		str = ft_strnew(len + BUFF_SIZE + 1);
		len = ft_strlen(str);
		ft_strcpy(str, tmp);
		ft_strdel(&tmp);
		ft_strcat(str, buf);	
		if ((p_n = ft_strchr(buf, '\n')) != 0)
			break;
		ft_strclr(buf);
	}
	*line = str;
	return (ret);
}

int main()
{
	int fd;
	char *p;
	char str[50];
	
	fd = open("text.txt", O_RDONLY);
	//read(fd, str, 20); 
	//str[20] = '\0';
	get_next_line(fd, &p);
	printf("%s\n", p);
	
}