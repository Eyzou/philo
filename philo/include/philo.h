/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:59:07 by ehamm             #+#    #+#             */
/*   Updated: 2024/06/11 14:34:40 by ehamm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>  // pthread and mutex
# include <stdbool.h>  // booleen
# include <stdio.h>    // for printf
# include <stdlib.h>   // for malloc / free
# include <string.h>   // for memset
# include <sys/time.h> // gettimeofday
# include <stdint.h> // gettimeofday
# include <unistd.h>   // write and usleep

# define RESET "\e[0m"
# define PINK "\e[0;38;5;199m"
# define GREEN "\e[0;32m"
# define BLUE "\e[0;34m"
# define G_BLUE "\e[0;38;5;24m"
# define B_BLUE "\e[1;34m"
# define G_CYAN "\e[0;38;5;44m"

# define INT_MAX 2147483647
# define PHILO_MAX 200

typedef struct s_data	t_data;

typedef struct s_philo
{
	pthread_t			t;
	int					id;
	int					number_meal;
	size_t				last_meal_time;
	int					r_fork;
	int					l_fork;
	int					should_eat;
	struct s_data		*data;
}						t_philo;

typedef struct s_data
{
	int					number_philo;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	int					number_must_eat;
	size_t				start_simulation;
	int					is_dead; // compare with time_to_die
	int					is_full; // compare with number_must_eat
	pthread_mutex_t		*forks_lock;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		dead_lock;
	pthread_mutex_t		meal_lock;
	pthread_mutex_t		time_lock;
	t_philo				*philo;
}						t_data;

// init
int			prog_init(t_data *data, int argc, char **argv);
int			init_thread(t_data *data);

// routine
void		*health_checker(void *arg);
void		*routine(void *arg);
int			is_full(t_philo *philo);
int			is_dead(t_philo *philo);

// utils
size_t		get_time(void);
void		my_usleep(size_t milliseconds);
long		ft_atol(const char *str, t_data *data);
void		print_msg(t_philo *philo, int id, char *color, char *msg);
void		print_msg_death(t_philo *philo, int id, char *color, char *msg);
int			error_msg(char *msg);
void		clean_all(t_data *data);

#endif