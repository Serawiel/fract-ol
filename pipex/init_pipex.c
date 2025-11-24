/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprot <cprot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:04:30 by cprot             #+#    #+#             */
/*   Updated: 2025/05/21 17:59:34 by cprot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_input_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror(filename);
		fd = open("/dev/null", O_RDONLY);
	}
	return (fd);
}

int	open_output_file(char *filename, int *error_flag)
{
	int	fd;

	*error_flag = 0;
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(filename);
		*error_flag = 1;
		fd = open("/dev/null", O_WRONLY);
	}
	return (fd);
}

char	*find_in_path(char *cmd, char *path_dirs)
{
	char	**dirs;
	char	*full_path;
	int		i;

	dirs = ft_split(path_dirs, ':');
	if (!dirs)
		return (NULL);
	i = -1;
	while (dirs[++i])
	{
		full_path = create_path(dirs[i], cmd);
		if (!full_path)
		{
			free_args(dirs);
			return (NULL);
		}
		if (access(full_path, X_OK) == 0)
		{
			free_args(dirs);
			return (full_path);
		}
		free(full_path);
	}
	free_args(dirs);
	return (NULL);
}

char	*search_path(char *cmd, char **envp)
{
	char	**args;
	char	*path;
	int		i;

	args = ft_split(cmd, ' ');
	if (!args)
		return (NULL);
	if (ft_strrchr(args[0], '/'))
	{
		path = ft_strdup(args[0]);
		free_args(args);
		return (path);
	}
	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = find_in_path(args[0], envp[i] + 5);
			free_args(args);
			return (path);
		}
	}
	free_args(args);
	return (NULL);
}

t_pipex	init_pipex(char **av, char **envp)
{
	t_pipex	pipex;

	ft_memset(&pipex, 0, sizeof(t_pipex));
	pipex.infile = av[1];
	pipex.outfile = av[4];
	pipex.cmd1 = av[2];
	pipex.cmd2 = av[3];
	pipex.envp = envp;
	pipex.fdin = open_input_file(pipex.infile);
	pipex.fdout = open_output_file(pipex.outfile, &pipex.error_flag);
	if (pipex.cmd1 && *pipex.cmd1)
	{
		pipex.envp1 = search_path(pipex.cmd1, envp);
		pipex.args1 = ft_split(pipex.cmd1, ' ');
	}
	if (pipex.cmd2 && *pipex.cmd2)
	{
		pipex.envp2 = search_path(pipex.cmd2, envp);
		pipex.args2 = ft_split(pipex.cmd2, ' ');
	}
	return (pipex);
}
