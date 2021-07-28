/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/28 16:25:13 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/07/28 21:53:47 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

void	run_pipex(int argc, char **argv, char **env);
void	run_heredoc(int argc, char **argv);
void	throw_error(const char *err);

#endif
