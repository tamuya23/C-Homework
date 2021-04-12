//
//  grade.cpp
//  HW-2
//
//  Created by Tangmuyao on 2021/4/7.
//

#include "grade.hpp"
using namespace std;
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


int getLenth(Info student[]){
    for (int i = 0 ; i<100;i++){
        if((student[i].name).compare("-1")==0||student[i].id == -1){
        return i;
        }
    }
    return 0;
}
void systemReturn(Info student[]){
    cout<<"Return to the system press 1"<<endl;
    int statement;
    cin>>statement;
    if(statement == 1){
        systemJudge(welcome(),student);
    }
}

void systemShow(Info student[]){
    for(int i = 0; i<getLenth(student);i++){
        cout<<student[i].name<<"\t"<<student[i].id<<"\t"<<student[i].grades<<endl;
    }
}

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
