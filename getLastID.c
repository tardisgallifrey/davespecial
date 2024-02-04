//
// Created by tardis1 on 2/4/24.
//
#include "app.h"

int getLastID(){
   int id;
   FILE* infile;
   struct Record tempRecord;
   unsigned long flag;

   infile = fopen(DATAFILE, "rb");

   do{

      flag = fread( &tempRecord, sizeof(struct Record), 1, infile);
      id = tempRecord.id;

   }while(!feof(infile));

   return id;
}