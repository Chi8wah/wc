#include <stdio.h>
#include <stdlib.h>

void CountLetter(FILE *fp)
{
    int ltr=0,count=0;
    while(!feof(fp))
    {
        ltr=fgetc(fp);
        if(ltr=='\n') continue;//识别非换行符
        count++;
    }
    count--;//减去末尾eof
    printf("共%d字符\n",count);
}

void CountWord(FILE *fp)
{
    int ltr=0,count=0;
    int mk=0;//判断当前状态：0为空，1为字符串
    while(!feof(fp))
    {
        ltr=fgetc(fp);
        if(ltr=='.') continue;//防止误判
        if((ltr>='a'&&ltr<='z')||(ltr>='A'&&ltr<='Z')||ltr=='_')
        {
            if(mk==0) mk=1;
        }
        else
        {
            if(mk==1)
            {
                count++;
                mk=0;
            }
            else continue;
        }
    }
    printf("共%d词\n",count);
}

void CountLine(FILE *fp)
{
    int ltr=0,count=0;
    while(!feof(fp))
    {
        ltr=fgetc(fp);
        if(ltr=='\n')
            count++;
    }
    printf("共%d行\n",count);
}

int main(int argc, char* argv[])
{
    char command;
    FILE* fp=NULL;
    char* fun=(char*)malloc(sizeof(char)*50);
    if(argv[2]!=NULL&&argv[1]!=NULL)
    {
        fp=fopen(argv[2],"r");
        fun=argv[1];
        command=fun[1];
        if(fp==NULL)
        {
            printf("打开失败\n");
            exit(1);
        }
    }
    else
    {
        printf("输入错误\n");
        return 0;
    }
    while(1)
    {
        switch(command)
        {
        case 'c':
            CountLetter(fp);
            rewind(fp);
            break;
        case 'w':
            CountWord(fp);
            rewind(fp);
            break;
        case 'l':
            CountLine(fp);
            rewind(fp);
            break;
        case 'q':
            fclose(fp);
            free(fun);
            exit(0);
        default:
            printf("输入错误\n");
        }
        printf("输入：q 退出\t w 获取词数\t l 获取行数\t c 获取字符数\n请输入：");
        fflush(stdin);scanf("%c",&command);
    }
    return 0;
}
