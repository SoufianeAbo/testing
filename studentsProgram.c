#include <stdio.h>
#include <stdbool.h>

FILE *fptr;

// initialize global variables
int num = 0;
int nextId = 0;

// structure for student
struct Student {
    char name[30];
    int age;
    int id;
};

// initialize a max
struct Student student[100] = {};

// save file function
void SaveFile() {
    fptr = fopen("students.txt", "ab");

    // if file doesn't exist(?), idk unsure
    if (fptr == NULL) {
        printf("Invalid file\n");
        mainMenu();
    }

    // save informations to file
    fprintf(fptr, "%s, %d, SIDN: %03d\n", student[num].name, student[num].age, student[num].id);
    fclose(fptr);
}

// load file function
void LoadFile() {
    fptr = fopen("students.txt", "r");

    // if file doesn't exist
    if (fptr == NULL) {
        printf("Invalid file\n");
        mainMenu();
    }

    // loop until it finishes going through students
    while (fscanf(fptr, "%29[^,], %d, SIDN: %d", student[num].name, &student[num].age, &student[num].id) == 3) {
        nextId++;
        num++;
    }

    fclose(fptr);
    mainMenu();
}

void Create() {
    // name
    printf("Input name: \n");
    scanf("%s", &student[num].name);

    // age
    printf("Input age: \n");
    scanf("%d", &student[num].age);

    // id is nextid
    student[num].id = nextId;

    // print creation
    printf("%s has been created with an ID of SIDN %03d\n", student[num].name, student[num].id);
    SaveFile();

    // increment variables
    nextId++;
    num++;
    mainMenu();
}

// print every student function
void Check() {
    // if num is 0 then no student exist yet
    if (num == 0) {
        printf("Empty\n");
        mainMenu();

    } else {

        // loops as long as num is bigger than i
        for (int i = 0; i < num ; i++) {
            printf("%s, %d, SIDN: %03d\n", student[i].name, student[i].age, student[i].id);
        }

        mainMenu();
    }
}

// search function
void Select() {
    // initialize variables
    int search = 0;
    bool found = false;

    // ask for user input
    printf("Enter the ID to search for: \n");
    scanf("%d", &search);

    // loops to keep searching until it finds the variable that is equal to the search
    for (int i = 0; i < num; i++) {
        if (search == student[i].id) {
            found = true;
            printf("\nName: %s\nAge: %d\nID: SIDN%03d\n", student[i].name, student[i].age, student[i].id);
            mainMenu();
        }
    }

    // if found isn't true then prints this
    if (!found) {
        printf("A student with the SIDN%03d does not exist.", search);
        mainMenu();
    }
}

// main menu function
void mainMenu() {
    // initialize variables
    int sel;

    // print menu
    printf("\nSelect:\n1. Create\n2. Select\n3. Check\n4. Save File\n5. Load File\n6. Delete Struct\n7. Exit\n");
    scanf("%d", &sel);

    // condition for menu
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

// main function
int main () {
    mainMenu();
    return 0;
}