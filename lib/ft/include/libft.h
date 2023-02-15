/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 21:15:32 by mgarcia-          #+#    #+#             */
/*   Updated: 2023/02/15 15:07:45 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <limits.h>
# include "cstring.h"
# include "ctypes.h"
# include "cfstream.h"
# include "clist.h"


# define FT_MAX(x,y)(x > y ? x : y)
# define FT_MIN(x,y)(x < y ? x : y)


float				ft_fabs(float number);

int					ft_abs(int number);




#endif
