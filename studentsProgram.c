#include <stdio.h>
#include <stdbool.h>

FILE *fptr;

int num = 0;
int nextId = 0;

struct Student {
    char name[30];
    int age;
    int id;
};

struct Student student[100] = {};

void SaveFile() {
    fptr = fopen("students.txt", "ab");

    if (fptr == NULL) {
        printf("Invalid file\n");
        mainMenu();
    }

    fprintf(fptr, "%s, %d, SIDN: %03d\n", student[num].name, student[num].age, student[num].id);
    fclose(fptr);
}

void LoadFile() {
    fptr = fopen("students.txt", "r");

    if (fptr == NULL) {
        printf("Invalid file\n");
        mainMenu();
    }

    while (fscanf(fptr, "%29[^,], %d, SIDN: %d", student[num].name, &student[num].age, &student[num].id) == 3) {
        nextId++;
        num++;
    }

    fclose(fptr);
    mainMenu();
}

void Create() {
    printf("Input name: \n");
    scanf("%s", &student[num].name);

    printf("Input age: \n");
    scanf("%d", &student[num].age);

    student[num].id = nextId;

    printf("%s has been created with an ID of SIDN %03d", student[num].name, student[num].id);
    SaveFile();


    nextId++;
    num++;
    mainMenu();
}

void Check() {
    if (num == 0) {
        printf("Empty\n");
        mainMenu();
    } else {
        for (int i = 0; i < num ; i++) {
            printf("%s, %d, SIDN: %03d\n", student[i].name, student[i].age, student[i].id);
        }
        mainMenu();
    }
}

void Select() {
    int search = 0;
    bool found = false;

    printf("Enter the ID to search for: \n");
    scanf("%d", &search);

    for (int i = 0; i < num; i++) {
        if (search == student[i].id) {
            found = true;
            printf("\nName: %s\nAge: %d\nID: SIDN%03d\n", student[i].name, student[i].age, student[i].id);
            mainMenu();
        }
    }

    if (!found) {
        printf("A student with the SIDN%03d does not exist.", search);
        mainMenu();
    }
}

void mainMenu() {
    int sel;

    printf("\nSelect:\n1. Create\n2. Select\n3. Check\n4. Save File\n5. Load File\n6. Delete Struct\n7. Exit\n");
    scanf("%d", &sel);

    switch (sel) {
        case 1:
            Create();
            break;
        case 2:
            Select();
            break;
        case 3:
            Check();
            break;
        case 4:
            LoadFile();
            break;
        case 5:
            remove("students.txt");
            break;
        case 6:
            return 0;
        default:
            printf("Invalid option, try again.");
            break;
    }
}

int main () {
    mainMenu();
    return 0;
}