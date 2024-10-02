/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:32:48 by ccolin            #+#    #+#             */
/*   Updated: 2024/10/02 16:41:05 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_last_word(const char *str, char delimiter)
{
	const char *last_delim = ft_strrchr(str, delimiter);
	if (last_delim != NULL)
		return (ft_strdup(last_delim + 1));
	else
		return ft_strdup(str);
}

int	main(void)
{
	char	*user;
	char	*path;
	char	*current_dir;
	
	chdir(getenv("HOME"));
	user = getenv("USER");
	while (1)
	{
		path = getcwd(NULL, 0);
		current_dir = get_last_word(path, '/');
		ft_printf("%s@minishell:%s$ ", user, current_dir);
		free(path);
		free(current_dir);
		minishell(get_next_line(1));
	}
}
