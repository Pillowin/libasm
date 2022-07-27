S			:=	src/
T			:=	test/
O			:=	obj/

NAME		:=	libasm.a
BIN_NAME	:=	asmbin

ASM_SRC		:=	$(wildcard $S*.s $S*/*.s)
ASM_OBJ		:=	$(ASM_SRC:$S%.s=$O%.o)

CXX_SRC		:=	$(wildcard $T*.cpp $T*/*.cpp)
CXX_OBJ		:=	$(CXX_SRC:$T%.cpp=$O%.o)

AR			:=	ar
ARFLAGS		:=	rc

AS			:=	nasm
ASFLAGS		+=	-fmacho64 -g -F dwarf

CXX			:=	clang++
CXXFLAGS	+=	-Wall -Werror -Wextra -std=c++98 -pedantic-errors -MMD -g
CPPFLAGS	+=	-Ilibtest/header

LD			:=	ld
LDFLAGS		+=	-arch x86_64
LDFLAGS		+=	-L. -L/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib -Llibtest
LDLIBS		+=	-lSystem -lc++ -lasm -ltest

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
	$(MAKE) -C libtest

$O%.o: $T%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

$(BIN_NAME): all libtest $(CXX_OBJ)
	$(LD) $(LDFLAGS) $(CXX_OBJ) $(LDLIBS) -o $@

test: all libtest $(BIN_NAME) 
	./$(BIN_NAME)

clean:
	$(RMDIR) $(wildcard $(NAME).dSYM)
	$(RMDIR) $O

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BIN_NAME)
	$(RM) tmp.txt

re: fclean
	@$(MAKE)

.PHONY: all clean fclean libtest test re

-include $(CXX_OBJ:.o=.d)
