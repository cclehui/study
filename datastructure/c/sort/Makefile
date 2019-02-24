objects = test.o sort.o table_list.o
result:$(objects)
	gcc -o $@ $(objects) 
sort.o:sort.c sort.h
	gcc -c $< 
test.o:test.c
	gcc -c $<
table_list.o:../list/table_list.c ../list/table_list.h
	gcc -c $<
.PHONY:clean
clean:
	rm $(objects) result
