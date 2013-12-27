#pragma once

#include <string>
#include <deque>
#include <atomic>
#include <future>
#include "Integer.h"
#include "Conversions.h"
#include "Fileops.h"
#include "MathFunctions.h"

using namespace std;

extern atomic_flag stop;

int getFibonacci();
int calcFibonacci();
int getFibonacci2();
int calcFibonacci2();

int getFactorial();
int calcFactorial();

int getPowersOf2();
int calcPowersOf2();

void inputLoop();
int ProjectEuler();

int empty();