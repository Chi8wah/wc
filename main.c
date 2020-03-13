#include <stdio.h>
#include <stdlib.h>

void CountLetter(FILE *fp)
{
    int ltr=0,count=0;
    while(!feof(fp))
    {
        ltr=fgetc(fp);
        if(ltr=='\n') continue;//ʶ��ǻ��з�
        count++;
    }
    count--;//��ȥĩβeof
    printf("��%d�ַ�\n",count);
}

void CountWord(FILE *fp)
{
    int ltr=0,count=0;
    int mk=0;//�жϵ�ǰ״̬��0Ϊ�գ�1Ϊ�ַ���
    while(!feof(fp))
    {
        ltr=fgetc(fp);
        if(ltr=='.') continue;//��ֹ����
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
    printf("��%d��\n",count);
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
    printf("��%d��\n",count);
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
            printf("��ʧ��\n");
            exit(1);
        }
    }
    else
    {
        printf("�������\n");
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
            printf("�������\n");
        }
        printf("���룺q �˳�\t w ��ȡ����\t l ��ȡ����\t c ��ȡ�ַ���\n�����룺");
        fflush(stdin);scanf("%c",&command);
    }
    return 0;
}
