CC = gcc
CFLAGS += -g -pedantic -Wall -Iutils
LDFLAGS += -ldl -Wl,-rpath=./my_algos/lib

OUTPUTS = sort_algo 
ALGOS = my_algos
.PHONY : clean new my_algos run


all :  $(OUTPUTS) $(ALGOS)

my_algos :
	$(MAKE) -C my_algos

sort_algo : main.o utils/algo_dir_utils.o
	$(CC) $(CFLAGS) $(LDFLAGS) $? -o $@
	
main.o: main.c utils/algo_dir_utils.h utils/../algo_interface/algo_interface.h

clean :
	rm -rf *.o $(OUTPUTS)
	$(MAKE) -C utils clean
	$(MAKE) -C my_algos clean

new : clean all

run : all
	./sort_algo