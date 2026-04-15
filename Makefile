CC = clang
CFLAGS = -Wall -Wextra -std=c23 -g -fsanitize=address,undefined
O = -O0

CPPC = clang++
CPPFLAGS = -Wall -Wextra -std=c++17 -fsanitize=address,undefined

main: main.c
	$(CC) $(CFLAGS) $(O) main.c -o main && ./main

maincpp: main.cpp
	$(CPPC) $(CPPFLAGS) $(O) main.cpp -o main && ./main

test: test.cpp
	$(CPPC) $(CPPFLAGS) $(O) test.cpp -o main && ./main

clean:
	rm -f main

.PHONY: main maincpp clean test
