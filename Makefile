S			:=	src/
T			:=	test/
O			:=	obj/

NAME		:=	libasm.a
BIN_NAME	:=	asmbin

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

all: $(NAME)
	@$(MAKE) $(NAME)

$(NAME): $(ASM_OBJ)
	$(AR) $(ARFLAGS) $@ $(ASM_OBJ)

libtest: libtest/libtest.a
	@$(MAKE) -C libtest

$O%.o: $T%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$O%.o: $T%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

$(BIN_NAME): $(CXX_OBJ)
	$(CXX) $(LDFLAGS) $(CXX_OBJ) $(LDLIBS) -o $@

test: all libtest $(BIN_NAME) 
	./$(BIN_NAME)

clean:
	$(RMDIR) $(wildcard $(NAME).dSYM)
	$(RMDIR) $O

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BIN_NAME)

re: fclean
	@$(MAKE)

.PHONY: all clean fclean libtest test re

-include $(ASM_OBJ C_OBJ CXX_OBJ:.o=.d)
