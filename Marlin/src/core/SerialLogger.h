#pragma once

#define PGM_P const char *

class SerialLogger {
public:
  virtual void echo(PGM_P str);
  virtual void echo(char v);
  virtual void echo(int v);
  virtual void echo(long v);
  virtual void echo(float v);
  virtual void echo(double v);
  virtual void echo(unsigned int v);
  virtual void echo(unsigned long v);
  virtual void echoPgm(PGM_P str);
  virtual void echoPgm(PGM_P str, PGM_P str2);
  virtual void echoPgm(PGM_P str, char v);
  virtual void echoPgm(PGM_P str, int v);
  virtual void echoPgm(PGM_P str, long v);
  virtual void echoPgm(PGM_P str, float v);
  virtual void echoPgm(PGM_P str, double v);
  virtual void echoPgm(PGM_P str, unsigned int v);
  virtual void echoPgm(PGM_P str, unsigned long v);
  virtual void echoLn();
  virtual void echoLnPgm(PGM_P str);
  virtual void echoLnPgm(PGM_P str, PGM_P str2);
  virtual void echoLnPgm(PGM_P str, char v);
  virtual void echoLnPgm(PGM_P str, int v);
  virtual void echoLnPgm(PGM_P str, long v);
  virtual void echoLnPgm(PGM_P str, float v);
  virtual void echoLnPgm(PGM_P str, double v);
  virtual void echoLnPgm(PGM_P str, unsigned int v);
  virtual void echoLnPgm(PGM_P str, unsigned long v);
};
