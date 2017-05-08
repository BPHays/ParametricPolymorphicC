all: vector list hashtab

vector: vector.c vector.h
	clang -o vector --std=c11 vector.c

list: list.c list.h
	clang -o list --std=c11 list.c

hashtab: hashtab.c hashtab.h
	clang -o hashtab --std=c11 hashtab.c

clean:
	rm vector
	rm list
	rm hashtab
