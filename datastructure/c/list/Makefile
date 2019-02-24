objects = test.o linked_list.o table_list.o
result:$(objects)
	gcc -o result $(objects)
test.o:test.c linked_list.h
	gcc -c -o test.o $<
linked_list.o:linked_list.c linked_list.h
	gcc -c -o $@ $<
table_list.o:table_list.c table_list.h
	gcc -c -o $@ $<
.PHONY:clean
clean:
	rm $(objects) result


