/*
 * adder.c - a minimal CGI program that adds two numbers together
 */
/* $begin adder */
#include "csapp.h"

int main(void) {
    char *buf, *p;
    char arg1[MAXLINE], arg2[MAXLINE], content[MAXLINE];
    int n1=0, n2=0;

    // /* Extract the two arguments */
    // if ((buf = getenv("QUERY_STRING")) != NULL) {
	// p = strchr(buf, '&');
	// *p = '\0';
	// strcpy(arg1, buf);   // arg1에 buf 변수의 문자열을 복사!
	// strcpy(arg2, p+1);
	// n1 = atoi(arg1);
	// n2 = atoi(arg2);
    // }

    /* [11.10-A/B Sol] formadder.html의 input box에서 GET 요청 */
    if ((buf = getenv("QUERY_STRING")) != NULL) {
	p = strchr(buf, '&');
	*p = '\0';
    sscanf(buf, "first=%d", &n1);
    sscanf(p + 1, "second=%d", &n2);
    }

    /* Make the response body */
    sprintf(content, "<b><p> <<<<<<<<< 2nd SW Jungle 2 Jo! >>>>>>>> </b></p>   \r\n");
    sprintf(content, "%sCalculator hahaha \r\n<p>", content);
    sprintf(content, "%s SUM 2 Arguments : %d + %d = %d\r\n<p>", content, n1, n2, n1 + n2);
    sprintf(content, "%s <i>!!!!WOW!!!! IS THIS REAL?? </i> \r\n", content);
  
    /* Generate the HTTP response */
    printf("Connection: close\r\n");
    printf("Content-length: %d\r\n", (int)strlen(content));
    printf("Content-type: text/html\r\n\r\n");
    printf("%s", content);
    fflush(stdout);

    exit(0);
}
/* $end adder */
