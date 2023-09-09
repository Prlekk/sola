#ifndef GRADE_H
#define GRADE_H

class Grade
{
private:
    int gradeID;
    int studentID;
    int subjectID;
    int grade;
public:
    Grade();
    Grade(int i, int stid, int suid, int g);
    ~Grade();
    void setGradeID(int i);
    void setStudentID(int i);
    void setSubjectID(int i);
    void setGrade(int g);
    int getGradeID();
    int getStudentID();
    int getSubjectID();
    int getGrade();
};

#endif