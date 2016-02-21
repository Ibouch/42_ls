#include <ft_ls.h>

int main(int ac, char **av)
{
    t_env   *e;
    t_flg   *flg;

    e = ft_memalloc(sizeof(t_env));
    flg = ft_memalloc(sizeof(t_flg));
    e->flg = flg;
    params_parsing(ac, av, e);
	delimit_flags(e);
    return (0);
}
