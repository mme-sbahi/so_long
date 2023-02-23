/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:51:33 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/02/23 12:32:17 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef SO_LONG_H
# define SO_LONG_H


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1999999999
# endif

# include <limits.h>
# include <fcntl.h>
# include <mlx.h> 
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_pos
{
	int x;
	int y;
} t_pos;
typedef struct s_map 
{
	char **tab;
	void *mlx;
	void *win;
	void *img;
	int a;
	int b;
	t_pos pos_player;
	int C;
	int P;
	int E;
	int height; 
	int moves;
}t_ptr;

char	*ft_strdup(char *source);
int		ft_strlen(char *s);
int		ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*first(char *str);
char	*second(char *str);
char	*ft_read_line(int fd, char *s);
char	*get_next_line(int fd);
char	**ft_split(char *str, char c);
char	*ft_substr( char *s,int start, int len);
void	ft_putstr(char *s);
void	ft_check(t_ptr *data);
int		ft_strcohr(char *s, char c);
void	ft_check_cote(t_ptr *data);
void	ft_check_one(t_ptr *data);
void	ft_count(t_ptr *data);
char	**ft_read(char **argv);
void	draw_map_1(t_ptr *data);
void	parcing(char **argv, t_ptr *data);
char	*ft_strtrim(char *s1, char *set);
int		ft_strcmp(char *first, char *second);
void	draw_map_P(t_ptr *data);
void	draw_map_C(t_ptr *data);
void	draw_map_E(t_ptr *data);
void	draw_map_0(t_ptr *data);
int		ft_W(t_ptr *data);
int		ft_A(t_ptr*data);
int		ft_D(t_ptr *data);
int		hook(int key, t_ptr *data);
int		ft_S(t_ptr *data);
void	ft_putnbr_fd(int nb, int fd);
char	**dup_2d_arr(char **arr);
void	flood_fill_e(char **arr, int x, int y);
void	flood_fill_c(char **arr, int x, int y);
int		check_flood_fill(t_ptr *data);
int		ft_strlen_2d(char **str);
void	ft_check_ber(char *str, t_ptr *data);
void	ft_error(char *s, char **);
char	**ft_free(char **str, int i);

#endif 