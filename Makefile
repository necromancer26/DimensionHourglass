program : main.o souris.o  soumenu.o animation.o chrono.o collisions.o enig.o enigme.o ennemieya.o game.o init.o intro.o menu.o source.o rotozoom.o
	gcc -o prog main.o souris.o  soumenu.o animation.o chrono.o collisions.o enig.o enigme.o ennemieya.o game.o init.o intro.o menu.o source.o rotozoom.o -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -lSDL_gfx
