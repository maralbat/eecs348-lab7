CC := gcc
CFLAGS := -Wall

football.exe: football_main.c football.c
	$(CC) $^ -o $@

temperature.exe: temperature_main.c temperature.c
	$(CC) $^ -g -o $@