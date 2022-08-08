#ifndef PCALGORITHM_UTILS_H
#define PCALGORITHM_UTILS_H
#include "./Elementary.h"

vector<Rule5> loadRule5(FILE *fp);
vector<Rule12> loadRule12(FILE *fp);

vector<Packet5> loadPakcet5(FILE *fp);
vector<Packet12> loadPakcet12(FILE *fp);
#endif //PCALGORITHM_UTILS_H
