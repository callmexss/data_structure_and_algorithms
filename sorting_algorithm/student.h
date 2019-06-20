/*
 * File:          student.h
 * File Created:  Thursday, 20th June 2019 9:38:51 pm
 * Author:        xss (callmexss@126.com)
 * Description:   simple student
 * -----
 * Last Modified: Thursday, 20th June 2019 9:38:56 pm
 * Modified By:   xss (callmexss@126.com)
 * -----
 */

#include <iostream>
#include <string>


struct Student
{
    std::string name;
    int score;

    bool operator<(const Student& otherStudent)
    {
        return score != otherStudent.score ? score < otherStudent.score : name < otherStudent.name;
    }

    friend std::ostream& operator<<(std::ostream& os, const Student& student)
    {
        os << "Student: " << student.name << " " << student.score << std::endl;
        return os;
    }
};