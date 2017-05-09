all: vector list hashtab pair

vector: vector.c vector.h
	clang -o vector --std=c11 vector.c

list: list.c list.h
	clang -o list --std=c11 list.c

hashtab: hashtab.c hashtab.h list.h
	clang -o hashtab --std=c11 hashtab.c

pair: pair.c pair.h
	clang -o pair --std=c11 pair.c

clean:
	rm vector
	rm list
	rm hashtab
	rm pair
