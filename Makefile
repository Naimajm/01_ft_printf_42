
# ARCHIVO MAKEFILE PROYECTO 42 "FT_PRINTF" --------------------------------

# tutorial 2 completo -> https://makefiletutorial.com/

# VARIABLES -----------------------------------------
# ---------------------------------------------------

# nombre compilador
CC := cc

# flags de compilacion
CFLAGS := -Wall -Wextra -Werror

# LISTADO FUNCIONES A INCLUIR EN BIBLIOTECA
SRC := \

# NOMBRE SALIDA ARCHIVO BIBLIOTECA ".a"
NAME = libftprintf.a

# LISTA ARCHIVOS .O SEGUN ARCHIVO C
OBJ_FILES := $(SRC:%.c = %.o)

# RECETAS -----------------------------------------
# ---------------------------------------------------

# FUNCION PPAL -> CREACION ARCHIVO LIBRERIA ESTATICA .a
$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

# receta predeterminada
all: $(NAME)

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

