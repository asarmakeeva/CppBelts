#include "test_runner.h"
#include <sstream>
#include <string>
using namespace std;

// Параметры макроса LOG — объект класса Logger и строковое сообщение, которое должно быть передано в метод Log.
// В зависимости от настроек объекта класса Logger логируемое сообщение должно предваряться именем файла или номером строки. 
// Смотрите юнит-тесты в заготовке решения для более подробного описания поведения.

// Реализуйте макрос LOG так, чтобы он добавлял в логируемое сообщение имя файла и номер строки в зависимости от настроек 
//объекта logger. Пришлите на проверку cpp-файл, содержащий

// реализацию макроса LOG
// объявление класса Logger, при этом вы можете при необходимости добавлять в него дополнительные поля и методы
// определения всех методов класса Logger

class Logger {
public:
  explicit Logger(ostream& output_stream) : os(output_stream) {
  }

  void SetLogLine(bool value) { log_line = value; }
  void SetLogFile(bool value) { log_file= value; }

  void LogFile(string file){
      file_name = file;
  }
  void LogLine(int line){
      file_line = line;
  }
  void Log(const string& message){
      if (log_file && log_line){
          os << file_name << ":" << file_line << " " << message << endl;
      }
      else if (log_file){
          os << file_name << " " << message << endl;
      }
      else if (log_line){
          os << "Line " << file_line << " " << message << endl;
      }
      else os << message <<endl;
  }

private:
  ostream& os;
  bool log_line = false;
  bool log_file = false;
  string file_name;
  int file_line;
};

#define LOG(logger, message) \
  logger.LogFile(__FILE__);  \
  logger.LogLine(__LINE__);  \
  logger.Log(message);

void TestLog() {
/* Для написания юнит-тестов в этой задаче нам нужно фиксировать конкретные
 * номера строк в ожидаемом значении (см. переменную expected ниже). Если
 * мы добавляем какой-то код выше функции TestLog, то эти номера строк меняются,
 * и наш тест начинает падать. Это неудобно.
 *
 * Чтобы этого избежать, мы используем специальный макрос #line
 * (http://en.cppreference.com/w/cpp/preprocessor/line), который позволяет
 * переопределить номер строки, а также имя файла. Благодаря ему, номера
 * строк внутри функции TestLog будут фиксированы независимо от того, какой
 * код мы добавляем перед ней*/
#line 1 "logger.cpp"

  ostringstream logs;
  Logger l(logs);
  LOG(l, "hello");

  l.SetLogFile(true);
  LOG(l, "hello");

  l.SetLogLine(true);
  LOG(l, "hello");

  l.SetLogFile(false);
  LOG(l, "hello");

  string expected = "hello\n";
  expected += "logger.cpp hello\n";
  expected += "logger.cpp:10 hello\n";
  expected += "Line 13 hello\n";
  ASSERT_EQUAL(logs.str(), expected);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestLog);
}
