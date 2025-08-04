/* check_python.c — simple check for python3 version, with log */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // Run 'python3 --version' and capture output
    FILE *fp = popen("python3 --version 2>&1", "r");  
    if (!fp) {
        // If popen fails, print error and exit
        fprintf(stderr, "Error: Python 3.x not found\n");
        return 1;
    }

    char buf[128];
    // Read the first line of output from the command
    if (fgets(buf, sizeof(buf), fp)) {
        // Remove trailing newline or carriage return
        buf[strcspn(buf, "\r\n")] = 0;
        // Print detected Python version to stdout
        printf("Detected Python Version: %s\n", buf);
        // Open log file for writing
        FILE *logf = fopen("/tmp/python_ver.log", "w");
        if (logf) {
            // Write Python version to log file
            fprintf(logf, "%s\n", buf);
            fclose(logf);
        }
        // Close the process stream
        pclose(fp);
        return 0;
    }

    // If no output was read, close stream and print error
    pclose(fp);
    fprintf(stderr, "Error: Python 3.x not found\n");
    return 1;
}