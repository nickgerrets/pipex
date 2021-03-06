/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc_file.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/29 19:28:10 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/08/18 12:49:59 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../lib/get_next_line/get_next_line.h"

/*
**	Delete (unlink) the temporary heredoc file
*/
void	heredoc_delete(char *fname)
{
	if (unlink(fname) != 0)
		throw_error(NULL);
}

/*
**	Find a good filename for the temporary heredoc file. This is required if
**	multiple instances of pipex are running in the same directory.
*/
char	*heredoc_get_fname(void)
{
	char	*fname;

	fname = ft_strjoin(HEREDOC_NAME, "0");
	while (access(fname, F_OK) == 0)
	{
		if (ft_strlen(fname) > 50)
			throw_error("Error - Too many heredocs.");
		fname = ft_strjoin(fname, "0");
	}
	return (fname);
}

/*
**	Write a temporary heredoc file from STDIN.
*/
void	heredoc_write(char *fname, char *delimiter)
{
	int		ret;
	int		fd;
	char	*line;

	line = NULL;
	fd = open(fname, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	if (fd < 0)
		throw_error(NULL);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		if (ret < 0)
			throw_error("get_next_line returned -1\n");
		if (str_is_str(line, delimiter))
		{
			free(line);
			break ;
		}
		if (write(fd, ft_strjoin(line, "\n"),
				(ft_strlen(line) + 1) * sizeof(char)) < 0)
			throw_error(NULL);
		free(line);
	}
	close(fd);
}
