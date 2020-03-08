CC = g++
exe_file = LinkedList
$(exe_file): node.o linked_list.o prog.o
	$(CC) -std=c++11 -g node.o linked_list.o prog.o -o $(exe_file)
node.o: node.cpp
	$(CC) -c -std=c++11 node.cpp
linked_list.o: linked_list.cpp
	$(CC) -c -std=c++11 linked_list.cpp
prog.o: prog.cpp
	$(CC) -c -std=c++11 prog.cpp
clean:
	rm -f *.out *.o *.gch $(exe_file)
