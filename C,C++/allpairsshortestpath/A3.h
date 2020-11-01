/* Project: C++ Assignment 3
 * Purpose: Header for Mainline - All Pairs Shortest Path 
 * File:    A3.h
 * Author:  COAD021
 * Date:    02APR2001
 */

#ifndef A3HEADER_H
#define A3HEADER_H

#include "StringTable.h"
#include "TwoDIntArray.h"
#include "Stack.h"

#define MAX_LINE_LENGTH 132
#define MAX_STRING_LENGTH 32
#define DELIMITER ","
#define NOTFOUND -1

bool TestArgs (char * Arg,int NumCities,StringTable &st);
void PrintPredChart(int cities, StringTable &st, TwoDIntArray &PredecessorArray);
void DispItinerary(StringTable &st, char * StartCity,  char * EndCity, TwoDIntArray &DistanceMatrix, Stack &Reverse);
void DispRoute(Stack &Reverse, StringTable &st);
void InitMatrices(TwoDIntArray &DistanceMatrix, TwoDIntArray &PredecessorMatrix, int cities);
void getMapData(ifstream &in, StringTable &st, char * buf, TwoDIntArray &DistanceMatrix, TwoDIntArray &PredecessorMatrix);
void FloydWarshall(TwoDIntArray &DistanceMatrix, TwoDIntArray &PredecessorMatrix, int cities);
void StackCities(char * StartCity, char * EndCity, TwoDIntArray &DistanceMatrix, TwoDIntArray &PredecessorMatrix, StringTable &st, Stack &Reverse);
void getArgs(int argc, char* argv[], ifstream &in);

#endif //A3HEADER_H