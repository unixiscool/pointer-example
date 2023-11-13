#include "header.h"
int Player(int* health, int* energy, int* count);
int Enemy(int *health, int *energy, int *count);
/*int CreateEnemy(int *health, int *energy, int *count,
                int (*pP)(int *, int *, int *));
*/
// int CreateEnemy(int (*pP)(int *, int *, int *));
// bool Battle(int* player, int* enemy, int enemyDamage, int playerDamage, char*
// choose);
bool Battle(int* player, int* enemy, char choose, bool win);
#define MIN_HEALTH 0
#define MAX_HEALTH 200
bool (*B)(int *, int *, char, bool) = Battle;
int (*pE)(int *, int *, int *) = Enemy;
char choose;
bool victory;
int main() {
  //structure enemy begin
  int healthE = 50;
  int energyE = 25;
  int count_argE = 3;
  int enemy_D = 5;
  //structure enemy end
  
  //structure player begin
  int health = 150;
  int energy = 100;
  int count_arg = 3;
  int player_D = 10;
  //structure player end
  int player[3] = {health,energy,count_arg}; //array of player
  int enemy[3] = {healthE, energyE, count_argE};
  
  int (*p)(int*,int*,int*) = Player; //указатель на функцию
  p(&player[0], &player[1], &player[2]); //передаем параметры
  
  pE(&enemy[0], &enemy[1], &enemy[2]);
  printf("%d\n", enemy[0]); //выводим 0 элемент и получаем "150" в терминал, т.е число energy
  //int (*pCreateEnemy)(int *, int *, int *, int (*)(int *, int *, int *)) = CreateEnemy;
  B(player, enemy, choose, victory);
  return 0; 
}
