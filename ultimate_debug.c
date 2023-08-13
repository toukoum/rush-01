

void	ft_rush_main(int tab_config[4][4]);
// ============================================
// check board
// ============================================

int ft_check_board_duplicate(int **tab_solution, int num, int i, int j)
{
    int k = 0;
    while (k < 4) {
        if (tab_solution[j][k] == num) {
            return (0);
        }
        k++;
    }
    k = 0;
    while (k < 4) {
        if (tab_solution[k][i] == num) {
            return 0;
        }
        k++;
    }
    return (1);
}

int	ft_check_col(int tab_config[4][4], int **tab_solution, int i)
{
	int j = 0;
	int count_top = 0;
	int count_bottom = 0;
	int max_top = 0;
	int max_bottom = 0;

	while (j < 4) {
		if (tab_solution[j][i] > max_top) {
			max_top = tab_solution[j][i];
			count_top++;
		}
		if (tab_solution[3 - j][i] > max_bottom) {
			max_bottom = tab_solution[3 - j][i];
			count_bottom++;
		}
		j++;
	}
	if (tab_config[0][i] == count_top && tab_config[1][i] == count_bottom) {
		return 1;
	} 
	else
		return 0;
}





int	ft_check_line(int tab_config[4][4], int **tab_solution, int j)
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

// ============================================
// check param
// ============================================

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_check_argv(char **argv)
{
	int i;

	i = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] >= '1' && argv[1][i] <= '4' && (i % 2 == 0))
		{
			i++;
		}
		else if (argv[1][i] == ' ' && (i % 2 == 1))
			i++;
		else
		{
			return (0);
		}
		
	}
	return (1);
}

int	ft_check_param(int i, int j, int argc, char **argv)
{
	int k;
	int	tab_config[4][4];
	if (argc == 2 && ft_strlen(argv[1]) == 31 && ft_check_argv(argv))
	{
		k = 0;
		while (argv[1][i] != '\0')
		{
			if (k > 3)
			{
				j++;
				k = 0;
			}
			if (argv[1][i] >= '1' && argv[1][i] <= '4')
			{
				tab_config[j][k] = argv[1][i] - 48;
				k++;
			}
			i++;
		}
		ft_rush_main(tab_config);
		return (1);
	}
	else
		return (0);
}


// ============================================
// display
// ============================================

#include <unistd.h>

void	ft_putchar(int x)
{
	write (1, &x, 1);
}

void	ft_display_solution(int **tab_solution)
{	
	int	x;
	int y;

	x = 0;
	y = 0;
	while(y < 4)
	{
		while (x < 4)
		{
			ft_putchar(tab_solution[y][x] + '0');
			if (x < 3)
				ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		x = 0;
		y++;
	}
}


#include <stdlib.h>

// ============================================
// rush-01.c
// ============================================

int	*ft_next_ij(int i, int j)
{
	int	next_i;
	int next_j;	
	int	*tab_next;
	
	tab_next = malloc(sizeof(int) * 2);
	if (!tab_next)
	{
		free(tab_next);
		return (0);
	}
	next_i = i + 1;
	next_j = j;
	if (next_i == 4)
	{
		next_i = 0;
		next_j++;
	}
	tab_next[0] = next_i;
	tab_next[1] = next_j;
	return (tab_next);
}

void	ft_fill_board(int tab_config[4][4], int **tab_solution, int i, int j)
{
	int num;
	int next_i;
	int next_j;
	if (tab_solution[3][3] != 0) 
	{
		ft_display_solution(tab_solution);
		return ;
	}
	int *next_indices = ft_next_ij(i, j);
	next_i = next_indices[0];
	next_j = next_indices[1];
	free(next_indices);
	num = 1;
	while (num < 5)
	{
		if (ft_check_board_duplicate(tab_solution, num, i, j)) 
		{
            tab_solution[j][i] = num;
            if ((i < 3 || ft_check_line(tab_config, tab_solution, j)) &&
                (j < 3 || ft_check_col(tab_config, tab_solution, i))) 
                ft_fill_board(tab_config, tab_solution, next_i, next_j);
            tab_solution[j][i] = 0;
        }
		num++;
	}
}

void	ft_init_tab_sol(int **tab_solution, int n)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (j < n)
	{
		tab_solution[j] = malloc(n * sizeof(int));
		if (tab_solution[j] == NULL)
			break;
		while (i < n)
		{
			tab_solution[j][i] = 0;
			i++;
		}
		i = 0;
		j++;		
	}
	
}

void	ft_rush_main(int tab_config[4][4])
{
	int	n;
	// int	tab_config[4][4] = {
	// {4,3,2,1},
	// {1,2,2,2},
	// {4,3,2,1},
	// {1,2,2,2},
	// };
	
	int	**tab_solution;
	n = 4;

	tab_solution = malloc(n * sizeof(int *));
	if (tab_solution == NULL) {
		return ;
	}

	ft_init_tab_sol(tab_solution, n);
	ft_fill_board(tab_config, tab_solution, 0, 0);
}
int	main(int argc, char **argv)
{
	int i;
	int j;
	int k;
	
	i = 0;
	j = 0;
	// int argc = 2;
	// char *argv[] = {"a.out", "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"};

	
	if (!ft_check_param(i, j, argc, argv))
	{
		write(1, "Error\n", 6);
	}
	
	return (0);
}