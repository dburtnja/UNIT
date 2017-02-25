
#ifndef CHECKER_CHECKER_H
# define CHECKER_CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft.h"
# include "./get_next_line.h"

# define GREEN			"\x1b[32m"
# define YELLOW			"\x1b[33m"
# define BLUE			"\x1b[34m"
# define RED			"\x1b[31m"
# define RESET			"\x1b[0m"

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
int						check_instructions(t_doub_lst **a, t_doub_lst **b,
											  int flag);
void					swap_stack(t_doub_lst **stack);
void					push_stack(t_doub_lst **from, t_doub_lst **into);
void					rotate_stack(t_doub_lst **head);
void					rev_rotate_stack(t_doub_lst **head);
void					apply_to_both(t_doub_lst **a, t_doub_lst **b,
									   void (*f)(t_doub_lst **stack));

void					ps_swap_stack(t_doub_lst **stack);
void					ps_push_stack(t_doub_lst **from, t_doub_lst **into);
void					ps_rotate_stack(t_doub_lst **head);
void					ps_rev_rotate_stack(t_doub_lst **head);
void					ps_apply_to_both(t_doub_lst **a, t_doub_lst **b,
									  void (*f)(t_doub_lst **stack));
void					find_sort_algorithm(t_doub_lst **a, t_doub_lst **b);
int						check_if_sort_a(t_doub_lst *a);
int						check_if_sort_b(t_doub_lst *b);

void					sort_small(t_doub_lst *a, t_doub_lst *b);
int						middle_nbr(t_doub_lst *head);
int						if_rev_rotate(t_doub_lst *lst, int midd_nbr, int size);

#endif
