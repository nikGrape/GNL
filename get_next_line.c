/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 21:56:03 by vinograd          #+#    #+#             */
/*   Updated: 2019/05/21 17:11:49 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(const int fd, char **line)
{
	char			*p_n;
	char			*tmp;
	char			*str;
	char			buf[BUFF_SIZE + 1];
	static char		rest[BUFF_SIZE];
	int				r;

	p_n = NULL;
	if (fd < 0)
		return (-1);
	if ((p_n = ft_strchr(rest, '\n')) != NULL)
	{
		str = ft_strsub(rest, 0, p_n - rest);
		ft_strcpy(rest, ++p_n);
	}
	else
	{
		str = ft_strnew(ft_strlen(rest) + 1);
		ft_strcat(str, rest);
		ft_strclr(rest);
	}
	while (p_n == 0 && ((r = read(fd, buf, BUFF_SIZE))))
	{
		buf[r] = '\0';
		if ((p_n = ft_strchr(buf, '\n')) != NULL)
		{
			ft_strcpy(rest, ++p_n);
			ft_strclr(--p_n);
		}
		tmp = str;
		if (!(str = ft_strnew(ft_strlen(tmp) + BUFF_SIZE + 1)) || r < 0)
			return (-1);
		ft_strcat(str, tmp);
		ft_strdel(&tmp);
		ft_strcat(str, buf);
		ft_strclr(buf);
		if (p_n != NULL || r == 0)
			break ;
	}
	*line = str;
	//if (r < 0)
	//	return (-1);
	return (ft_strlen(str) ? 1 : 0);
}

int			main(void)
{
	int		fd;
	char	*p;
	int		i;
	int		ret;

	i = 0;
	ret = 1;
	fd = open("text.txt", O_RDONLY);
	while (ret > 0)
	{
		ret = get_next_line(fd, &p);
		printf("%s\t%d\n", p, ret);
		i++;
	}
	close(fd);
}
