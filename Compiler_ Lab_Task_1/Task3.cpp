#include <stdio.h>
using namespace std;

int main () {
   FILE *fp;

   fp = fopen("file.txt","w");
   fputs("This is tutorialspoint.com", fp);

   fseek( fp, 0, SEEK_SET );
   fputs("C Programming", fp);
   fclose(fp);

   return(0);
}


