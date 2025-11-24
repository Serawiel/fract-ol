/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprot <cprot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:39:24 by cprot             #+#    #+#             */
/*   Updated: 2025/05/21 17:26:11 by cprot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parse_args(int ac)
{
	if (ac != 5)
		return (-1);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	int		status;

	if (ac != 5)
	{
		ft_printf("Usage: %s infile cmd1 cmd2 outfile\n", av[0]);
		return (1);
	}
	pipex = init_pipex(av, envp);
	status = ft_pipex(&pipex);
	cleanup_pipex(&pipex);
	if (pipex.error_flag)
		return (1);
	return (status);
}
