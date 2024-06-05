/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elo <elo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:54:02 by ehamm             #+#    #+#             */
/*   Updated: 2024/06/05 17:51:08 by elo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char **argv)
{
	t_data *data;

	if (argc == 5 || argc == 6)
	{
		data = malloc(sizeof(t_data));
		prog_init(data, argc, argv);
		init_thread(data);
		// Clean when philos are full or one philo dies
	}
	else
	 	printf("Error: Invalid number of arguments\n Usage: ./philo [number_of_philosophers] [time_to_die]time_to_eat] [time_to_sleep] (optional)[number_of_times_each_philosopher_must_eat]Example: ./philo 5 800 200 200 3\n");
}
