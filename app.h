//
// Created by tardis1 on 2/3/24.
//

#ifndef DAVESSPECIAL_APP_H
#define DAVESSPECIAL_APP_H
struct Record {
   int id;
   char data1[50];
   char data2[50];
   long hash;
};

#define DATAFILE "datafile.bin"

void splashScreen();
int init();
int menu();
void addEntry();
int saveRecord(struct Record saveRecord);
struct Record getRecordbyID(int id);

#endif //DAVESSPECIAL_APP_H
