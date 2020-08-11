#include "../includes/minishell.h"

void loop(t_env *lst)
{
	while (1) //use status //NORM?
	{
		if (get_command(lst))
		{
			if (sh_builtins(lst) == 0)
			{
				if(!(lst->parent = fork())) //return of fork?
					sh_executable(lst);
				else 
					wait(&lst->status);		
			}
		}
		//free(lst);
	}
}

int main(int ac, char **av, char **env)
{
	t_env *lst;

    // system("aplay /home/acarlota/minishell/dobryden.wav");
	if (!(*env))
	{
		ft_putstr("Environment not found, the shell will exit "); //what?
		exit(0);
	}
	//init_minishell
	if((lst = init_list(env)))
		loop(lst);
	ac = 0;
	av[ac] = '\0';
}
