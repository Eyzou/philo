/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elo <elo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:54:02 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/28 21:27:55 by elo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main (int argc, char **argv)
{
	t_data *data;

	prog_init(data);
	create_thread(data);
	join_thread(data);
}