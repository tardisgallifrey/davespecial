//
// Created by tardis1 on 2/3/24.
//
#include <stdio.h>
#include <stdlib.h>
#include "app.h"

int init(){

   FILE* outfile;
   FILE* infile;

   infile = fopen(DATAFILE, "rb");

   if(infile != NULL){
      //file exists, nothing to do so return success
      fclose(infile);
      return 1;
   }

   // open file for writing
   outfile = fopen(DATAFILE, "wb");
   if (outfile == NULL) {
      fprintf(stderr, "\nError opened file\n");
      exit(1);
   }

   //create record 0
   struct Record initRecord = { 0, "rohan", "sharma", 0 };

   // write struct to file
   unsigned long flag = 0;
   flag = fwrite(&initRecord, sizeof(struct Record), 1,
                 outfile);
   if (flag) {
      //good write
      fclose(outfile);
      return 1;
   }
   else{
      //bad write
      fclose(outfile);
      return -1;
   }

}