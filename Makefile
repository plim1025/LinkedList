CC = g++
exe_file = LinkedList
$(exe_file): node.o linked_list.o prog.o
	$(CC) -g -std=c++11 node.o linked_list.o prog.o -o $(exe_file)
node.o: node.cpp
	$(CC) -c node.cpp
linked_list.o: linked_list.cpp
	$(CC) -c linked_list.cpp
prog.o: prog.cpp
	$(CC) -c prog.cpp
clean:
	rm -f *.out *.o *.gch $(exe_file)

