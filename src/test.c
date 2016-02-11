#include <stdio.h>
#include <libft.h>

void	ft_swap_str(char *s1, char *s2)
{
	int	i = (-1);

	s = ((ft_biggest_str(s1, s2, s1) == 1) ? ft_strlen(s1) : ft_strlen(s2));
	while (++i < s)
		ft_memswap(&s1[i], &s2[i], 1);
}

int	main()
{
	char *s1 = "Deuxieme phrase les beau goss du diamanche!";
	char *s2 = "Premiere phrae inshallah!";

	ft_swap_str(s1, s2);
	ft_putendl(s1);
	ft_putendl(s2);
}
