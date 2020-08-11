#ifndef MINISHELL_H
#define MINISHELL_H

#define PATH "/bin/"
#define MALLOC_ERROR		0
#include "../libft/libft.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

typedef struct s_env
{
	int status;
	char *cmd_line;
	char *cmd_name;
	char **cmd_arg;
	pid_t parent;
	char **path;
	char **envcpy;
	t_list *env_list;
} t_env;

void exit_sh(char *cmd);
void cmd_not_found_msg(char *cmd);
int get_command(t_env *list);
int    sh_builtins(t_env *lst);
void sh_executable(t_env *lst);
t_env		*init_list(char **env);
void	printenv(t_env *print);
void env_builtin(t_env *lst);
void echo_builtin(t_env *lst);
int my_builtin(char *cmd_name);
char *get_value(t_list *env, char *name);
int ft_setenv(t_env *lst);
t_list *set_value(t_list *env, char *name, char *value);
size_t	ft_keylen(char *content);
char ft_is_sign(char c);
t_list *unset_value(t_list *env, char *name);
int ft_unsetenv(t_env *lst);
char *home_expansion(t_list *env, char *str);
int		is_blank_line(char *str);
char *key_expansion(t_list *env, char *str);
int cd_builtin(t_env *lst);
void display_prompt();
int				cd_errors(char *path);
void expand_args(t_env *lst);
char			**ft_split_cmd(char const *s);

#endif