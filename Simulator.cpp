#include "Simulator.h"

Simulator::Simulator()
{
  for (int i = 0; i < 1000; i++)
  {                                    // Llenar la matriz de memoria con datos iniciales
    memory[0][i] = "D" + to_string(i); // direccion de memoria
    memory[1][i] = to_string(i);       // valor de memoria
  }
}

// Setters and getters
void Simulator::setACC(int _ACC)
{
  ACC = _ACC;
}

void Simulator::setMAR(string _MAR)
{
  MAR = _MAR;
}

void Simulator::setICR(string _ICR)
{
  ICR = _ICR;
}

void Simulator::setUC(string _UC)
{
  UC = _UC;
}

void Simulator::setIDR(string _IDR)
{
  IDR = _IDR;
}

void Simulator::setMDR(string _MDR)
{
  MDR = _MDR;
}

int Simulator::getACC()
{
  return ACC;
}

string Simulator::getMAR()
{
  return MAR;
}

string Simulator::getICR()
{
  return ICR;
}

string Simulator::getUC()
{
  return UC;
}

string Simulator::getIDR()
{
  return IDR;
}

string Simulator::getMDR()
{
  return MDR;
}

void Simulator::start()
{
  string instrucction;
  string options[3];
  do
  {
    cin >> instrucction >> options[0] >> options[1] >> options[2];
    // cout << instrucction << options[0] << options[1] << options[2] << endl;

    if (instrucction == "END")
    {
      break;
    }
    else if (instrucction == "SET")
    {
      SET(options);
    }
    else if (instrucction == "ADD")
    {
      ADD(options);
    }
    else if (instrucction == "SUB")
    {
      SUB(options);
    }
    else if (instrucction == "MUL")
    {
      MUL(options);
    }
    else if (instrucction == "DIV")
    {
      DIV(options);
    }
    else if (instrucction == "INC") // INCREMENT
    {
      INC(options);
    }
    else if (instrucction == "DEC") // DECREMENT
    {
      DEC(options);
    }
    else if (instrucction == "MOV") // MOVE
    {
      MOV(options);
    }
    else if (instrucction == "LDR") // LOAD
    {
      LDR(options);
    }
    else if (instrucction == "STR") // STORE
    {
      STR(options);
    }
    else if (instrucction == "BEQ") // EQUAL
    {
      BEQ(options);
    }
    else if (instrucction == "AND")
    {
      AND(options);
    }
    else if (instrucction == "OR")
    {
      OR(options);
    }
    else if (instrucction == "SHW") // SHOW
    {
      SHW(options);
    }
    setUC(instrucction);
  } while (true);
  cout << result << endl;
}

void Simulator::SET(string options[])
{ // SET - Guarda el valor en la direccion de memoria ingresada
  // setACC(stoi(options[1]));
  STR(options);
}

void Simulator::ADD(string options[])
{                           // ADDITION -
  if (options[1] == "NULL") // D1 NULL NULL
  {                         // 1 parametro - carga el valor de la memoria y lo suma con el del acumulador
    int aux = getACC();
    LDR(options);
    setACC(getACC() + aux);
  }
  else
  {
    if (options[2] == "NULL") // D1 D2 NULL
    {                         // 2 parametros - carga los 2 valores de la memoria, los suma y lo guarda en el acumulador
      string ldrOptions[3] = {options[1], "NULL", "NULL"};
      string addOptions[3] = {options[0], "NULL", "NULL"};
      LDR(ldrOptions);
      ADD(addOptions);
    }
    else // D1 D2 D3
    {    // 3 parametros - carga los 2 valores de la memoria, los suma y lo guarda en la direccion de memoria
      string addOptions[3] = {options[0], options[1], "NULL"};
      ADD(addOptions);
      string strOptions[3] = {options[2], "NULL", "NULL"};
      STR(strOptions);
    }
  }
}

void Simulator::SUB(string options[])
{
  if (options[1] == "NULL")
  { // 1 parametro - carga el valor de la memoria y lo resta con el del acumulador
    int aux = getACC();
    LDR(options);
    setACC(getACC() - aux);
  }
  else
  {
    if (options[2] == "NULL")
    { // 2 parametros - carga los 2 valores de la memoria, los resta y lo guarda en el acumulador
      string ldrOptions[3] = {options[1], "NULL", "NULL"};
      string subOptions[3] = {options[0], "NULL", "NULL"};
      LDR(ldrOptions);
      SUB(subOptions);
    }
    else
    { // 3 parametros - carga los 2 valores de la memoria, los resta y lo guarda en la direccion de memoria
      string subOptions[3] = {options[0], options[1], "NULL"};
      SUB(subOptions);
      string strOptions[3] = {options[2], "NULL", "NULL"};
      STR(strOptions);
    }
  }
}

void Simulator::MUL(string options[])
{ // MULTIPLICATION -
  if (options[1] == "NULL")
  {
    int aux = getACC();
    LDR(options);
    while (aux > 1)
    {
      ADD(options);
      aux--;
    }
  }
  else
  {
    if (options[2] == "NULL")
    { // 2 parametros - carga los 2 valores de la memoria, los resta y lo guarda en el acumulador
      string ldrOptions[3] = {options[1], "NULL", "NULL"};
      string mulOptions[3] = {options[0], "NULL", "NULL"};
      LDR(ldrOptions);
      MUL(mulOptions);
    }
    else
    { // 3 parametros - carga los 2 valores de la memoria, los resta y lo guarda en la direccion de memoria
      string mulOptions[3] = {options[0], options[1], "NULL"};
      MUL(mulOptions);
      string strOptions[3] = {options[2], "NULL", "NULL"};
      STR(strOptions);
    }
  }
}

void Simulator::DIV(string options[])
{ // INTEGER DIVISION -
}

void Simulator::INC(string options[])
{ // INCREMENT -
}

void Simulator::DEC(string options[])
{ // DECREMENT -
}

void Simulator::MOV(string options[])
{ // MOVE -
}

void Simulator::LDR(string options[])
{ // LOAD - carga una direccion de memoria y lo agrega en el acumulador (ACC)
  int index;
  for (int i = 0; i < sizeof(memory[0]); i++)
  {
    if (memory[0][i] == options[0])
    {
      index = i;
      break;
    }
  }
  setMAR(memory[0][index]);
  setMDR(memory[1][index]);
  setACC(stoi(memory[1][index]));
}

void Simulator::STR(string options[])
{ // STORE - guarda lo del acumulador (ACC) en una direccion de memoria
  int index;
  for (int i = 0; i < sizeof(memory[0]); i++)
  {
    if (memory[0][i] == options[0])
    {
      index = i;
      break;
    }
  }
  setMAR(memory[0][index]);
  setMDR(to_string(getACC()));
  memory[1][index] = getMDR();
}

void Simulator::BEQ(string options[])
{ // EQUAL -
}

void Simulator::AND(string options[])
{ // AND GATE -
}

void Simulator::OR(string options[])
{ // OR GATE -
}

void Simulator::SHW(string option[])
{ // SHOW - Imprime los valores de los registros o de una direccion de memoria
  if (option[0] == "ACC")
  { // Valor del acumulator register
    result = to_string(getACC());
  }
  else if (option[0] == "ICR")
  { // Valor del ICR register
    result = getICR();
  }
  else if (option[0] == "MAR")
  { // Valor MAR register
    result = getMAR();
  }
  else if (option[0] == "MDR")
  { // Valor MDR register
    result = getMDR();
  }
  else if (option[0] == "UC")
  { // Valor en Control Unit
    result = getUC();
  }
  else
  {
    result = MDR_Read(option[0]);
  }
}

string Simulator::MDR_Read(string adress)
{
  int index;
  for (int i = 0; i < sizeof(memory[0]); i++)
  {
    if (memory[0][i] == adress)
    {
      index = i;
      break;
    }
  }
  return memory[1][index];
}