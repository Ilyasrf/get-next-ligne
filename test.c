// #include <fcntl.h>   // For open
// #include <unistd.h>  // For close, read, write

// int main() {
//     // Open a file in read-only mode
//     int fd = open("example.txt", O_RDONLY);
//     if (fd == -1) {
//         // Error handling
//         return 1;
//     }

//     // Read from the file
//     char buffer[100];
//     ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
//     if (bytesRead > 0) {
//         buffer[bytesRead] = '\0'; // Null-terminate the string
//         write(1, buffer, bytesRead); // Write to stdout
//     }

//     // Close the file
//     close(fd);

//     return 0;
// }
