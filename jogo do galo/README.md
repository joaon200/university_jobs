This is my first project in C language.
The project consist on a app with three modes of playing, 1vs1, easy and hard.
On the screen apears a menu, made with switch function, to choose the mode of playing. If 1vs1 mode was choosen the next interaction ask you 
the name of the first player and afterr the name of second player.
When the name are chosen appears on the screen the game table, the gme table are made by a 3*3 matrix initializaded with "." on ever 
positions. The first player choose her first playthroug introducing a bidimensional coordinate, if he introduce a number major of 3 the 
system issues a warming and asks to try again. The choosen position is changed in the matrix to an "x". Same processe are made for the second 
player but instead a "x" the position on matrix are changed to an "o".
This processe is repeated until someone make tik-tak-toe or reaches nine moves. The tik-tak-toe are monitoring by a extense elsif loop and 
the number of moves is controled by a For loop.
