#include "Course.hpp"

using namespace std;


Course::Course(string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time) : title(title), day(day),
                                                                                                 start_time(start_time),finish_time(finish_time) {}

Course::Course(const Course &course) : title(course.title), day(course.day), start_time(course.start_time), finish_time(course.finish_time) {}

Course &Course::operator=(const Course &rhs) = default;


bool Course::operator==(const Course &rhs) const {
    return title == rhs.title && day == rhs.day && start_time == rhs.start_time && finish_time == rhs.finish_time;
}
bool Course::operator<(const Course &rhs) const {
    if (day == rhs.day)
        if (start_time < rhs.start_time)
            return true;
    return day < rhs.day;
}
ostream &operator<<(ostream &os, const Course &rhs) {
    string d;
    switch(rhs.day) {
        case Course::MON:
            d= "M";
        case Course::TUE:
            d= "T";
        case Course::WED:
            d= "W";
        case Course::FRI:
            d= "F";
        default:
            break;
    }
    os << rhs.title;
    os << " " << d;
    os << " " << rhs.start_time;
    os << " " << rhs.finish_time;
    return os;
}