.PHONY: build, re

all :
	gcc -o ok.exe *.c libmlx.a -lXext -lX11 -lm -lbsd
	./ok.exe "test.cub"
re :
	rm ok.exe
	gcc -o ok.exe *.c libmlx.a -lXext -lX11 -lm -lbsd
	./ok.exe "test.cub"