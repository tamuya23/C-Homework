//
//  grade.hpp
//  HW-2
//
//  Created by Tangmuyao on 2021/4/7.
//

#ifndef grade_hpp
#define grade_hpp

#include <stdio.h>
#include<iostream>
#include<vector>
#include<cctype>
struct Info{
    std::string name;
    int id;
    double grades;
};
int welcome(void);
void systemName(Info student[]);
void systemJudge(int,Info student[]);
void systemGrades(Info student[]);
void systemCaculate(Info student[]);
void systemRevise(Info student[]);
void systemPrint(Info student[]);
void systemReturn(Info student[]);
void systemOrder(Info student[]);
void systemShow(Info student[]);
int getLenth(Info student[]);


#endif /* grade_hpp */
