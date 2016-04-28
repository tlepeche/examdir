/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 15:31:38 by tlepeche          #+#    #+#             */
/*   Updated: 2015/04/23 15:39:47 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	print(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		else
		{
			while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
			{
				ft_putchar(str[i]);
				i++;
			}
			break ;
		}
	}

}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		print(av[1]);
	}
	ft_putchar('\n');
	return (0);
}
