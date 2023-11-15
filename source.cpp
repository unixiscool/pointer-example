#include "header.h"
#include <locale>
int Player(int* health, int* energy, int* count, int*);
int Enemy(int *health, int *energy, int *count);
bool Battle(int *player, int *enemy, char choose, bool win, int* money);
int CreateEnemy(int *health, int *energy, int *count,
                int (*pP)(int *, int *, int *));
//char Menu(char *choose);
void Menu(int player[], int enemy[], char choose1, bool win, int* money, char choose, bool (*tmp)(int *, int *, char, bool, int* ));

// int CreateEnemy(int (*pP)(int *, int *, int *));
// bool Battle(int* player, int* enemy, int enemyDamage, int playerDamage, char*
// choose);p

#define MIN_HEALTH 0
#define MAX_HEALTH 200
int money = 0;
int* mP = &money;
int* mP2 = &money;
bool (*B)(int *, int *, char, bool, int*) = Battle;
int (*pE)(int *, int *, int *) = Enemy;
int (*p)(int*,int*,int*, int*) = Player;
//char (*pC)(char *) = Menu;
void (*pM)(int*, int*, char, bool, int*, char, bool (*tmp)(int*, int*, char, bool, int* ));
char choose;
char* chP = &choose;
bool victory;
int main() {
  //structure enemy begin
  int healthE = 50;
  int energyE = 25;
  int count_argE = 3;
  int enemy_D = 5;
  int enemy[3] = {healthE, energyE, count_argE};
  pE(&enemy[0], &enemy[1], &enemy[2]);
  //structure enemy end
  
  //structure player begin
  int health = 150;
  int energy = 100;
  int count_arg = 3;
  int player_D = 10;
  
  int player[4] = {health,energy,count_arg, player_D};//array of player
  p(&player[0], &player[1], &player[2], &player[3]); // передаем параметры
  //structure player end
  
  // printf("%d\n", player[0]); //выводим 0 элемент и получаем "150" в терминал, т.е число energy
  
  while (true) {
    //Battle(player, enemy, choose, victory, mP);
    pM(player, enemy, choose, victory, mP, choose, B);
  }
  return 0; 
}
