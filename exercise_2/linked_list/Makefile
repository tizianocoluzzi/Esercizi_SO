CC=gcc
CCOPTS=--std=gnu99 -Wall -D_LIST_DEBUG_ -g 
AR=ar

OBJS=linked_list.o int_list.o float_list.o

HEADERS=linked_list.h

LIBS=liblinkedlist.a

BINS=linked_list_test linked_list_exercise_1a 

#linked_list_exercise_1 linked_list_exercise_2

#disastros_test

.phony: clean all


all:	$(BINS) $(LIBS)

%.o:	%.c $(HEADERS)
	echo "sto a compilando evero un puntoci in un puntoo"
	$(CC) $(CCOPTS) -c -o $@  $<

liblinkedlist.a:	$(OBJS) 
	echo "genero la libreria"
	$(AR) -rcs $@ $^


linked_list_test:	linked_list_test.c $(LIBS)
	echo "comopilo il main"
	$(CC) $(CCOPTS) -o $@ $^

linked_list_exercise_1a:	linked_list_exercise_1a.c $(LIBS)
	echo "comopilo il main"
	$(CC) $(CCOPTS) -o $@ $^

# linked_list_exercise_1:	linked_list_exercise_1.c $(LIBS)
# 	echo "comopilo il main"
# 	$(CC) $(CCOPTS) -o $@ $^

# linked_list_exercise_2:	linked_list_exercise_2.c $(LIBS)
# 	echo "comopilo il main"
# 	$(CC) $(CCOPTS) -o $@ $^

clean:
	echo "lavo"
	rm -rf *.o *~ $(LIBS) $(BINS)
