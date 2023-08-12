/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htassain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:37:21 by htassain          #+#    #+#             */
/*   Updated: 2023/08/12 17:37:27 by htassain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_check_param(int i, int j, int k)
{
	char	*argv[];

	i = 0;
	if (ft_strlen(argv[1]) == 31)
	{
		ft_check_argv();
		i = 0;
		j = 0;
		k = 0;
		while (argv[1][i] != '\0')
		{
			if (k > 3)
			{
				j++;
				k = 0;
			}
			if (argv[1][i] >= 1 && argv[1][i] <= 4)
			{
				ft_array_init();
				k++;
			}
			i++;
		}
	}
}

void	ft_array_init(void)
{
	int	tab_config[4][4];
	char *argv[];

	tab_config[4][4] = {0};
	tab_config[j][k] = argv[1][i];
}

void	ft_check_argv(void)
{
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] >= '1' && argv[1][i] <= '4')
		{
			argv[1][i] -= 48;
			i++;
		}
		else if (argv[1][i] == ' ')
			i++;
		else
		{
			write(1, "Error\n", 6);
			return (0);
		}
	}
}
