#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>
# include <stdlib.h>
# include "libft.h"
# define PRINT_VAR(X) printf(#X " is %ld and the address is %p\n", X, &X);
# define THREAD_LIMIT 100

typedef enum s_state
{
	scratch_balls,
	eating,
	sleeping,
	thinking,
	is_dead
} t_state;

typedef struct s_info
{
	int				id;
	pthread_t		t;
	long 			last_eat;
	int 			total_eat;
	int 			time_to_sleep;
	int 			time_to_die;
	int				how_many_times_to_eat;
	int 			time_to_eat;
	bool 			*fork_left;
	bool 			*fork_right;
	t_state 		st;
	pthread_mutex_t	lock;
	pthread_mutex_t	kill;
	pthread_mutex_t	lock_write;
	pthread_mutex_t	lock2;
} t_info;

typedef struct s_philo
{
	t_info			*philo;
	bool			*forks;
	int				nmr_p;
	struct timeval	time;
} t_philo;

void	stop_eating(t_info *p, long time);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	init_philo(t_philo *p, char **av, int ac);
long	calculate_time(long	time);
long	get_time(void);
void	give_forks(t_info *p, long time);
void	put_to_sleep(t_info *p);
void	think(t_info *p, long time);

#endif
