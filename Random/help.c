#include <stdio.h>

int main(){
	int size;
	int y;
	char direction;
	char x;
	char word[50];
	printf("Board's size: ");
				    scanf("%d", &size);
				       printf("size: %d \n",size);
				       fflush(stdout);
				       //getchar();
				       printf("Insert the word (ex. C5H program): \n");
				       //scanf("%c%d%c %s",&x,&y,&direction, word);

				       scanf("%c", &x); 
				       scanf("%d", &y); 
				       scanf("%c", &direction); 
				       scanf("%s", word); 
						    printf("The word is %s\n",word);
						        printf("x:%c\n",x);
							    printf("direction:%c\n",direction);
							        printf("y:%d\n",y);

								    return 0;
}
