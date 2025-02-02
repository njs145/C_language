# 아키텍쳐 정의
ARCH = armv7-a
MCPU = cortex-a8	

# 컴파일러 변수 추가.
CC = /usr/bin/aarch64-linux-gnu-gcc
AS = /usr/bin/aarch64-linux-gnu-as
LD = /usr/bin/aarch64-linux-gnu-gcc
OC = /usr/bin/aarch64-linux-gnu-objcopy
OD = /usr/bin/aarch64-linux-gnu-objdump

# 출력 파일 이름 정의.
output = build
MAP_FILE = build/C_Language.map
ASM_FILE = build/C_Language.asm
C_Language = build/C_Language

# 컴파일 옵션 정의.
CFLAGS = -fdiagnostics-color=always -c -g -O0 -std=c11

# 링커 옵션 선언.
LDFLAGS = -static -lgcc

# 컴파일 목록들 정의.
C_SRCS = $(wildcard *.c)
C_SRCS += $(notdir $(wildcard 10_Standard_IO/*.c))
C_SRCS += $(notdir $(wildcard 11_Calculator/*.c))
C_SRCS += $(notdir $(wildcard 12_branching_statement/*.c))
C_SRCS += $(notdir $(wildcard 13_Iteration/*.c))
C_SRCS += $(notdir $(wildcard 14_array/*.c))
C_SRCS += $(notdir $(wildcard Hello/*.c))
C_SRCS += $(notdir $(wildcard common/*.c))
C_OBJS = $(patsubst %.c, build/%.o, $(C_SRCS))

# 컴파일 경로 정의
INC_DIRS = -I 10_Standard_IO	\
		   -I 11_Calculator	\
		   -I 12_branching_statement \
		   -I 13_Iteration \
		   -I 14_array \
		   -I Hello \
		   -I common

# Makefile의 검색 경로 설정
VPATH = 10_Standard_IO	\
		11_Calculator	\
		12_branching_statement \
		13_Iteration \
		14_array \
		Hello \
		common \

# Makefile 타겟 정의
.PHONY: all clean

# build
all: $(C_Language)

# build 폴더 삭제
clean:
	@rm -fr build

# object파일 링크
$(C_Language): $(C_OBJS)
	$(LD) -o $(C_Language) $(C_OBJS) -Wl,-Map=$(MAP_FILE) $(LDFLAGS)
	$(OD) -d $(C_Language) >> $(ASM_FILE)
	rm $(output)/*.o

# c파일 컴파일
$(output)/%.o: %.c
	mkdir -p $(shell dirname $@)
	@echo $(CC) $(INC_DIRS) $(CFLAGS) -o $@ $<
	$(CC) $(INC_DIRS) $(CFLAGS) -o $@ $<