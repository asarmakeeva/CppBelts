#include "airline_ticket.h"
#include "test_runner.h"
#include <sstream>
#include <algorithm>
#include <numeric>
#include <tuple>
#include <iostream>
using namespace std;

// Напишите макрос SORT_BY, который принимает в качестве параметра имя поля структуры AirlineTicket. 
// Вызов sort(begin(tixs), end(tixs), SORT_BY(some_field)) должен приводить к сортировке вектора tixs по полю some_field.

// содержит определения операторов, необходимых для использования классов Date и Time в алгоритме сортировки и макросе 
//ASSERT_EQUAL (формат вывода в поток можете выбрать произвольный)


#define SORT_BY(field)                                          \
    [](const AirlineTicket& lhs, const AirlineTicket& rhs) { return lhs.field < rhs.field;}                     

bool operator<(const Date& lhs, const Date& rhs) {
    return tie(lhs.year, lhs.month, lhs.day) < tie(rhs.year, rhs.month, rhs.day);
}
bool operator==(const Date& lhs, const Date& rhs) {
   return tie(lhs.year, lhs.month, lhs.day) == tie(rhs.year, rhs.month, rhs.day);
}
ostream& operator<<(ostream& stream, const Date& date) {
  stream << date.year << "-" <<date.month << "-" <<  date.day;
  return stream;
}
bool operator<(const Time& lhs, const Time& rhs) {
    return tie(lhs.hours, lhs.minutes) < tie(rhs.hours, rhs.minutes);
}
bool operator==(const Time& lhs, const Time& rhs) {
   return tie(lhs.hours, lhs.minutes) == tie(rhs.hours, rhs.minutes);
}
ostream& operator<<(ostream& stream, const Time& times) {
  stream << times.hours << ":" << times.minutes;
  return stream;
}
void TestSortBy() {
  vector<AirlineTicket> tixs = {
    {"VKO", "AER", "Utair",     {2018, 2, 28}, {17, 40}, {2018, 2, 28}, {20,  0}, 1200},
    {"AER", "VKO", "Utair",     {2018, 3,  5}, {14, 15}, {2018, 3,  5}, {16, 30}, 1700},
    {"AER", "SVO", "Aeroflot",  {2018, 3,  5}, {18, 30}, {2018, 3,  5}, {20, 30}, 2300},
    {"PMI", "DME", "Iberia",    {2018, 2,  8}, {23, 00}, {2018, 2,  9}, { 3, 30}, 9000},
    {"CDG", "SVO", "AirFrance", {2018, 3,  1}, {13, 00}, {2018, 3,  1}, {17, 30}, 8000},
  };

   sort(begin(tixs), end(tixs), SORT_BY(price));
   ASSERT_EQUAL(tixs.front().price, 1200);
   ASSERT_EQUAL(tixs.back().price, 9000);

  sort(begin(tixs), end(tixs), SORT_BY(from));
   ASSERT_EQUAL(tixs.front().from, "AER");
   ASSERT_EQUAL(tixs.back().from, "VKO");

   sort(begin(tixs), end(tixs), SORT_BY(arrival_date));
   ASSERT_EQUAL(tixs.front().arrival_date, (Date{2018, 2, 9}));
   ASSERT_EQUAL(tixs.back().arrival_date, (Date{2018, 3, 5}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestSortBy);
}