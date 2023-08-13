#include <unistd.h>

void	ft_putchar(char x)
{
	write (1, &x, 1);
}

void	print_grid_sol(char *rep)
{	
	int	x;
	int 	y;

	x = 1;
	y = 1;
	while(y <= 4)
	{
		while (x <= 4)
		{
		i	ft_putchar(*rep);
			if (x < 4)
				ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		x = 1;
		y++;
	}
}

/*int	main(void)
{
	print_grid_sol(T);
	return (0);
}*/
