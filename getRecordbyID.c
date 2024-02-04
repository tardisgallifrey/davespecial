//
// Created by tardis1 on 2/4/24.
//
#include <stdio.h>
#include <stdlib.h>
#include "app.h"

struct Record getRecordbyID(int id){
   struct Record tempRecord;
   unsigned long flag;

   FILE* infile;

   infile = fopen(DATAFILE, "rb");

   if(infile == NULL){
      printf("\nsomething went wrong");
      exit(1);
   }else{
      do{
         flag = fread(&tempRecord, sizeof(struct Record), 1, infile);

         if(tempRecord.id == id){
            break;
         }

      }while(!feof(infile));
   }

   if(tempRecord.id != id){
      printf("\nRecord not found. Returning last record.");
   }
   return tempRecord;
}