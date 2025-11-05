#ifndef HEXA_H
# define HEXA_H

# include "types.h"

# define HEX_BASE_LEN 16
# define HEX_LOW_BASE "0123456789abcdef"
# define HEX_UPP_BASE "0123456789ABCDEF"

int	ft_putnbr_hex(unsigned int nbr, t_bool uppercase);

#endif
