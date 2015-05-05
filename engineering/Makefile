BUILD_PATH=build/
menu:menu.o util.o list.o
	gcc -o $@ $^
menu.o:menu.c common/util.h color.h model/list.h
	gcc -c $<
util.o:common/util.c
	gcc -c $<
list.o:model/list.c model/list.h
	gcc -c $<
clean:
	rm *.o 
.PHONY:clean
