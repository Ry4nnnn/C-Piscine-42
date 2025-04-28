/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlim <wlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 02:34:58 by wlim              #+#    #+#             */
/*   Updated: 2025/04/29 03:17:53 by wlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

# define DIV_ERR "Stop : division by zero\n"
# define MOD_ERR "Stop : modulo by zero\n"

int		ft_atoi(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
int		add(int a, int b);
int		minus(int a, int b);
int		multiply(int a, int b);
int		div(int a, int b);
int		mod(int a, int b);

#endif