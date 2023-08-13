/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col_check_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htassain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:25:38 by htassain          #+#    #+#             */
/*   Updated: 2023/08/13 11:25:42 by htassain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_col(int tab_config[4][4], int tab_solution[4][4], int i)
{
	int	j;
	int	count;
	int	current;

	count = 1;
	j = 0;
	current = tab_solution[0][i];
	while (j < 3)
	{
		if (current < tab_solution[j + 1][i])
		{
			current = tab_solution[j + 1][i];
			count++;
		}
		j++;
	}
	if (tab_config[0][i] != count)
	{
		return (0);
	}
	count = 1;
	current = tab_solution[3][i];
	while (j > 0)
	{
		if (current < tab_solution[j - 1][i])
		{
			current = tab_solution[j - 1][i];
			count++;
		}
		j--;
	}
	if (tab_config[1][i] == count)
		return (1);
	else
		return (0);
}

int	ft_check_line(int tab_config[4][4], int tab_solution[4][4], int j)
{
	int	i;
	int	count;
	int	current;

	count = 1;
	i = 0;
	current = tab_solution[j][0];
	while (i < 3)
	{
		if (current < tab_solution[j][i + 1])
		{
			current = tab_solution[j][i + 1];
			count++;
		}
		i++;
	}
	if (tab_config[2][j] != count)
	{
		return (0);
	}
	count = 1;
	current = tab_solution[j][3];
	while (i > 0)
	{
		if (current < tab_solution[j][i - 1])
		{
			current = tab_solution[j][i - 1];
			count++;
		}
		i--;
	}
	if (tab_config[3][j] == count)
		return (1);
	else
		return (0);
}
