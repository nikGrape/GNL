/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 21:56:03 by vinograd          #+#    #+#             */
/*   Updated: 2019/05/17 21:44:51 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	char			*p_n;
	char			*tmp;
	char			*str;
	char			buf[BUFF_SIZE + 1];
	static char		rest[BUFF_SIZE];
	int				ret;
	int				len;
	int 			rest_len;

	rest_len = ft_strlen(rest);
	ret = 0;
	len = 0;
	str = ft_strnew(rest_len);
	ft_strcat(str, rest);
	p_n = NULL;
	while (read(fd, buf, BUFF_SIZE) != 0)
	{
		buf[BUFF_SIZE] = '\0';
		if ((p_n = ft_strchr(buf, '\n')) != 0)
		{
			ret = 1;
			ft_strcpy(rest, ++p_n);
			ft_strclr(--p_n);
		}
		tmp = str;
		len = ft_strlen(str);
		str = ft_strnew(len + BUFF_SIZE + 1);
		if (str == NULL)
			return (-1);
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

int		main(void)
{
	int		fd;
	char	*p;
	int		i;
	int		ret = 1;

	i = 0;
	fd = open("text.txt", O_RDONLY);
	while (ret > 0)
	{
		ret = get_next_line(fd, &p);
		printf("%s%d\n", p, ret);
		i++;
	}
}

