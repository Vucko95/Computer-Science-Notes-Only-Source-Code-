/* Project: C++ Assignment 3
 * Purpose: Mainline - All Pairs Shortest Path 
 * File:    APSP.cpp
 * Author:  COAD021
 * Date:    02APR2001
 */

#include <fstream.h>
#include <stdlib.h>
#include <string.h>
#include "A3.h"
#include "TwoDIntArray.h"
#include "StringTable.h"
#include "Stack.h"

int main(int argc, char * argv[]) {
   try {
      ifstream in;
      
      // Check arguments and open country file
      //==========================================================
      getArgs(argc, argv, in);

      // Get number of cities from first line of file
      //==========================================================
      char buf[MAX_LINE_LENGTH];
      in.getline(buf,MAX_LINE_LENGTH-1);
      int cities = atoi(buf);                    
      if(!cities)                                
         throw MyException("File does not have number "
                        "of cities as the first line.");

      // Construct Distance and Predecessor matrices
      //==========================================================
      TwoDIntArray DistanceMatrix(cities,cities);
      TwoDIntArray PredecessorMatrix(cities,cities);
      
      //Initialize the matrices
      //==========================================================
      InitMatrices(DistanceMatrix, PredecessorMatrix, cities);
      
      // Construct the String Table
      //==========================================================
      StringTable st(cities,MAX_STRING_LENGTH);   
      
      // Read in the map data from the data file
      //==========================================================
      getMapData(in, st, buf, DistanceMatrix, PredecessorMatrix);
     
      // Check if command line city names are in the data file
      //==========================================================
      bool ArgCheck = TestArgs(argv[1],cities,st);
      if(!ArgCheck) {
         throw MyException("Start city not found in map file.");
      } 
      char * StartCity = argv[1];          

      ArgCheck = TestArgs(argv[2],cities,st);
      if(!ArgCheck) {
         throw MyException("End city not found in map file.");
      }
      char * EndCity = argv[2];
      
      // Floyd-Warshall Algorithm function
      //==========================================================
      FloydWarshall(DistanceMatrix, PredecessorMatrix, cities);
      
      // Construct Stack for storing route city names
      //==========================================================
      Stack Reverse(sizeof(int));
      
      // Place route cities on stack for reversal
      //==========================================================
      StackCities(StartCity, EndCity, DistanceMatrix, 
                  PredecessorMatrix, st, Reverse);
      
      // Display the route - Start city to End city
      //==========================================================
      DispRoute(Reverse, st);     // For testing

      // Display the Intervening cities and the distances between 
      // them including the cumulative distances for the route
      //==========================================================
      DispItinerary(st, StartCity, EndCity, DistanceMatrix, Reverse);

   }catch (MyException e) {
      cout<<e.getMessage()<<endl<<endl;
      return 1;
   }     
   
   return 0;
}

// Check arguments and open country file
//================================================================
void getArgs(int argc, char* argv[], ifstream &in) {
   if (argc != 4) {
      cout<<"Usage example: A3 Paris Marseille FranceData.txt\n"
            "     Where the first argument, 'A3', is the program name,\n"
            "     the second, 'Paris', is the starting city,\n"
            "     the third,  'Marseille', is the ending city and\n"
            "     the fourth, 'FranceData.txt', is the country map file name.\n"
            "     - The city names are case sensitive."<<endl;
            //"     Available road maps: France, Ireland, NS (Nova Scotia)"
      throw MyException("Wrong Number of arguments.");
   }else {
      in.open(argv[3],ios::in|ios::nocreate);  
      if (!in) {
         throw MyException("Could not open map file.");         
      }   
   }
}


// Check if command line city names are in the data file
//================================================================
bool TestArgs (char * Arg,int NumCities,StringTable &st) {
   
   int TestString;   
   
   for(int a=0;a<NumCities;a++) {
      TestString = strcmp(Arg,st.getString(a));
      if (TestString == 0) return true;         
   }
   return false;                                 // City name not found
}

// Display the route - Start city to End city
//==========================================================
void DispRoute(Stack &Reverse, StringTable &st) {
   int CityIndex;
   cout<<"\t"<<"The shortest route is as follows:\n\n\t";        
   for(int m=Reverse.getNumber(); m>-1; m--) {
      CityIndex = *(int *)Reverse.Read(m);
      cout<<st.getString(CityIndex)<<"  ";
   }
   //cout<<endl;
}

//Initialize the matrices
//================================================================
void InitMatrices(TwoDIntArray &DistanceMatrix, 
                  TwoDIntArray &PredecessorMatrix, int cities) {
     
   for(int p=0; p<cities; p++) {                  // Initialize distance matrix
      for (int q=0; q<cities; q++) {
         if (p == q) {
            DistanceMatrix(p, q) = 0;
            PredecessorMatrix(p, q) = 9999;
         }else {
            DistanceMatrix(p, q) = 9999;         // 9999 = infinity
         }
      }
   }
} 

// Read in the map data from the data file
//================================================================
void getMapData(ifstream &in, StringTable &st, char * buf, 
                TwoDIntArray &DistanceMatrix, TwoDIntArray &PredecessorMatrix) {
   char * City1 = {0};
   char * City2 = {0};
   char * DistTemp;
   char * Trash = {0};
   int City1Index;
   int City2Index;
   int Distance;   
   
   while (in.getline(buf,MAX_LINE_LENGTH)) {     // Get next line of data
      City1Index=NOTFOUND;                       // NOTFOUND = -1
      City2Index=NOTFOUND;
      if(City1=strtok(buf,DELIMITER)) {          // Skips blank lines in map file
         City2=strtok(NULL,DELIMITER);
         if (City2 == NULL)                      // No second city
            throw MyException("Data read error in map file. No delimiter?");
         DistTemp=strtok(NULL,DELIMITER);
         if (DistTemp == NULL)                   // No distance at end of line
            throw MyException("Data read error in map file. No delimiter?");
         Trash = strtok(NULL,DELIMITER);
         if (Trash != NULL)                      // Extra data at end of line
            throw MyException("Unrecognized data in map file. Too many items on line?");
         Distance=atoi(DistTemp);
         if(!Distance)                           // Data at end of line is not an integer
            throw MyException("Data read error in map file. No distance?");
         
         City1Index=st.addString(City1);        // Add city to string table
         City2Index=st.addString(City2);  
         DistanceMatrix(City1Index, City2Index) = Distance;        // Seed distance matrix
         PredecessorMatrix(City1Index, City2Index) = City1Index;   // Seed predecessor matrix
      }
   }
   in.close(); 
}

// Floyd-Warshall Algorithm function 
// ((i, k) + (k, j)) = Path through k
// (i, j) = Path not through k
//==========================================================
void FloydWarshall(TwoDIntArray &DistanceMatrix, 
                   TwoDIntArray &PredecessorMatrix, int cities) {         

   int DistAdder;
   for (int k=0; k<cities; k++) {
      for (int i=0; i<cities; i++) {
         for (int j=0; j<cities; j++) {            
            DistAdder = DistanceMatrix(i, k) + DistanceMatrix(k, j);
            if( DistAdder < DistanceMatrix(i, j)) {                  
               DistanceMatrix(i, j) = DistAdder;                   // Update distance matrix
               PredecessorMatrix(i, j) = PredecessorMatrix(k, j);  // Update predecessor matrix
            }  
         }
      }
   }
}

// Place route cities on stack for reversal
//================================================================
void StackCities(char * StartCity, char * EndCity, 
                 TwoDIntArray &DistanceMatrix, 
                 TwoDIntArray &PredecessorMatrix, 
                 StringTable &st, Stack &Reverse) {

   // Place the route cities on the stack
   //======================================================================      
   
   // Stack the end city
   int Previous = st.getIndex(EndCity);
   if (!Reverse.Push(&Previous)) {
      throw MyException("Stack 'Push' failure");
   }
   
   // Stack the intervening cities
   while(PredecessorMatrix(st.getIndex(StartCity),Previous) != st.getIndex(StartCity)) {
      Previous = PredecessorMatrix(st.getIndex(StartCity),Previous);
      if (!Reverse.Push(&Previous)) {
         throw MyException("Stack 'Push' failure");
      }
   }
   // Stack the start city
   Previous = st.getIndex(StartCity);
   if (!Reverse.Push(&Previous)) {
         throw MyException("Stack 'Push' failure");
   }      
}

// Display the Intervening cities and the distances between 
// them including the cumulative distances for the route
//================================================================
void DispItinerary(StringTable &st, char * StartCity, char * EndCity,
                   TwoDIntArray &DistanceMatrix, Stack &Reverse) {
   int RouteDistance;
   int TripTotal;
   int NameLength1;
   int NameLength2;
   int Space1;
   int Space2;
   const char * RouteCity1;
   const char * RouteCity2;
   
   int DisplayDistance = DistanceMatrix(st.getIndex(StartCity),st.getIndex(EndCity));
   
   cout<<"\n\n\tThe shortest distance from "
      <<StartCity<<" to "<<EndCity<<" is "
      <<DisplayDistance<<" kilometers."<<endl<<endl;      
   cout<<"    +---------------------------------------------------------------------+"<<endl;
   cout<<"    |    Distances in kilometers between cities on the shortest route     |"<<endl;
   cout<<"    +------------------+------------------+----------------+--------------+"<<endl;
   cout<<"    |                  |                  |    Distance    |  Cumulative  |"<<endl;
   cout<<"    |  From            |  To              | Between Cities |   Distance   |"<<endl;
   cout<<"    +------------------+------------------+----------------+--------------+"<<endl;
   for (int n=Reverse.getNumber(); n>0; n--) {
      RouteDistance = DistanceMatrix(*(int *)Reverse.Read(n),*(int *)Reverse.Read(n-1));         
      RouteCity1 = st.getString(*(int *)Reverse.Read(n));
      NameLength1 = strlen(RouteCity1);
      Space1 = 15 - NameLength1;
      RouteCity2 = st.getString(*(int *)Reverse.Read(n-1));
      NameLength2 = strlen(RouteCity2);
      Space2 = 15 - NameLength2;
      TripTotal =  DistanceMatrix(st.getIndex(StartCity),*(int *)Reverse.Read(n-1));
      cout<<"    |  "<<RouteCity1;
      for (int y=0; y<Space1; y++) cout<<" ";
      cout<<" |  "<<RouteCity2;
      for (y=0; y<Space2; y++) cout<<" ";
      cout<<" |     "<<RouteDistance<<"  ";
      if        (RouteDistance <10 )cout<<"        |     ";
         else if(RouteDistance <100 )cout<<"       |     ";
         else if(RouteDistance <1000) cout<<"      |     ";
         else                          cout<<"     |     ";
      cout<<TripTotal;
      if        (TripTotal <10 )cout<<"        |\n";
         else if(TripTotal <100 )cout<<"       |\n";
         else if(TripTotal <1000 )cout<<"      |\n";
         else                      cout<<"     |\n";
   }
    cout<<"    +------------------+------------------+----------------+--------------+"<<endl;
}