#include <stdio.h>
#include <stdlib.h>

void createFile(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to create the file: %s\n", filename);
    } else {
        printf("File created successfully: %s\n", filename);
        fclose(file);
    }
}

void deleteFile(const char* filename) {
    if (remove(filename) == 0) {
        printf("File deleted successfully: %s\n", filename);
    } else {
        printf("Failed to delete the file: %s\n", filename);
    }
}

void copyFile(const char* source, const char* destination) {
    FILE* sourceFile = fopen(source, "r");
    FILE* destFile = fopen(destination, "w");
    char ch;

    if (sourceFile == NULL) {
        printf("Failed to open the source file: %s\n", source);
        return;
    }

    if (destFile == NULL) {
        printf("Failed to create the destination file: %s\n", destination);
        fclose(sourceFile);
        return;
    }

    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    fclose(sourceFile);
    fclose(destFile);

    printf("File copied successfully from %s to %s\n", source, destination);
}

void moveFile(const char* source, const char* destination) {
    if (rename(source, destination) == 0) {
        printf("File moved successfully from %s to %s\n", source, destination);
    } else {
        printf("Failed to move the file from %s to %s\n", source, destination);
    }
}

int main() {
    int choice;
    char filename[100];
    char sourceFile[100];
    char destFile[100];

    while (1) {
        printf("\nFile Operations:\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. Copy File\n");
        printf("4. Move File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the filename to create: ");
                scanf("%s", filename);
                createFile(filename);
                break;
            case 2:
                printf("Enter the filename to delete: ");
                scanf("%s", filename);
                deleteFile(filename);
                break;
            case 3:
                printf("Enter the source file: ");
                scanf("%s", sourceFile);
                printf("Enter the destination file: ");
                scanf("%s", destFile);
                copyFile(sourceFile, destFile);
                break;
            case 4:
                printf("Enter the source file: ");
                scanf("%s", sourceFile);
                printf("Enter the destination file: ");
                scanf("%s", destFile);
                moveFile(sourceFile, destFile);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}


