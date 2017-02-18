
#ifndef CHECKER_CHECKER_H
# define CHECKER_CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../get_nex_line/get_next_line.h"

void	error(void);
int		check_instructions(int *a, int *b);
void	swap_stack(int *stack);
void	push_stack(int *from, int *into);
void	rotate_stack(int *arr);
void	rev_rotate_stack(int *arr);
void	applay_to_both(int *a, int *b, void (*f)(int *stack));

#endif //CHECKER_CHECKER_H
