/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:32:53 by ccolin            #+#    #+#             */
/*   Updated: 2024/10/02 17:04:54 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_newline(char *command)
{
	int	i;
	
	i = 0;
	while (command[i])
		i++;
	i--;
	command[i] = '\0';
}

void	exit_ms(void)
{
	ft_printf("Exiting...\n");
	exit(0);
}

void	cd(char *path)
{
	if (chdir(path))
		ft_printf("cd : %s: No such file or directory\n", path);
}

int	minishell(char *command)
{
	int	i;
	char **commands;

	i = 0;
	remove_newline(command);
	commands = ft_split(command, ' ');
	free(command);
	while(commands[i])
	{
		if (ft_strncmp(commands[i], "exit", ft_strlen(commands[i])) == 0)
			exit_ms();
		if (ft_strncmp(commands[i], "cd", ft_strlen(commands[i])) == 0)
			cd(commands[++i]);
		i++;
	}
	return (1);
}
