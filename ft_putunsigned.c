/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:07:03 by juagomez          #+#    #+#             */
/*   Updated: 2024/06/10 22:10:06 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned(unsigned int num)
{
	if (num < 0)
	{
        ft_putchar('-');
		num = num * -1;
		ft_putunsigned(num);
	}
	else if (num > 9)
	{
		ft_putunsigned(num / 10);
		ft_putunsigned(num % 10);
	}
	else
		ft_putunsigned(num + '0');
}