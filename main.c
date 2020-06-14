#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
struct data{
    char dir[20];
    char directory[50];
};
struct data back_path(char directory[],char dir[])
{

    int i;
    int j=0;
    for(i=strlen(directory)-1;i>=0;i--)
    {
        if(directory[i]=='/')
        {
            directory[i]='\0';
            break;
        }
        dir[j]=directory[i];
        j++;
        directory[i]='\0';
    }
    dir[j]='\0';
    strrev(dir);
    struct data d;
    strcpy(d.dir,dir);
    strcpy(d.directory,directory);
    return d;
}

int main()
{
	char str[10];
	printf("是否进入笔记系统？Y/N(请输入正确参数)\n");
	begin:scanf("%s",str);
	if (strcmp(str, "N") == 0){
		printf("再见！\n");
		exit(0);
		return 0;
	}else if (strcmp(str, "Y") == 0){
		char control[10]; //操作
		char name[20]; //文件
		char parameter[10];//参数
		char dir[20] = "notes";
		char directory[1000] = "../notes";
		char p[25];
		FILE *fp = NULL;
		start:system("bash ./tree.sh");
		printf("当前所在目录：%s\n",dir);
printf("%s\n",directory);
		printf("笔记操作参数：增加（create），打开（open），删除（delete），移动（remove)，重命名（rename），取消（exit）\n");
		printf("目录操作参数：创建（create），打开（open），删除（delete），重命名（rename），后退（back），取消（exit）\n");
		printf("选择操作：笔记（n），目录（d），退出（任意输入）\n");
		scanf("%s",control);
		if(strcmp(control, "n") == 0){
			before1:printf("请输入：操作参数 操作对象名（注意中间空格）");
			scanf("%s %s", parameter, name);
			char yy[100];
			strcpy( yy, directory);
			strcat( yy, "/");
			strcat( yy, name);
			if(strcmp(parameter, "create") == 0){
				char a[100] = {'0'};
				sprintf(p,"bash ncreate.sh %s", yy);
				fp = popen(p, "r");
				if (fp == NULL){
					printf("popen error!\n");
					return 1;
				}
				while (fgets(a, sizeof(a), fp) != NULL){
					printf("%s", a);
				}
				pclose(fp);
			}else if(strcmp(parameter, "rename") == 0){
				char b[100] = {'0'};
				char new_name[20];
				char xx[100];
				printf("请输入新名字：");
				scanf("%s",new_name);
				strcpy( xx, directory);
				strcat( xx, "/");
				strcat( xx, new_name);
				sprintf(p,"bash nrename.sh %s %s", yy, xx);
				fp = popen(p, "r");
				if (fp == NULL){
					printf("popen error!\n");
					return 1;
				}
				while (fgets(b, sizeof(b), fp) != NULL){
					printf("%s", b);
				}
				pclose(fp);
			}else if(strcmp(parameter, "open") == 0){
				char c[100] = {'0'};
				sprintf(p,"bash nopen.sh %s", yy);
				fp = popen(p, "r");
				if (fp == NULL){
					printf("popen error!\n");
					return 1;
				}
				while (fgets(c, sizeof(c), fp) != NULL){
					printf("%s", c);
				}
				pclose(fp);
			}else if(strcmp(parameter, "remove") == 0){
				char d[100] = {'0'};
				char new_path[20];
				printf("请输入新path：(../notes/+)");
				scanf("%s",new_path);
				sprintf(p,"bash nrename.sh %s %s", yy, new_path);
				fp = popen(p, "r");
				if (fp == NULL){
					printf("popen error!\n");
					return 1;
				}
				while (fgets(d, sizeof(d), fp) != NULL){
					printf("%s", d);
				}
				pclose(fp);
			}else if(strcmp(parameter, "delete") == 0){
				char e[100] = {'0'};
				sprintf(p,"bash ndelete.sh %s", yy);
				fp = popen(p, "r");
				if (fp == NULL){
					printf("popen error!\n");
					return 1;
				}
				while (fgets(e, sizeof(e), fp) != NULL){
					printf("%s", e);
				}
				pclose(fp);
			}else if(strcmp(parameter, "exit") == 0){
			}else{
				printf("输入参数无效！\n");
				goto before1;
			}
			goto start;
		}else if(strcmp(control, "d") == 0){
			before2:printf("请输入：操作参数 操作对象名（注意中间空格）");
			scanf("%s %s", parameter, name);
			char yy[100];
			strcpy( yy, directory);
			strcat( yy, "/");
			strcat( yy, name);
			if(strcmp(parameter, "create") == 0){
				char f[100] = {'0'};
				sprintf(p,"bash dcreate.sh %s", yy);
				fp = popen(p, "r");
				if (fp == NULL){
					printf("popen error!\n");
					return 1;
				}
				while (fgets(f, sizeof(f), fp) != NULL){
					printf("%s", f);
				}
				pclose(fp);
			}else if(strcmp(parameter, "rename") == 0){
				char g[100] = {'0'};
				char new_name[20];
				char xx[100];
				printf("请输入新名字：");
				scanf("%s",new_name);
				strcpy( xx, directory);
				strcat( xx, "/");
				strcat( xx, new_name);
				sprintf(p,"bash drename.sh %s %s", yy, xx);
				fp = popen(p, "r");
				if (fp == NULL){
					printf("popen error!\n");
					return 1;
				}
				while (fgets(g, sizeof(g), fp) != NULL){
					printf("%s", g);
				}
				pclose(fp);
			}else if(strcmp(parameter, "open") == 0){
				char i[100] = {'0'};
				int T = 0;
				sprintf(p,"bash dopen.sh %s", yy);
				fp = popen(p, "r");
				if (fp == NULL){
					printf("popen error!\n");
					return 1;
				}
				while (fgets(i, sizeof(i), fp) != NULL){
					printf("%s", i);
				}
				T=atoi(i);
				if(T == 0){
					printf("未找到相关目录，请检查重新输入  ");
				}else if(T == 1){
					strcpy( dir, name);
					strcat( directory, "/");
					strcat( directory, name);
				}
				pclose(fp);
			}else if(strcmp(parameter, "back") == 0){
				if(strcmp(directory, "../notes") == 0){
					printf("已到根目录，不能再后退   ");
				}else{
					char aa[100];
					char bb[20];
					strcpy( aa, directory);
					struct data m=back_path(aa,bb);
					strcpy( directory, m.directory);
					strcpy( aa, directory);
					struct data n=back_path(aa,bb);
					strcpy( dir, n.dir);
				}
			}else if(strcmp(parameter, "delete") == 0){
				char h[100] = {'0'};
				sprintf(p,"bash ddelete.sh %s", yy);
				fp = popen(p, "r");
				if (fp == NULL){
					printf("popen error!\n");
					return 1;
				}
				while (fgets(h, sizeof(h), fp) != NULL){
					printf("%s", h);
				}
				pclose(fp);
			}else if(strcmp(parameter, "exit") == 0){
			}else{
				printf("输入参数无效！\n");
				goto before2;
			}
			goto start;
		}else{
			printf("再见！\n");
			exit(0);
			return 0;
		}
	}else{
		goto begin;
	}
}
