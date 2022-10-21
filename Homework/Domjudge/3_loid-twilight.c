#include <stdio.h>

typedef struct {
    int id;
    char name[100];
    int severity;
}patient;

void input(patient *p) {
    scanf("%d", &p->id);
    scanf("%s", p->name);
    scanf("%d", &p->severity);
}

void sort_id(patient *p, int n) {
    int i, j;
    patient temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].id > p[j].id) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

patient *critical(patient *p, int n) {
    int maxseverity = 0; int maxid = 0; int i;
    for (i = 0; i < n; i++) {
        if (p[i].severity > maxseverity) {
            maxseverity = p[i].severity;
            maxid = p[i].id;
        }
    }
    for (i = 0; i < n; i++) {
        if (p[i].severity == maxseverity) {
            if (p[i].id < maxid) {
                maxid = p[i].id;
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (p[i].id == maxid) {
            return &p[i];
        }
    }
}

void outputAll(patient *p) {
    printf("  %02d %-10s %d\n", p->id, p->name, p->severity);
}

void outputCritical(patient *p) {
    printf("  %02d %-10s %d\n", p->id, p->name, p->severity);
}

float average(patient *p, int n) {
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += p[i].severity;
    }
    float avg = sum / n;
    float tmp_avg = avg;
    tmp_avg *= 100;
    int tmp = (int)tmp_avg%10;
    if (tmp != 0) {
        avg += 0.1;
        return avg;
    }
    return avg;
}

int main(void) {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("Nothing to show");
        return 0;
    }
    else if (n < 0) {
        printf("ErRor.!");
        return 0;
    }
    patient patients[n];
    for (int i = 0; i < n; i++) {
        input(&patients[i]);
    }
    sort_id(patients, n);
    printf("All patient:\n");
    for (int i = 0; i < n; i++) {
        outputAll(&patients[i]);
    }
    patient *c = critical(patients, n);
    int i = c->id;
    printf("Critical:\n");
    for (int i = 0; i < n; i++) {
        if (patients[i].severity == c->severity) {
            outputCritical(&patients[i]);
        }
    }
    printf("Average: %.1f\n", average(patients, n));
    
    return 0;
}