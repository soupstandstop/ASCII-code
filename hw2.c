// count_letter.c: Count uppercase letters in a file. */
// compile: gcc -o count_letters count_letter.c
// run: count_letters chapterl data1
//作業2
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
   int c, i, letter[127], a;
   FILE *ifp, *ofp;
   if (argc!= 3) {
       printf("\n%s%s%s\n\n%s\n%s\n\n",
                  "Usage: ", argv[0] , " infile outfile",
                  "The uppercase letters in infile will be counted.",
                  "The results will be written in outfile.");
      exit(1) ;
  }
   ifp = fopen(argv[1] , "r");//在compiler給argv[1]一個名字例如：input1.txt，input1.txt就會被讀入
   ofp = fopen(argv[2] , "w");//在compiler給argv[2]一個名字例如：output1.txt，答案會寫進output1.txt
   a=0;
   for (i=0; i <= 127; ++i) letter[i] = 0;//將letter[0]~letter[126]均設為0

   while ((c=getc(ifp))!= EOF)//getc()為讀入一字元的function、EOF = end of file
       if (c >= 0 && c <= 127) ++letter[c];//新讀取的字元不管是什麼都令為c，若c位於null到~之間，letter[c]就要加一

   a = letter[9] + letter[10] + letter[32] ;

   fprintf(ofp, "%d\n", a);
   for (i=0; i <= 127; ++i) {
      putc('\t', ofp);
      fprintf(ofp, "%d", letter[i]);
   }
   putc('\n', ofp);
   return 0;
}

