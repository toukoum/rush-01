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

void ft_display_solution(int tab_solution[4][4]) {
    int j = 0;
    while (j < 4) {
        int i = 0;
        while (i < 4) {
			if (i == 3)
			{
				printf("%d", tab_solution[j][i]);
			}
			else{
            	printf("%d ", tab_solution[j][i]);
			}
            i++;
        }
        printf("\n");
        j++;
    }
}


int ft_check_board_duplicate(int tab_config[4][4], int tab_solution[4][4], int num, int i, int j) {
    // Vérifiez si le numéro existe déjà dans la même ligne
    int k = 0;
    while (k < 4) {
        if (tab_solution[j][k] == num) {
            return 0; // Le numéro existe déjà dans la ligne
        }
        k++;
    }

    // Vérifiez si le numéro existe déjà dans la même colonne
    k = 0;
    while (k < 4) {
        if (tab_solution[k][i] == num) {
            return 0; // Le numéro existe déjà dans la colonne
        }
        k++;
    }	

    // Si vous atteignez ce point, toutes les vérifications ont réussi
    return 1;
}

int	ft_check_col(int tab_config[4][4], int tab_solution[4][4], int i)
{
	int j;
	int	count;
	int current;

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
	int i;
	int	count;
	int current;

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






void	ft_fill_board(int tab_config[4][4], int tab_solution[4][4], int i, int j)
{
	int num;
	if (tab_solution[3][3] != 0) // ou sinon on peut faire  current_position[0] == 3 && current_position[1] == 3; (== tab size) 
	{
		ft_display_solution(tab_solution);
		return ;
	}
	int next_i = i + 1;
	int next_j = j;
	if (next_i == 4) {
		next_i = 0;
		next_j++;
	}
	num = 1;
	while (num < 5)
	{
		if (ft_check_board_duplicate(tab_config, tab_solution, num, i, j)) 
		{
            tab_solution[j][i] = num;
            if ((i < 3 || ft_check_line(tab_config, tab_solution, j)) &&
                (j < 3 || ft_check_col(tab_config, tab_solution, i))) 
			{
                ft_fill_board(tab_config, tab_solution, next_i, next_j);
            }
            tab_solution[j][i] = 0;
        }
		num++;
	}
	
}

void	ft_rush_main()
{
	int tab_config[4][4] = {
    {1,3,3,4},
    {2,1,2,4},
	{1,3,3,2},
    {2,1,2,3},
	};
	int	tab_solution[4][4] = {0};
	
	ft_fill_board(tab_config, tab_solution, 0, 0);
	
}
int main(int argc, char const *argv[])
{
	
	ft_rush_main();
	
	return (0);
}





	// if (ft_check_board_duplicate(tab_config, tab_solution, num, i, j) &&
	// 	((i != 3 || ft_check_line(tab_config, tab_solution, j)) &&
	// 		(j != 3 || ft_check_col(tab_config, tab_solution, i))))
	// 	{
	// 		tab_solution[j][i] = num;
	// 		ft_fill_board(tab_config, tab_solution, next_i, next_j);
	// 		tab_solution[j][i] = 0;
	// 	}



