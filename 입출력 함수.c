putchar, fputc : 하나의 문잧 출력
fputc: 스트림 지정 가능 
fputc(int c, stdout)


int ch1;
getchar fgetc : 하나의 문자를 입력 받을 때
ch1=fgetc(stdin)



puts, fputs
printf("%d")   자동개행X
puts: 자동개행
fputs: 자동개행 X


gets, fgets: 문자열 입력 함수
str1[30]=0;
fgets(str1,sizeof(str1),stdin);
str1[strlen(str1)-1]=0;



FILE* fp = fopen("simple.txt", "wt");

fputc('A', fp) //fp 파일 안에 A라는 단어 추가함.
fputs("asdf", fp)   //fp 파일 안에 asdf 문자열 추가함.

for(i=0;i<100;i++){
printf("%c",fgetc(fp));}        //fp 파일 안에 있는 글자를 하나씩 읽어와서 콘솔 창에 출력함.