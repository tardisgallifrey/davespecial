#include <stdio.h>
#include <stdlib.h>
#include "app.h"

//TODO write getRecordbyValue function(s)
//TODO change to use file from command line or builtin
//TODO test for bad inputs

int main() {

   int menuChoice;
   int id;
   struct Record tempRecord;

   //initialize
   if(init()){
      splashScreen();
   }else{
      printf("\nSomething didn't work right.\n");
      exit(0);
   }

   //menu
   do{
      menuChoice = menu();

      switch(menuChoice){
         case 1:
            addEntry();
            break;
         case 2:
            printf("\nEnter id of record to find: ");
            scanf(" %d", &id);
            tempRecord = getRecordbyID(id);
            printf("\n   id: %d", tempRecord.id);
            printf("\n   data1: %s", tempRecord.data1);
            printf("\n   data2: %s\n", tempRecord.data2);
            break;
         case 9:
            printf("\nProgram ending normally.");
            break;
         default:
            printf("\nIncorrect choice.  Return to Menu.");

      }
   }while(menuChoice != 9);


   return 0;
}
