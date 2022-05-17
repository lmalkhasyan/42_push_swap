/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:16:46 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/16 16:06:22 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdlib.h"
# include "unistd.h"
# include "stdio.h"
# include "limits.h"

# define UP 1
# define DOWN 0

typedef struct s_node
{
	int				data;
	int				index;
	int				markup;
	int				keep;
	int				a_updown;
	int				b_updown;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
	int		m_length;
	t_node	*m_start;
	int		updown;
	int		a_updown;
	int		b_updown;
}	t_stack;
/* Additional Functions */
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
char	*ft_strjoin(char *s1, char const *s2);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_swapint(int *a, int *b);
int		ft_min(int num1, int num2);
int		ft_min4(int one, int two, int three, int four);
int		ft_abs(int a);

/* Error function (pointer for free) */
void	ft_exit_error(char *str, char **matrix);

/* Free Fucntions */
void	ft_free_array(char **arr);
void	ft_free_matrix(char ***matrix);

/* Checking and returning strings argv in matrix */
char	**ft_checkargvs(int argc, char *argv[]);

/* Stack functions */
t_node	*ft_new_node(int data);
void	ft_stack_push(t_stack *stack, t_node *new);
void	ft_stack_pop(t_stack *stack);
void	ft_stack_clear(t_stack *stack);
void	ft_fill_stack(t_stack *stack, char **numlist);
int		ft_is_sorted(t_stack *stack);

/* Stack Insturctions */
/* sa , sb or ss */
void	ft_stack_swap(t_stack *stack, char *text);
/* pa or pb */
void	ft_stack_papb(t_stack *dest, t_stack *src, char *text);
/* ra, rb or rr */
void	ft_stack_rotate(t_stack *stack, char *text);
/* rra, rrb or rrr */
void	ft_stack_rrotate(t_stack *stack, char *text);

/* Indexation Stack */
void	ft_index_stack(t_stack *stack);

/* Indexing for markup */
void	ft_markup_index(t_stack *stack);

/* Find largest markup */
void	ft_markup(t_stack *stack);
int		ft_markuplength(t_node *first);

/* set markup fields to 1 */
void	ft_keep_set(t_stack *stack);

/* From A to B */
void	ft_tostack_b(t_stack *a, t_stack *b);

/* Updating all scores in B */
void	ft_find_scores(t_stack *a, t_stack *b);

/* To Stack A */
void	ft_tostack_a(t_stack *a, t_stack *b);

/* Align Stack A */
void	ft_align_stack(t_stack *a);

/* Checker (bonus part) */
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*get_next_line(int fd);
void	ft_checker(t_stack *a, t_stack *b);
# define BUFFER_SIZE 5

#endif
