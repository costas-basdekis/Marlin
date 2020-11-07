#include <sstream>
#include "./TestLogger.h"

TestLogger::TestLogger() {
  bufferSize = 2048;
  buffer = new char[bufferSize];
  bufferPosition = 0;
}

TestLogger::~TestLogger() {
  delete[] buffer;
  bufferSize = 0;
  bufferPosition = 0;
}

bool TestLogger::canAdd(PGM_P str) {
  return canAdd(str, 0);
}

bool TestLogger::canAdd(PGM_P str, std::size_t extraCount) {
  const std::size_t newSize = std::strlen(str);
  return (bufferPosition + newSize + extraCount) < bufferSize;
}

void TestLogger::add(PGM_P str) {
  if (!canAdd(str)) {
    bufferPosition = bufferSize;
    std::strcpy(buffer, "--- RUN OUT OF SPACE ---");
    return;
  }

  std::strcpy(buffer + bufferPosition, str);
  const std::size_t newSize = std::strlen(str);
  bufferPosition += newSize;
  buffer[bufferPosition] = 0;
}

void TestLogger::add(char v) {
  char buffer[128];
  sprintf(buffer, "%c", v);
  add(buffer);
}

void TestLogger::add(int v) {
  char buffer[128];
  sprintf(buffer, "%d", v);
  add(buffer);
}

void TestLogger::add(long v) {
  char buffer[128];
  sprintf(buffer, "%ld", v);
  add(buffer);
}

void TestLogger::add(float v) {
  char buffer[128];
  sprintf(buffer, "%f", v);
  add(buffer);
}

void TestLogger::add(double v) {
  char buffer[128];
  sprintf(buffer, "%f", v);
  add(buffer);
}

void TestLogger::add(unsigned int v) {
  char buffer[128];
  sprintf(buffer, "%u", v);
  add(buffer);
}

void TestLogger::add(unsigned long v) {
  char buffer[128];
  sprintf(buffer, "%ld", v);
  add(buffer);
}

void TestLogger::clean() {
  bufferPosition = 0;
  buffer[bufferPosition] = 0;
}

void TestLogger::echo(PGM_P v) {
  add(v);
}

void TestLogger::echo(char v) {
  add(v);
}

void TestLogger::echo(int v) {
  add(v);
}

void TestLogger::echo(long v) {
  add(v);
}

void TestLogger::echo(float v) {
  add(v);
}

void TestLogger::echo(double v) {
  add(v);
}

void TestLogger::echo(unsigned int v) {
  add(v);
}

void TestLogger::echo(unsigned long v) {
  add(v);
}

void TestLogger::echoPgm(PGM_P str) {
  echo(str);
}

void TestLogger::echoPgm(PGM_P str, PGM_P str2) {
  echo(str);
  echo(str2);
}

void TestLogger::echoPgm(PGM_P str, char v) {
  echo(str);
  echo(v);
}

void TestLogger::echoPgm(PGM_P str, int v) {
  echo(str);
  echo(v);
}

void TestLogger::echoPgm(PGM_P str, long v) {
  echo(str);
  echo(v);
}

void TestLogger::echoPgm(PGM_P str, float v) {
  echo(str);
  echo(v);
}

void TestLogger::echoPgm(PGM_P str, double v) {
  echo(str);
  echo(v);
}

void TestLogger::echoPgm(PGM_P str, unsigned int v) {
  echo(str);
  echo(v);
}

void TestLogger::echoPgm(PGM_P str, unsigned long v) {
  echo(str);
  echo(v);
}

void TestLogger::echoLn() {
  add("\n");
}

void TestLogger::echoLnPgm(PGM_P str) {
  echoPgm(str);
  echoLn();
}

void TestLogger::echoLnPgm(PGM_P str, PGM_P str2) {
  echoPgm(str, str2);
  echoLn();
}

void TestLogger::echoLnPgm(PGM_P str, char v) {
  echoPgm(str, v);
  echoLn();
}

void TestLogger::echoLnPgm(PGM_P str, int v) {
  echoPgm(str, v);
  echoLn();
}

void TestLogger::echoLnPgm(PGM_P str, long v) {
  echoPgm(str, v);
  echoLn();
}

void TestLogger::echoLnPgm(PGM_P str, float v) {
  echoPgm(str, v);
  echoLn();
}

void TestLogger::echoLnPgm(PGM_P str, double v) {
  echoPgm(str, v);
  echoLn();
}

void TestLogger::echoLnPgm(PGM_P str, unsigned int v) {
  echoPgm(str, v);
  echoLn();
}

void TestLogger::echoLnPgm(PGM_P str, unsigned long v) {
  echoPgm(str, v);
  echoLn();
}

char *TestLogger::getBuffer() {
  return buffer;
}

std::vector<std::string> TestLogger::getBufferLines() {
  auto lines = std::vector<std::string>{};
  std::string strBuffer(buffer);
  auto stream = std::stringstream{strBuffer};

  for (std::string line; std::getline(stream, line, '\n');) {
    lines.push_back(line);
  }

  return lines;
}
