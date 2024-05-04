CC=g++
obj=function_overload
OBJ=function_overload.o
target=function_overload

$(target):$(OBJ)
	$(CC) $^ -o $@
$(obj).o:$(obj).cc
	$(CC) -c $< -o $@
clean:
	rm -rf *.o
