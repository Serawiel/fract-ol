/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprot <cprot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:52:07 by cprot             #+#    #+#             */
/*   Updated: 2025/05/21 17:58:16 by cprot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_all_fds(t_pipex *pipex)
{
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	close(pipex->fdin);
	close(pipex->fdout);
}

void	child_one(t_pipex *pipex)
{
	if (dup2(pipex->fdin, STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(1);
	}
	if (dup2(pipex->pipefd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(1);
	}
	close_all_fds(pipex);
	if (!pipex->cmd1 || !*pipex->cmd1 || !pipex->envp1)
	{
		if (!pipex->cmd1 || !*pipex->cmd1)
			ft_printf("Error: Empty command 1\n");
		else
			perror(pipex->cmd1);
		cleanup_pipex(pipex);
		exit(127);
	}
	execve(pipex->envp1, pipex->args1, pipex->envp);
	perror(pipex->cmd1);
	cleanup_pipex(pipex);
	exit(127);
}

void	child_two(t_pipex *pipex)
{
	if (dup2(pipex->pipefd[0], STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(1);
	}
	if (dup2(pipex->fdout, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(1);
	}
	close_all_fds(pipex);
	if (!pipex->cmd2 || !*pipex->cmd2 || !pipex->envp2)
	{
		if (!pipex->cmd2 || !*pipex->cmd2)
			ft_printf("Error: Empty command 2\n");
		else
			perror(pipex->cmd2);
		cleanup_pipex(pipex);
		exit(127);
	}
	execve(pipex->envp2, pipex->args2, pipex->envp);
	perror(pipex->cmd2);
	cleanup_pipex(pipex);
	exit(127);
}

void	handle_second_child(t_pipex *pipex)
{
	pipex->pid2 = fork();
	if (pipex->pid2 < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pipex->pid2 == 0)
		child_two(pipex);
}

int	ft_pipex(t_pipex *pipex)
{
	int	status;

	if (pipe(pipex->pipefd) == -1)
	{
		perror("pipe");
		return (1);
	}
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
	{
		perror("fork");
		return (1);
	}
	if (pipex->pid1 == 0)
		child_one(pipex);
	handle_second_child(pipex);
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	status = wait_children(pipex->pid1, pipex->pid2);
	if (pipex->error_flag)
		return (1);
	return (status);
}
