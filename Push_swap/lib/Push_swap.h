
#ifndef CHECKER_CHECKER_H
# define CHECKER_CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft.h"
# include "./get_next_line.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef	struct			s_doub_lst
{
	int					nbr;
	int 				size;
	struct s_doub_lst	*next;
	struct s_doub_lst	*prev;
}						t_doub_lst;

t_doub_lst				*lst_dup(t_doub_lst *head);
t_doub_lst				*new_lst(int nbr);
void					add_lst_to_back(t_doub_lst **head, t_doub_lst *new);
void					add_lst_to_front(t_doub_lst **head, t_doub_lst *new);
void					free_lst(t_doub_lst **head);

t_doub_lst				*bubble_sort(t_doub_lst *lst);

void					error(void);
int						check_instructions(t_doub_lst **a, t_doub_lst **b);
void					swap_stack(t_doub_lst **stack);
void					push_stack(t_doub_lst **from, t_doub_lst **into);
void					rotate_stack(t_doub_lst **head);
void					rev_rotate_stack(t_doub_lst **head);
void					apply_to_both(t_doub_lst **a, t_doub_lst **b,
									   void (*f)(t_doub_lst **stack));
void					find_sort_algorithm(t_doub_lst *a, t_doub_lst *b);

#endif
