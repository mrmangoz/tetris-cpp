#ifndef THREAD_H_INCLUDED
#define THRAD_H_INCLUDED
#include <atomic>
using namespace std;

void checkInput(atomic_bool &done);
char getKey();

#endif