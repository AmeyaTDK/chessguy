
.PHONY: clean

test: test.c chess.h chess.c
	gcc test.c chess.c -o testrun

clean: 
	@rm -f test
