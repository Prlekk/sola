#ifndef GRADES_H
#define GRADES_H

class Grades
{
private:
  int id;
  int studentId;
  int subjectId;
  int grade;
public:
    Grades();
    Grades(int i, int student, int subject, int g);
    void setId(int i);
    void setStudentId(int i);
    void setSubjectId(int i);
    void setGrade(int g);

    int getId();
    int getStudentId();
    int getSubjectId();
    int getGrade();
};


#endif