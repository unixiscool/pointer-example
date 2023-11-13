#include "header.h"
int Player(int* health, int* energy, int* count);
  
int main() {
  //structure begin
  int health = 150;
  int energy = 100;
  int count_arg = 3;
  //structure end
  int player[3] = {health,energy,count_arg}; //array of player
  
  int (*p)(int*,int*,int*) = &Player; //указатель на функцию
  p(&player[1], &player[2], &player[3]); //передаем параметры
  printf("%d\n", player[0]); //выводим 0 элемент и получаем "150" в терминал, т.е число energy
  
  return 0; 
}
