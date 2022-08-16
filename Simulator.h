#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;

class Simulator
{
public:
  Simulator();
  // setters and getters
  void setACC(int _ACC);
  void setMAR(string _MAR);
  void setICR(string _ICR);
  void setUC(string _UC);
  void setIDR(string _IDR);
  void setMDR(string _MDR);

  int getACC();
  string getMAR();
  string getICR();
  string getUC();
  string getIDR();
  string getMDR();

  string result = "";
  void start(string inputOptions[]);
  void lectura();

  void SET(string options[]);
  void ADD(string options[]);
  void SUB(string options[]);
  void MUL(string options[]);
  void DIV(string options[]);
  void INC(string options[]);
  void DEC(string options[]);
  void MOV(string options[]);
  void LDR(string option);
  void STR(string address, string value);
  void BEQ(string options[]);
  void AND(string options[]);
  void OR(string options[]);
  void SHW(string options[]);

  string MDR_Read(string adress);

private:
  int ACC;
  string MAR, ICR, UC, IDR, MDR;
  string memory[2][1000];
};

#endif
