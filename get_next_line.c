/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 21:56:03 by vinograd          #+#    #+#             */
/*   Updated: 2019/05/17 20:36:35 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	char	*p_n;
	char	*tmp;
	char	*str;
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		len;

	ret = 0;
	len = 0;
	str = ft_strnew(1);
	p_n = NULL;
	while (read(fd, buf, BUFF_SIZE) > 0)
	{
		buf[BUFF_SIZE] = '\0';
		if ((p_n = ft_strchr(buf, '\n')) != 0)
			ft_strclr(p_n);
		tmp = str;
		len = ft_strlen(str);
		str = ft_strnew(len + BUFF_SIZE + 1);
		ft_strcpy(str, tmp);
		ft_strdel(&tmp);
		ft_strcat(str, buf);
		if (p_n != 0)
			break ;
		ft_strclr(buf);
	}
	*line = str;
	return (ret);
}
/*
int		main(void)
{
	int		fd;
	char	*p;
	int		i;

	i = 0;
	fd = open("text.txt", O_RDONLY);
	while (i < 5)
	{
		get_next_line(fd, &p);
		printf("%s\n", p);
		i++;
	}
}*/

