main:./source/*.c libfunc.a
	gcc -o main source/*.c libfunc.a -I./include
libfunc.a:library.o
	ar -rc libfunc.a library/library.o
library.o:./library/*.c
	gcc -c library/*.c -I./include -o ./library/library.o
clean:
	rm	-rf	main
	rm	-rf	./library/library.o
	rm	-rf	libfunc.a
