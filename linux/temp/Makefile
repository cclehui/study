objects = main.o io.o 
result:$(objects)
	gcc -o result $(objects)
main.o:main.c io.h
	gcc -c -o main.o $<
io.o:io.c io.h
	gcc -c -o $@ $<
.PHONY:clean
clean:
	rm $(objects) result
