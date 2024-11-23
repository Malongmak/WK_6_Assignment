all: main weather

main: main.c calculate.c
	gcc main.c -o main -lm

weather: weather_module.c calculate.c
	gcc -shared -o weather.so weather_module.c -lm -I/usr/include/python3.8 -lpython3.8

clean:
	rm -f *.o main weather.so
