CC = cc
CFLAGS = -Wall -Wextra -Werror -D_POSIX_C_SOURCE=200809L

all: client server

client: client.o minitalk.h
	$(CC) $(CFLAGS) -o $@ $<

server: server.o minitalk.h
	$(CC) $(CFLAGS) -o $@ $<

client_bonus: client_bonus.o minitalk_bonus.h
	$(CC) $(CFLAGS) -o $@ $<

server_bonus: server_bonus.o minitalk_bonus.h
	$(CC) $(CFLAGS) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: client_bonus server_bonus

clean:
	rm -f *.o

fclean: clean
	rm -f client server client_bonus server_bonus

re: fclean all

.PHONY: all bonus clean fclean re
