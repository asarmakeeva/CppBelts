#include "test_runner.h"

#include <ostream>
using namespace std;

#define PRINT_VALUES(out, x, y) \
do {out << (x) << "\n" << (y) << "\n";}\
while (0)
int main() {
  TestRunner tr;
  tr.RunTest([] {
    ostringstream output;
    PRINT_VALUES(output, 5+1, "red belt");
    ASSERT_EQUAL(output.str(), "6\nred belt\n");
  }, "PRINT_VALUES usage example");
}