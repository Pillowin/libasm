S			:=	src/
T			:=	test/
O			:=	obj/

NAME		:=	libasm.a

ASM_SRC		:=	$(wildcard $S*.s $S*/*.s)
ASM_OBJ		:=	$(ASM_SRC:$S%.s=$O%.o)

C_SRC		:=	$(wildcard $T*.c $T*/*.c)
C_OBJ		:=	$(C_SRC:$T%.c=$O%.o)

CXX_SRC		:=	$(wildcard $T*.cpp $T*/*.cpp)
CXX_OBJ		:=	$(CXX_SRC:$T%.cpp=$O%.o)

AR			:=	ar
ARFLAGS		:=	rc

AS			:=	nasm
ASFLAGS		+=	-fmacho64

CC			:=	gcc
CFLAGS		+=	-Wall -Werror -Wextra -MMD
CPPFLAGS	+=	-Ilibtest/header

CXX			:=	g++
CXXFLAGS	+=	-Wall -Werror -Wextra -std=c++98 -pedantic-errors -MMD

LD			:=	ld
LDFLAGS		+=	-arch x86_64
LDFLAGS		+=	-L. -L/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib -Llibtest
LDLIBS		+=	-lSystem -lasm -ltest

MAKEFLAGS	+=	--no-print-directory

RM			:=	/bin/rm -f
RMDIR		:=	/bin/rm -Rf

$O%.o: $S%.s
	@mkdir -p $(@D)
	$(AS) $(ASFLAGS) $< -o $@

all:
	@$(MAKE) $(NAME)

$(NAME): $(ASM_OBJ)
	$(AR) $(ARFLAGS) $@ $(ASM_OBJ)

libtest:
	@make -C libtest

$O%.o: $T%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$O%.o: $T%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

test: libtest all $(CXX_OBJ)
	#$(LD) $(LDFLAGS) $(CXX_OBJ) $(LDLIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(CXX_OBJ) $(LDLIBS)
	./a.out

clean:
	$(RMDIR) $(wildcard $(NAME).dSYM)
	$(RMDIR) $O

fclean: clean
	$(RM) $(NAME)
	$(RM) a.out

re: fclean
	@$(MAKE)

.PHONY: all clean fclean test re

-include $(ASM_OBJ C_OBJ CXX_OBJ:.o=.d)
