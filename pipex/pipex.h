/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprot <cprot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:39:35 by cprot             #+#    #+#             */
/*   Updated: 2025/05/21 16:53:58 by cprot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		fdin;
	int		fdout;
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	*infile;
	char	*outfile;
	char	*cmd1;
	char	*cmd2;
	char	*envp1;
	char	*envp2;
	char	**args1;
	char	**args2;
	char	**envp;
	int		error_flag;
}			t_pipex;

t_pipex		init_pipex(char **av, char **envp);
void		free_args(char **args);
char		*create_path(char *dir, char *cmd);
void		cleanup_pipex(t_pipex *pipex);
int			ft_pipex(t_pipex *pipex);
int			wait_children(pid_t child1, pid_t child2);

#endif