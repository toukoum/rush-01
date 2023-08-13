/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:29:04 by rgiraud           #+#    #+#             */
/*   Updated: 2023/08/13 10:52:32 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_check_col(int tab_config[4][4], int tab_solution[4][4], int i);
int	ft_check_line(int tab_config[4][4], int tab_solution[4][4], int j);
int	main(int argc, char const *argv[]);

void	ft_display_solution(int tab_solution[4][4])
{
	int	j;
	int	i;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (i == 3)
			{
				printf("%d", tab_solution[j][i]);
			}
			else
			{
				printf("%d ", tab_solution[j][i]);
			}
			i++;
		}
		printf("\n");
		j++;
	}
}

/* 1er while : Vérifiez si le numéro existe déjà dans la même ligne */
	/* if >> Le numéro existe déjà dans la ligne */
/* 2e while :Vérifiez si le numéro existe déjà dans la même colonne */
	/* if >> Le numéro existe déjà dans la colonne */
/* Si on atteind le return (1) a la fin, toutes les vérifications ont réussi */
int	ft_check_board_duplicate(int tab_solution[4][4], int num, int i, int j)
{
	int	k;

	k = 0;
	while (k < 4)
	{
		if (tab_solution[j][k] == num)
		{
			return (0);
		}
		k++;
	}
	k = 0;
	while (k < 4)
	{
		if (tab_solution[k][i] == num)
		{
			return (0);
		}
		k++;
	}
	return (1);
}

void	ft_fill_board(int tab_config[4][4], int tab_solution[4][4], int i,
		int j)
{
	int	num;
	int	next_i;
	int	next_j;

	if (tab_solution[3][3] != 0)
	{
		ft_display_solution(tab_solution);
		return ;
	}
	next_i = i + 1;
	next_j = j;
	if (next_i == 4)
	{
		next_i = 0;
		next_j++;
	}
	num = 1;
	while (num < 5)
	{
		if (ft_check_board_duplicate(tab_config, tab_solution, num, i, j))
		{
			tab_solution[j][i] = num;
			if ((i < 3 || ft_check_line(tab_config, tab_solution, j)) && (j < 3
					|| ft_check_col(tab_config, tab_solution, i)))
			{
				ft_fill_board(tab_config, tab_solution, next_i, next_j);
			}
			tab_solution[j][i] = 0;
		}
		num++;
	}
}

void	ft_rush_main(void)
{
	int	tab_solution[4][4];
	int	tab_config[4][4];

	tab_config[4][4] = {{1, 3, 3, 4}, {2, 1, 2, 4}, {1, 3, 3, 2}, {2, 1, 2, 3}};
	tab_solution[4][4] = {0};
	ft_fill_board(tab_config, tab_solution, 0, 0);
}
/* 
if (ft_check_board_duplicate(tab_config, tab_solution, num, i, j) &&
	((i != 3 || ft_check_line(tab_config, tab_solution, j)) &&
		(j != 3 || ft_check_col(tab_config, tab_solution, i))))
	{
		tab_solution[j][i] = num;
		ft_fill_board(tab_config, tab_solution, next_i, next_j);
		tab_solution[j][i] = 0;
	}*/
