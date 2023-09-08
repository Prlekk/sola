#include "Student.h"
#include "Subject.h"

int main()
{
    std::vector<Student> students = generateStudent();
    Subject nrpa(1, "NRPA", "Zak Drofenik");
    Subject nupb(2, "NUPB", "Zoltan Sep");

    for(int i = 0; i < students.size(); i++) {
        nrpa.addStudent(students[i]);
        nupb.addStudent(students[i]);
    }
    for(auto i : students) {
        nrpa.addGradeToStudent(rand()% 5 + 1, i.getId());
        nrpa.addGradeToStudent(rand()% 5 + 1, i.getId());
        nrpa.addGradeToStudent(rand()% 5 + 1, i.getId());
        nrpa.addGradeToStudent(rand()% 5 + 1, i.getId());
        nrpa.addGradeToStudent(rand()% 5 + 1, i.getId());
        nrpa.addGradeToStudent(rand()% 5 + 1, i.getId());
    }
    nrpa.allStudents();
}