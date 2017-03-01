draw: main.c
	gcc main.c draw.c display.c matrix.c -o draw

run: draw
	./draw
	display image.ppm

clean:
	rm *~ *.ppm
