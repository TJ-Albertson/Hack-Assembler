#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main(int argc, char *argv[])
{
    char *input_filename = argv[1];
    char *output_filename = argv[2];
    char line[MAX_LINE_LENGTH];

    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");

    // Check that input and output files were successfully opened
    if (!input_file)
    {
        printf("Error: could not open input file.\n");
        return 1;
    }
    if (!output_file)
    {
        printf("Error: could not open output file.\n");
        return 1;
    }

    // Define symbol table for labels
    int rom_address = 0;
    int next_variable_address = 16;
    char symbol_table[100][20];
    int symbol_address[100];
    int symbol_count = 0;

    // First pass: build symbol table
    while (fgets(line, MAX_LINE_LENGTH, input_file))
    {
        // Remove whitespace and comments
        char *comment_ptr = strchr(line, '/');
        if (comment_ptr)
        {
            *comment_ptr = '\0';
        }
        char *end_ptr = strchr(line, '\n');
        if (end_ptr)
        {
            *end_ptr = '\0';
        }
        char *start_ptr = line;
        while (*start_ptr == ' ' || *start_ptr == '\t')
        {
            start_ptr++;
        }

        // Check for label definition
        if (*start_ptr == '(')
        {
            char *label_end_ptr = strchr(start_ptr, ')');
            if (label_end_ptr)
            {
                *label_end_ptr = '\0';
            }
            strcpy(symbol_table[symbol_count], start_ptr + 1);
            symbol_address[symbol_count] = rom_address;
            symbol_count++;
        }
        else if (*start_ptr != '\0')
        {
            rom_address++;
        }
    }

    // Second pass: generate machine code
    fseek(input_file, 0, SEEK_SET);
    while (fgets(line, MAX_LINE_LENGTH, input_file))
    {
        // Remove whitespace and comments
        char *comment_ptr = strchr(line, '/');
        if (comment_ptr)
        {
            *comment_ptr = '\0';
        }
        char *end_ptr = strchr(line, '\n');
        if (end_ptr)
        {
            *end_ptr = '\0';
        }
        char *start_ptr = line;
        while (*start_ptr == ' ' || *start_ptr == '\t')
        {
            start_ptr++;
        }

        // Check for A-instruction
        if (*start_ptr == '@')
        {
            char *symbol_ptr = start_ptr + 1;
            int address;
            if (*symbol_ptr >= '0' && *symbol_ptr <= '9')
            {
                address = atoi(symbol_ptr);
            }
            else
            {
                int i;
                for (i = 0; i < symbol_count; i++)
                {
                    if (strcmp(symbol_table[i], symbol_ptr) == 0)
                    {
                        address = symbol_address[i];
                        break;
                    }
                }
                if (i == symbol_count)
                {
                    strcpy(symbol_table[symbol_count], symbol_ptr);
                    symbol_address[symbol_count] = next_variable_address;
                    address = next_variable_address;
                    symbol_count++;
                    next_variable_address++;
                }
            }
            fprintf(output_file, "0%15d\n");
        }

        // Check for C-instruction
        else if (*start_ptr != '\0')
        {
            char dest[4] = "000";
            char comp[8];
            char jump[4] = "000";
            char *dest_ptr = dest;
            char *comp_ptr = comp;
            char *jump_ptr = jump;

            char *equals_ptr = strchr(start_ptr, '=');
            if (equals_ptr)
            {
                strncpy(dest, start_ptr, equals_ptr - start_ptr);
                dest_ptr = dest;
                start_ptr = equals_ptr + 1;
            }
            char *semicolon_ptr = strchr(start_ptr, ';');
            if (semicolon_ptr)
            {
                strncpy(comp, start_ptr, semicolon_ptr - start_ptr);
                comp_ptr = comp;
                start_ptr = semicolon_ptr + 1;
                strncpy(jump, start_ptr, 3);
                jump_ptr = jump;
            }
            else
            {
                strcpy(comp, start_ptr);
                comp_ptr = comp;
            }

            fprintf(output_file, "111%s%s%s\n", comp_ptr, dest_ptr, jump_ptr);
            rom_address++;
        }
    }

    fclose(input_file);
    fclose(output_file);
    return 0;
}