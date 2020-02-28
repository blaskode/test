target="determinant"
dflags=-Wall -Werror -std=c17
cflags=-std=c17

make:
	gcc determinant.c $(cflags) -o $(target)

debug:
	gcc determinant.c $(dflags) -o $(target)

clean:
	rm $(target)