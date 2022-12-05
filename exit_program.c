/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:08:55 by gsaile            #+#    #+#             */
/*   Updated: 2022/12/02 13:18:11 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *error_message, t_data *data)
{
	free_data(data);
	ft_putstr_fd("\033[1m\033[31mError\033[0m\n", 2);
	ft_putstr_fd(error_message, 2);
	ft_putchar_fd('\n', 2);
	exit(EXIT_FAILURE);
}
