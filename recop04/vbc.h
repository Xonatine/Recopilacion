/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vbc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:51:06 by dgargant          #+#    #+#             */
/*   Updated: 2025/10/30 14:12:18 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VBC_H
#define VBC_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>


void unexpected(char c);

int ft_product();

int ft_sum();

int ft_factor();

int chek_imput(char *str);

int main(int argc, char **argv);

#endif