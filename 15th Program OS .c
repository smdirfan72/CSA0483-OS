#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIRS 10
#define MAX_FILES 10

typedef struct {
    char name[50];
    char content[1000];
} File;

typedef struct {
    char name[50];
    File files[MAX_FILES];
    int file_count;
} Directory;

typedef struct {
    Directory directories[MAX_DIRS];
    int dir_count;
} FileSystem;

void initializeFileSystem(FileSystem *fs) {
    fs->dir_count = 0;
}

void createDirectory(FileSystem *fs, const char *dir_name) {
    if (fs->dir_count < MAX_DIRS) {
        Directory new_dir;
        strcpy(new_dir.name, dir_name);
        new_dir.file_count = 0;
        fs->directories[fs->dir_count] = new_dir;
        fs->dir_count++;
        printf("Directory '%s' created.\n", dir_name);
    } else {
        printf("Cannot create directory: Maximum directory count reached.\n");
    }
}

void createFileInDirectory(Directory *dir, const char *file_name, const char *content) {
    if (dir->file_count < MAX_FILES) {
        File new_file;
        strcpy(new_file.name, file_name);
        strcpy(new_file.content, content);
        dir->files[dir->file_count] = new_file;
        dir->file_count++;
        printf("File '%s' created in directory '%s'.\n", file_name, dir->name);
    } else {
        printf("Cannot create file: Maximum file count reached in directory '%s'.\n", dir->name);
    }
}

void listDirectoryContents(Directory *dir) {
    printf("Contents of Directory '%s':\n", dir->name);
    for (int i = 0; i < dir->file_count; i++) {
        printf("File: %s\n", dir->files[i].name);
    }
    printf("\n");
}

int main() {
    FileSystem fileSystem;
    initializeFileSystem(&fileSystem);

    createDirectory(&fileSystem, "Documents");
    createDirectory(&fileSystem, "Images");

    Directory *documents = &fileSystem.directories[0];
    Directory *images = &fileSystem.directories[1];

    createFileInDirectory(documents, "document1.txt", "This is the content of document1.");
    createFileInDirectory(documents, "document2.txt", "This is the content of document2.");
    createFileInDirectory(images, "image1.jpg", "This is an image file.");

    listDirectoryContents(documents);
    listDirectoryContents(images);

    return 0;
}
