#题目描述
编写学生信息管理系统。每个学生的信息包括:学号、姓名(拼音方式给出)、成绩。管理系统的功能  
包括:  
录入。可在控制台输入所有学生姓名、学号以及成绩信息。 修改。可修改指定姓名或学号学生信息。  
插入。可增加新的学生信息。  
删除。可删除指定姓名或学号学生信息。  
排序。可根据学生成绩或者姓名进行排序并显示结果。 统计。可统计指定姓的同学人数，如输入“wang”,输出该姓学生数。可统计学生成绩如平均成绩、总 成绩、最高最低成绩  
<br><br>
#思路
*两大问题*  
1.如何让用户终止输入名单，或者终止各种操作。  
2.如何在不使用计数器的情况下进行数组长度的统计和计算。  
<br><br>
*两大解决办法*  
采取-1作为特征值，当用户输入-1时强行结束程序回到主界面。  
编写了getlength函数，配合上面的-1进行数组长度的获取。
<br><br>


```cpp
//-------------------grade.hpp-------------------//
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



//--------------------grade.cpp--------------------//


#include "grade.hpp"
using namespace std;
//欢迎系统
int welcome(void){
        cout<<"Welcome to the grades system"<<endl;
        cout<<"To enter the namelist    press 1"<<endl;
        cout<<"To enter the grade       press 2"<<endl;
        cout<<"To order the list        press 3"<<endl;
        cout<<"To revise the grades     press 4"<<endl;
        cout<<"To calculate the grades press 5"<<endl;
        cout<<"To print the result      press 6"<<endl;
        cout<<"To close the system      press -1"<<endl;
        int statement;
        cin>>statement;
        return statement;
}
//名单修改系统
void systemName(Info student[]){
    cout<<"Enter the namelist press 1 "<<endl<<"Add the namelist press 2"<<endl<<"Delete the namelist press 3"<<endl;
    int statement,length=0;
    cin>>statement;
    if(statement == 1){
        cout<<"Please enter the name and id"<<endl<<"When the number is finished press -1"<<endl<<"name"<<"\t"<<"\t"<<"id number"<<endl;
        for(int i =0; i<100; i++){
            cin>>student[i].name;
            if((student[i].name).compare("-1")==0){
                cout<<"The enter has finished"<<endl;
                length = i;
                student[i].name = " ";
                student[i].id = -1;
                break;
            }
            cin>>student[i].id;
            if(student[i].id == -1 ){
                cout<<"The enter has finished"<<endl;
                length = i;
                i = 100;
                continue;
            }
        }
        cout<<endl<<"Please check"<<endl;
        for(int i = 0;i<length;i++){
            cout<<student[i].name<<"\t"<<student[i].id<<endl;
        }
        cout<<"In all "<<getLenth(student)<<" "<<" pieces of namelist"<<endl;
    }
    if(statement == 2){
        cout<<"Please enter the name and id you want to add"<<endl;
        cout<<"When finished press -1"<<endl;
        cout<<"name"<<"\t"<<"\t"<<"id"<<endl;
        for(int i =getLenth(student); i<100; i++){
            cin>>student[i].name;
            if((student[i].name).compare("-1")==0){
                cout<<"The enter has finished"<<endl;
                length = i;
                student[i].name = " ";
                student[i].id = -1;
                break;
            }
            cin>>student[i].id;
            if(student[i].id == -1 ){
                cout<<"The enter has finished"<<endl;
                length = i;
                break;
            }
        }
        cout<<endl<<"Please check"<<endl;
        systemShow(student);
        cout<<"In all"<<" "<<getLenth(student)<<" pieces of namelist"<<endl;
    }
    if(statement == 3){
        cout<<"Please enter the name and id you want to delete"<<endl;
        cout<<"name search press 1， id search press 2 "<<endl;
        cin>>statement;
        if(statement==1){
            cout<<"Please enter the name"<<endl;
            string name;
            cin>>name;
            for(int i = 0; i <getLenth(student);i++){
                if(name.compare(student[i].name)==0){
                    for(int j = i;j<getLenth(student);j++){
                        student[j]=student[j+1];
                    }
                }
            }
            cout<<endl<<"Please check"<<endl;
            systemShow(student);
            cout<<"In all "<<getLenth(student)<<" pieces of namelist"<<endl;
        }
        if(statement==2){
            cout<<"Please enter the id number"<<endl;
            int id;
            cin>>id;
            for(int i = 0; i <getLenth(student);i++){
                if(id == student[i].id){
                    for(int j = i;j<getLenth(student);j++){
                        student[j]=student[j+1];
                    }
                }
            }
            cout<<endl<<"Please check"<<endl;
            systemShow(student);
            cout<<"In all "<<getLenth(student)<<"pieces of namelist"<<endl;
        }
    }
    systemReturn(student);
}
//成绩输入系统
void systemGrades(Info student[]){
    cout<<"PLease enter the subject name"<<endl;
    string subject;
    cin>>subject;
    cout<<"Please enter everyone's grades"<<endl<<"When the number is finished press -1"<<endl;
    for(int i = 0; i<getLenth(student);i++){
        cout<<student[i].name<<"\t"<<student[i].id<<"\t";
        cin>>student[i].grades;
        if(student[i].grades == -1){
            student[i].grades = 0;
            i = getLenth(student);
            break;
        }
    }
    cout<<endl<<"name"<<"\t"<<"id"<<"\t"<<subject<<endl;
    systemShow(student);
    systemReturn(student);
}
//排序系统
void systemOrder(Info student[]){
    cout<<"Ordered by grades press 1，Ordered by id number press 2，Ordered by name press 3"<<endl;
    int statement;
    cin>>statement;
    if (statement == 1){
        for(int i = 0; i<getLenth(student);i++){
            for(int j = 0;j<getLenth(student);j++){
                if(student[i].grades>student[j].grades){
                    Info temp;
                    temp = student[i];
                    student[i]=student[j];
                    student[j]= temp;
                }
            }
        }
        systemShow(student);
    }
    if (statement == 2){
        for(int i = 0; i<getLenth(student);i++){
            for(int j = 0;j<getLenth(student);j++){
                if(student[i].id<student[j].id){
                    Info temp;
                    temp = student[i];
                    student[i]=student[j];
                    student[j]= temp;
                }
            }
        }
        systemShow(student);
    }
    if (statement == 3){
        for(int i = 0; i<getLenth(student);i++){
            for(int j = 0;j<getLenth(student);j++){
                if(student[i].name.compare(student[j].name)<0){
                    Info temp;
                    temp = student[i];
                    student[i]=student[j];
                    student[j]= temp;
                }
            }
        }
        systemShow(student);
    }

    systemReturn(student);
}
//修改分数系统
void systemRevise(Info student[]){
    cout<<"PLease enter the information you want to change"<<endl;
    cout<<"name search press 1， id search press 2"<<endl;
    int statement;
    cin>>statement;
    if(statement == 1){
        string name;
        cout<<"Please enter the name"<<endl;
        cin>>name;
        for (int i = 0; i<getLenth(student);i++){
                if(name.compare(student[i].name)==0){
                    cout<<student[i].name<<"\t"<<student[i].id<<"\t"<<student[i].grades<<endl;
                    cout<<"The changed result is :"<<endl;
                    cin>>student[i].grades;
                    cout<<"Successfully changed"<<endl;
                    i = getLenth(student);
                    continue;
            }
        }
    }
    if(statement == 2){
        int id;
        cout<<"Please enter the id number"<<endl;
        cin>>id;
        for (int i = 0; i<getLenth(student);i++){
                if(id==student[i].id){
                    cout<<student[i].name<<"\t"<<student[i].id<<"\t"<<student[i].grades<<endl;
                    cout<<"The changed grades is:"<<endl;
                    cin>>student[i].grades;
                    cout<<"Successfully changed"<<endl;
                    i = getLenth(student);
                    continue;
            }
        }
    }
    systemReturn(student);
}
//成绩单打印系统
void systemPrint(Info student[]){
    cout<<"The total paper press 1，Query certain people press 2"<<endl;
    int statement;
    cin>>statement;
    if(statement == 1){
        cout<<"\t"<<"The total paper"<<endl;
        systemShow(student);
        cout<<"Return to the system press 1"<<endl;
        cin>>statement;
        if(statement == 1){
            systemJudge(welcome(),student);
        }
    }
    if(statement ==2){
        cout<<"name search press 1， id search press 2"<<endl;
        cin>>statement;
        if(statement == 1){
            string name;
            cout<<"Please enter the name"<<endl;
            cin>>name;
            for (int i = 0; i<getLenth(student);i++){
                if(name.compare(student[i].name)==0){
                    cout<<student[i].name<<"\t"<<student[i].id<<"\t"<<student[i].grades<<endl;
                    break;
                }
            }
            systemReturn(student);
        }
        if(statement == 2){
            int id;
            cout<<"Please enter the id number"<<endl;
            cin>>id;
            for (int i = 0; i<getLenth(student);i++){
                if(id==student[i].id){
                    cout<<student[i].name<<"\t"<<student[i].id<<"\t"<<student[i].grades<<endl;
                    break;
                }
            }
            systemReturn(student);
        }
    }
}
//统计系统
void systemCaculate(Info student[]){
    cout<<"Enter the name you want to calculate"<<endl;
    string nameFirst;
    cin>>nameFirst;
    int count=0;
    int number = 0;
    Info selectStudent[100];
    for(int i = 0; i<getLenth(student);i++){
        for(int j = 0; j<nameFirst.length();j++){
            if(student[i].name[j]==nameFirst[j]){
            count++;}
            }
            if(count == nameFirst.length()){
                selectStudent[number] = student[i];
                cout<<selectStudent[number].name<<"\t"<<selectStudent[number].id<<"\t"<<selectStudent[number].grades<<endl;
                number++;
            }
        count = 0;
    }
    cout<<"In all "<<number<<" students"<<endl;
    cout<<"The average score of these students:";
    int sum=0;
    for(int i = 0;i<number;i++){
        sum+=selectStudent[i].grades;

    }
    cout<<sum/number<<endl;
    cout<<"The highest score among these students is:";
    int highest=0;
    for(int i = 0;i<number;i++){
        if(highest < selectStudent[i].grades){
            highest = selectStudent[i].grades;
        }
    }
    cout<<highest<<endl;
    systemReturn(student);
}

//获取数组长度
int getLenth(Info student[]){
    for (int i = 0 ; i<100;i++){
        if((student[i].name).compare("-1")==0||student[i].id == -1){
        return i;
        }
    }
    return 0;
}
//返回主界面系统
void systemReturn(Info student[]){
    cout<<"Return to the system press 1"<<endl;
    int statement;
    cin>>statement;
    if(statement == 1){
        systemJudge(welcome(),student);
    }
}
//展示系统
void systemShow(Info student[]){
    for(int i = 0; i<getLenth(student);i++){
        cout<<student[i].name<<"\t"<<student[i].id<<"\t"<<student[i].grades<<endl;
    }
}
//主界面系统
void systemJudge(int a,Info student[]){
        switch (a){
        case -1:cout<<"Welcome for next use"<<endl;break;
        case 1 :systemName(student);break;
        case 2 :systemGrades(student);break;
        case 3 :systemOrder(student);break;
        case 4 :systemRevise(student);break;
        case 5 :systemCaculate(student);break;
        case 6 :systemPrint(student);break;
    }
}
//-------------------------main.cpp-----------------------//

#include "grade.hpp"
using namespace std;

int main (){
    Info student[100]={"",0,0};
    systemJudge(welcome(),student);
}


```
#**主界面** 
![avatar](/Users/tangmuyao/Desktop/code/HW-2/HW-2/P1.png)  
<br><br>
#**名单录入**
![avatar](/Users/tangmuyao/Desktop/code/HW-2/HW-2/P2.png)  
<br><br>
#**名单增加**
![avatar](/Users/tangmuyao/Desktop/code/HW-2/HW-2/P3.png)  
<br><br>
#**名单删除**
![avatar](/Users/tangmuyao/Desktop/code/HW-2/HW-2/P4.png)  
<br><br>
#**分数录入**
![avatar](/Users/tangmuyao/Desktop/code/HW-2/HW-2/P5.png)  
<br><br>
*不一一枚举，能实现所有功能。测试成功。*
<br><br>

#困惑
*当要输入多组成绩，在不改变结构体的情况下该如何解决。*  

#总结
*当使用的函数名非常统一时，代码的可读性大大增加*


