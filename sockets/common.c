#include "common.h"

void error_handling(const char *fmt, ...) {
  int errno_save;
  va_list ap;

  // any system or library call can set errno, so we save it
  errno_save = errno;

  // print error fmt+args to standard out
  va_start(ap, fmt);
  vfprintf(stdout, fmt, ap);
  fprintf(stdout, "\n");
  fflush(stdout);

  // print out error message if errno was set
  if (errno_save != 0) {
    fprintf(stdout, "(errno = %d) : %s\n", errno_save, strerror(errno_save));
    fprintf(stdout, "\n");
    fflush(stdout);
  }
  va_end(ap);

  // terminate with an error
  exit(1);
}

char *bin2hex(const unsigned char *src, size_t len) {
  char *result;
  char *hexits = "0123456789ABCDEF";

  if (src == NULL || len <= 0) {
    return NULL;
  }

  int resultLength = len * 3 + 1;
  result = (char *)malloc(resultLength);
  memset(result, 0, resultLength);

  for (int i = 0; i < len; i++) {
    result[i * 3] = hexits[src[i] >> 4];
    result[i * 3 + 1] = hexits[src[i] & 0x0F];
    result[i * 3 + 2] = ' '; // for readability
  }

  return result;
}