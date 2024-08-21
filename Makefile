
# ARCHIVO MAKEFILE PROYECTO 42 "FT_PRINTF" --------------------------------

# tutorial 2 completo -> https://makefiletutorial.com/

# VARIABLES -----------------------------------------
# ---------------------------------------------------

# nombre compilador
CC := clang

# flags de compilacion
CFLAGS := -Wall -Wextra -Werror

# LISTADO FUNCIONES A INCLUIR EN BIBLIOTECA
SRC := ft_printf.c \
ft_putaddress.c ft_puthexadecimal.c ft_putunsigned.c ft_putnbr.c \
ft_putstr.c ft_putchar.c \

# NOMBRE SALIDA ARCHIVO BIBLIOTECA ".a"
NAME = libftprintf.a

# LISTA ARCHIVOS .O SEGUN ARCHIVO C
OBJ_FILES := $(SRC:%.c=%.o)

# RECETAS -----------------------------------------
# ---------------------------------------------------

# receta predeterminada
all: $(NAME)

# FUNCION PPAL -> CREACION ARCHIVO LIBRERIA ESTATICA .a
$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

# RECETA BORRAR ARCHIVOS '.o' -> '-f' ignora error si no encuentra archivos y elimina sin solicitar confirmacion
clean:
	rm -f $(OBJ_FILES)

# ejecuta clean + borrado archivo '.a'
fclean: clean
	rm -f $(NAME)

# FUNCION RECONSTRUCCION 
# -> ELIMINACION ARCHIVOS '.o' + archivos biblioteca '.a'
# NUEVA COMPILACION CON RECETA $(NAME)
re: fclean all

.PHONY: all clean fclean re

