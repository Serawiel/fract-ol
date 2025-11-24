/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprot <cprot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:14:34 by cprot             #+#    #+#             */
/*   Updated: 2025/05/21 17:28:28 by cprot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	wait_children(pid_t pid1, pid_t pid2)
{
	int	status1;
	int	status2;

	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	return (1);
}

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

char	*create_path(char *dir, char *cmd)
{
	char	*path;
	char	*temp;

	temp = ft_strjoin(dir, "/");
	if (!temp)
		return (NULL);
	path = ft_strjoin(temp, cmd);
	free(temp);
	return (path);
}

void	cleanup_pipex(t_pipex *pipex)
{
	if (pipex->args1)
		free_args(pipex->args1);
	if (pipex->args2)
		free_args(pipex->args2);
	if (pipex->envp1)
		free(pipex->envp1);
	if (pipex->envp2)
		free(pipex->envp2);
	if (pipex->fdin >= 0 && pipex->fdin != STDIN_FILENO)
		close(pipex->fdin);
	if (pipex->fdout >= 0 && pipex->fdout != STDOUT_FILENO)
		close(pipex->fdout);
	if (pipex->pipefd[0] > 0)
		close(pipex->pipefd[0]);
	if (pipex->pipefd[1] > 0)
		close(pipex->pipefd[1]);
}
