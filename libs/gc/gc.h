/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:47:54 by mechane           #+#    #+#             */
/*   Updated: 2023/07/16 09:28:39 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_H
# define GC_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_gc
{
	void		*address;
	struct s_gc	*next;
}t_gc;

t_gc	*new_gc(void *ptr);
void	*gc(size_t size, int fr_flag);
void	gc_add_front(t_gc **gc, t_gc *news);
void	free_gc(t_gc **gc);

#endif