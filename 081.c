#include <stdio.h>

struct Score {
    double math;
    double phys;
};

struct Student {
    int id;
    int math;
    int phys;  
};

void input_data(struct Student *student, int n) {
    for (int i = 0; i < n; i++) {
        int id = i + 100;
        student[i].id = id;
        student[i].math = (29*id + 83) % 100;
        student[i] .phys = (13*id + 58) % 100;
    }
}

void print_data(struct Student *students, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t|%d\t|%d\t|%.1f\n", students[i].id, students[i].math, students[i].phys, (students[i].math + students[i].phys) / 2.);
    }
}

struct Score get_avg(struct Student *student, int n) {
    double math = 0;
    double phys = 0;
    for (int i = 0; i < n; i++) {
        math += student[i].math;
        phys += student[i].phys;
    }
    struct Score avg = {math / n, phys / n};
    return avg;
}

int main() {
    struct Student students[20];

    input_data(students, 20);

    struct Score avg = get_avg(students, 20);

    print_data(students, 20);

    printf("\t|%.1f\t|%.1f\t|%.1f\n", avg.math, avg.phys, (avg.math + avg.phys) / 2.);
}
