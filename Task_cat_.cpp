#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
 
// Driver code
char buf[512];
int ln = 1;
char c;

void cat(int fd)
{
  int n;

  while((n = read(fd, buf, sizeof(buf))) > 0 ) {
  // changing started 	
  	while((n=getc(fd))!=EOF) {
		if (n =='\n'){
            ln++;
        }
    }
 // changing ended
  
  	
    if (write(1, buf, n) != n) {
      fprintf(2, "cat: write error\n");
      exit(1);
    }
  }
  if(n < 0){
    fprintf(2, "cat: read error\n");
    exit(1);
  }
  
}

int main(int argc, char *argv[])
{
  int fd, i;

  if(argc <= 1){
    cat(0);
    exit(0);
  }

  for(i = 1; i < argc; i++){
    if((fd = open(argv[i], 0)) < 0){
      fprintf(2, "cat: cannot open %s\n", argv[i]);
      exit(1);
    }
    cat(fd);
    close(fd);
  }
  exit(0);
}




/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {

    int ln = 1;
    char c;
    FILE *fp = fopen("Hi.txt", "r");

    while((c=getc(fp))!=EOF) {

        if (c=='\n'){
            ln++;
        }
    }
    printf("lines num: %d",c);
    fclose(fp);
    //return 0;
}
*/

// coppied this code from github and used this logic over txt file that i created 
// than put this code into the cat source file
