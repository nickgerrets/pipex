/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/29 15:35:39 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/08/18 12:52:47 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
**	Get the contents of environment variable var from the environment env.
*/
static char	*get_env(char **env, char *var)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strnstr(env[i], var, ft_strlen(var)) != 0)
			return (env[i] + ft_strlen(var) + 1);
		i++;
	}
	return (NULL);
}

/*
**	Get the PATH environment variable and search through the indicated
**	directories for an executable cmd, then return the path to this command.
*/
char	*get_path(char **cmd, char **env)
{
	char	*var;
	char	**directories;

	var = get_env(env, "PATH");
	if (var == NULL)
		throw_error("Something is wrong with the environment variables!\n");
	directories = ft_split(var, ':');
	while (*directories != NULL)
	{
		var = ft_strjoin(*directories, ft_strjoin("/", cmd[0]));
		if (access(var, F_OK | X_OK) == 0)
			return (var);
		directories++;
	}
	return (NULL);
}
