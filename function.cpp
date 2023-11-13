#include "header.h"
#include <cstdint>

int Player(int *health, int *energy, int *count) { return *count; }

int Enemy(int *health, int *energy, int *count) { return *count; }

int CreateEnemy(int *health, int *energy, int *count,
  int (*pP)(int *, int *, int *)) {
    return pP(health, energy,count);
}
