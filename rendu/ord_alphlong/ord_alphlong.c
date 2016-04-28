/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 17:00:21 by tlepeche          #+#    #+#             */
/*   Updated: 2015/04/23 17:00:33 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int     ft_strlen(char *s)
{
	int i;

	i = 0;
	while(s[i])
		i++;
	return(i);
}

void    ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

int		is_space(char c)
{
	if (c == ' ' || c == '	')
		return (1);
	return (0);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

int		count_word(char *s)
{
	int	nb;

	nb = 0;
	while(is_space(*s) && *s)
		s++;
	while(*s)
	{
		while(!is_space(*s) && *s)
			s++;
		nb++;
		while(is_space(*s) && *s)
			s++;
	}
	return (nb);
}

void		print_tab(char **t)
{
	int		j;

	j = 0;
	while(t[j])
	{
		ft_putstr(t[j]);
		if (t[j+1] && ft_strlen(t[j]) != ft_strlen(t[j+1]))
				ft_putchar('\n');
		else if (t[j+1])
			ft_putchar(' ');
		j++;
	}
	ft_putchar('\n');
}

char		**ft_strsplit(char *s)
{
	char	**t;
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	t = (char **)malloc(sizeof(char **) * count_word(s) + 1);
	while(is_space(*s) && *s)
		s++;
	while (*s)
	{
		while(!is_space(s[i]) && s[i])
			i++;
		new = (char *)malloc(sizeof(char *) * i + i);
		i = 0;
		while(!is_space(s[i]) && s[i])
		{
			new[i] = s[i];
			i++;
		}
		new[i] = '\0';
		t[j] = new;
		new = NULL;
		i = 0;
		j++;
		while(!is_space(*s) && *s)
			s++;
		while(is_space(*s) && *s)
			s++;
	}
	t[j] = NULL;
	return (t);
}

char		ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return(c);
}

int			must_swp(char *s1, char *s2)
{
	if(ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while(*s1 && *s2 && ft_tolower(*s1) == ft_tolower(*s2))
	{
		s1++;
		s2++;
	}
	if (!*s1 || !*s2)
		return (0);
	if (ft_tolower(*s1) > ft_tolower(*s2))
		return (1);
	return (0);
}

void		sort(char **t)
{
	char	*swp;
	int		j;
	int		i;

	j = 0;
	i = 0;
	swp = NULL;
	while(t[j])
	{
		if (t[j + 1])
			if (ft_strlen(t[j]) > ft_strlen(t[j + 1]))
			{
				swp = t[j+1];
				t[j+1] = t[j];
				t[j] = swp;
				swp = NULL;
				i = 0;
			}
		j++;
		if (i == 0)
		{
			j = 0;
			i = 1;
		}
	}
	j = 0;
	while(t[j])
	{
		if (t[j + 1])
			if (must_swp(t[j], t[j + 1]))
			{
				swp = t[j+1];
				t[j+1] = t[j];
				t[j] = swp;
				swp = NULL;
				j = 0;
			}
		j++;
	}
	print_tab(t);
}

void	ord(char *s)
{
	char	**t;

	t = ft_strsplit(s);
	sort(t);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		ord(argv[1]);
	else
		ft_putchar('\n');
	return (0);
}
