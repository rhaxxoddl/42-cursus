TARGET	=	push_swap.out

DEBUG	=	push_swap_d.out
CC		=	gcc

# INC	=
SUBDIRS	=	./includes/Libft
AR		= 	ar rc
CFLAGS	=	-Wall -Wextra -Werror
DEBUGFLAG = -fsanitize=address -g
LDFLAGS	=	-lc

SRC		=	push_swap.c tool1.c tool2.c tool3.c linkedlist.c util.c
OBJS	=	$(SRC:.c=.o)
ARFS	=	Libft.a

all		:	$(TARGET)

d		:	$(DEBUG)

$(TARGET)	:	$(OBJS)
	$(MAKE) -C $(SUBDIRS)
	cp $(SUBDIRS)/*.a ./
	$(CC) $(CFLAGS) $(LDFLAGS) $(ARFS) -o $@ $^

.c .o	:
	$(CC) $(CFLAGS) -c -o $@ $^

$(DEBUG)	:	$(OBJS)
	$(MAKE) -C $(SUBDIRS)
	cp $(SUBDIRS)/*.a ./
	$(CC) $(CFLAGS) $(LDFLAGS) $(ARFS) $(DEBUGFLAG) -o $@ $^

fclean	:	clean
	rm -f $(TARGET)
	$(MAKE) -C $(SUBDIRS) clean

dclean	:	clean
	rm -f $(DEBUG)
	$(MAKE) -C $(SUBDIRS) clean

clean	:
	rm -f $(OBJS)

re		:	fclean all


.PHONY	: clean fclean dclean d all re Libft
