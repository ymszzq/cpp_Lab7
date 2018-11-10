#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include "Course.hpp"

using namespace std;

void printSchedule(vector<Course> course_list) {
    vector<string> course_list_strings{};
    copy(course_list.begin(), course_list.end(), ostream_iterator<Course>(cout,"\n"));
    cout<<"--------------------";
}

int main() {
    vector<Course> course_list;
    ifstream input{"../courses.txt"};
    if (!input.is_open()) {
        cerr << "file not open" << endl;
        exit(1);
    }


    string line,title,day;
    Course::dayOfWeek dayOfWeek;
    unsigned int start, finish;
    while (getline(input, line)) {
        istringstream iss{line};
        iss >> title >> day >> start >> finish;

        if (day == "M")
            dayOfWeek = Course::dayOfWeek::MON;
        if (day == "T")
            dayOfWeek = Course::dayOfWeek::TUE;
        if (day == "W")
            dayOfWeek = Course::dayOfWeek::WED;
        if (day == "F")
            dayOfWeek = Course::dayOfWeek::FRI;
        Course new_course{title, dayOfWeek, start, finish};
        course_list.push_back(new_course);
    }


    sort(course_list.begin(), course_list.end());

    for (auto iterator1 = course_list.begin(); iterator1 != course_list.end(); ++iterator1) {
        for (auto iterator2 = iterator1 + 1; iterator2 != course_list.end(); ++iterator2) {
            if (iterator2->start_time < iterator1->finish_time && iterator1->day == iterator2->day) {
                cout<<"CONFLICT:\n"<<*iterator1<<"\n"<<*iterator2<<endl;
            }
        }
    }

    cout<<"--------------------------\n";

    printSchedule(course_list);
    return 0;
}