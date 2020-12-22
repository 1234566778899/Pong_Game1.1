#include<iostream>
#include <stdio.h>  
 #include <windows.h>  
#include<conio.h>
using namespace std;
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  
void dibujar(int x,int y) {
gotoxy(x, y);
cout << "*";
}
void borrar(int x, int y) {
gotoxy(x, y);
cout << " ";
}
void mapa(int x,int y) {
for (int i = 0; i < 21; i++) {
gotoxy(x,y);
for (int j = 0; j < 75; j++) {
if (i == 0 || j == 0 || i == 20 || j == 74)
cout << "*";
else
cout << " ";
}
y++;
}
}
void jugador(int x, int y) {
gotoxy(x, y-1);
cout << "#";
gotoxy(x, y);
cout << "#";
gotoxy(x, y+1);
cout << "#";
}
void jugador2(int x, int y) {
gotoxy(x, y - 1);
cout << "#";
gotoxy(x, y);
cout << "#";
gotoxy(x, y + 1);
cout << "#";
}
void borrar_jugador(int x, int y) {
gotoxy(x, y - 1);
cout << " ";
gotoxy(x, y);
cout << " ";
gotoxy(x, y + 1);
cout << " ";
}
int main()
{
int x=5, y=3;
int dx=1, dy=1;
int jx = 4, jy=6; int djy = 0;
int j2x = 70, j2y = 8; int dj2y = 0;
dibujar(x, y);
jugador(jx, jy);
jugador2(j2x, j2y);
mapa(0,0);
while (1) {
jugador2(j2x, j2y);
borrar(x, y);
x += dx; y += dy;
dibujar(x, y);
_sleep(100);
if (x + dx == 0 || x + dx == 74) {
dx = -dx;
}
if( y + dy == 0 || y + dy == 20)
{
dy = -dy;
}
if (_kbhit()) {
borrar_jugador(jx, jy);
borrar_jugador(j2x, j2y);
char tecla = _getch();
switch (tecla) {
//jugador 1;
case 'w': djy = -1; break;
case 's': djy = 1; break;
//jugador 2;
case 'i': dj2y = -1; break;
case 'k': dj2y = 1; break;
}
}
//segunda validacion;
if (jy + djy == 1 || jy + djy == 19)
{
djy = 0;
}
if (j2y + dj2y == 1 || j2y + dj2y == 19)
{
dj2y = 0;
}
jy += djy; //jugador1;
j2y += dj2y; //jugador2;
jugador(jx, jy);
jugador(j2x, j2y);
djy = 0; dj2y = 0;
if (x + dx == jx && y + dy == jy|| x + dx == jx && y + dy == jy+1|| x + dx == jx && y + dy == jy-1)
{
dx = -dx; dy = -dy;
}
if (x + dx == j2x && y + dy == j2y || x + dx == j2x && y + dy == j2y + 1 || x + dx == j2x && y + dy == j2y - 1)
{
dx = -dx; dy = -dy;
}
}
return 0;
}
