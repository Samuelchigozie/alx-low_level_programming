#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void print_magic(unsigned char *e_ident);
void print_class(unsigned char e_ident[EI_CLASS]);
void print_data(unsigned char e_ident[EI_DATA]);
void print_version(unsigned char e_ident[EI_VERSION]);
void print_osabi(unsigned char e_ident[EI_OSABI]);
void print_entry(unsigned long long e_entry, unsigned char *e_ident);

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ELF binary>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    Elf64_Ehdr header;
    if (read(fd, &header, sizeof(header)) != sizeof(header)) {
        fprintf(stderr, "Failed to read ELF header\n");
        exit(EXIT_FAILURE);
    }

    print_magic(header.e_ident);
    print_class(header.e_ident);
    print_data(header.e_ident);
    print_version(header.e_ident);
    print_osabi(header.e_ident);
    print_entry(header.e_entry, header.e_ident);

    close(fd);
    return 0;
}

void print_magic(unsigned char *e_ident) {
    printf("ELF magic: ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", e_ident[i]);
    }
    printf("\n");
}

void print_class(unsigned char e_ident[EI_CLASS]) {
    printf("ELF class: ");
    switch (e_ident[EI_CLASS]) {
        case ELFCLASSNONE:
            printf("none\n");
            break;
        case ELFCLASS32:
            printf("32-bit\n");
            break;
        case ELFCLASS64:
            printf("64-bit\n");
            break;
        default:
            printf("Invalid class\n");
            break;
    }
}

void print_data(unsigned char e_ident[EI_DATA]) {
    printf("ELF data: ");
    switch (e_ident[EI_DATA]) {
        case ELFDATANONE:
            printf("none\n");
            break;
        case ELFDATA2LSB:
            printf("little-endian\n");
            break;
        case ELFDATA2MSB:
            printf("big-endian\n");
            break;
        default:
            printf("Invalid data encoding\n");
            break;
    }
}

void print_version(unsigned char e_ident[EI_VERSION]) {
    printf("ELF version: ");
    if (e_ident[EI_VERSION] != EV_CURRENT) {
        printf("Invalid version\n");
    } else {
        printf("%d (current)\n", e_ident[EI_VERSION]);
    }
}

void print_osabi(unsigned char e_ident[EI_OSABI]) {
    printf("ELF OS/ABI: ");
    switch (e_ident[EI_OSABI]) {
        case ELFOSABI_NONE:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_HPUX:
            printf("UNIX - HP-UX\n");
            break;
        case ELFOSABI_NETBSD:
            printf("UNIX - NetBSD\n");
            break;
        case ELFOSABI_LINUX:
            printf("UNIX - Linux\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("UNIX - Solaris\n");
            break;
        case ELFOSABI_AIX:
            printf("UNIX - AIX\n");
            break;
        case ELFOSABI_IRIX:
            printf("UNIX - IRIX\n
