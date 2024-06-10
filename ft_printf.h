/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:50:52 by juagomez          #+#    #+#             */
/*   Updated: 2024/06/10 22:10:58 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// LIBRERIAS EXTERNAS -----------------------------------
// ----------------------------------------------------

# include <stdio.h>
# include <stdarg.h>

// INCLUSION ARCHIVO ENCABEZADO LIBRERIA "LIBFT.H"
//# include "../LIBFT/libft.h"

# include <unistd.h>

// FUNCIONES PRINT  -----------------------------------
// ----------------------------------------------------

/** 
* @brief Imita la funcionalidad de la función estándar "printf", permitiendo
salida formateada. Admite varios marcadores de posición como “%c” 
para caracteres, “%s” para cadenas y maneja conversiones de números, 
lo que facilita la personalización de la salida para los programadores.
* @param format: puntero a una cadena terminada en nulo que contiene la 
cadena de control de formato. Esta cadena puede contener caracteres 
comunes y especificaciones de formato.
* @param ...: número variable de argumentos que corresponden a los valores
que se formatearán e imprimirán en función de los marcadores de posición
en la cadena de formato.
* @returns int -> número total de caracteres impresos, excluido el byte
que termina en nulo. Si se produce un error o se encuentra un especificador
de conversión no compatible, devuelve -1.
*/
int	ft_printf(const char *format, ...);

/** 
* @brief Utilidad útil para imprimir números enteros en la salida estándar 
y obtener la longitud del número entero impreso. 
* @param num: Número entero que se escribirá en la salida estándar.
* @returns void -> 
*/
void	ft_putnbr(int num);


void	ft_putunsigned(unsigned int num);

/** 
* @brief diseñada para escribir una cadena terminada en nulo en la salida 
estándar (stdout) mediante la llamada al sistema de escritura. Si la cadena
de entrada es NULL, imprime la cadena "(nula)" en la salida estándar. 
La función devuelve el número total de caracteres escritos en la salida 
estándar.
* @param str: Puntero a la cadena terminada en nulo que se escribirá 
en la salida estándar.
* @returns void -> 
*/
void	ft_putstr(char *str);

/** 
* @brief Toma un carácter 'c' como entrada y lo escribe en la salida estándar
(descriptor de archivo 1). Luego devuelve el valor 1 para indicar éxito, 
normalmente utilizado para la impresión de caracteres en programas.
* @param c: El carácter que se imprimirá en la salida estándar.
* @returns void -> 
*/
void	ft_putchar(char character);



#endif
