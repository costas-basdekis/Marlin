#include <iostream>
#include <vector>
#include <src/core/SerialLogger.h>

class TestLogger : public SerialLogger {
public:
  TestLogger();
  virtual ~TestLogger();

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

  bool canAdd(PGM_P str);
  bool canAdd(PGM_P str, std::size_t extraCount);
  void add(PGM_P str);
  void add(char v);
  void add(int v);
  void add(long v);
  void add(float v);
  void add(double v);
  void add(unsigned int v);
  void add(unsigned long v);

  void clean();
  char *getBuffer();
  std::vector<std::string> getBufferLines();

private:
  char *buffer;
  std::size_t bufferSize;
  std::size_t bufferPosition;
};
