#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<openssl/md5.h>
#include<stdlib.h>
#include<time.h>
char ps[30],passwd[30];
int fcnt,flag=0,f=0;
char folderpath[5000],folderpath1[5000];
int i,count=0,cnt=0,k=0;
void print_md5_sum(unsigned char*);
void print();
void update(int);
void monitor();
void createstruct(char *);
unsigned char *calhash(char *);
void verifynupdate(int,int);
unsigned char result[30];
struct tm *tmp;
struct timespec *ts;
struct fileprop {
	char name[30];
	ino_t inode;
	unsigned char hash[20];
	char path[500];
	int hour;
	int  min;
	int sec;
	int day;
	int mday1;
	int mon1;
	int year1;
};
struct fileprop *fp,*fp3,*fp0;
void fillfp(struct stat *fa,struct dirent *ent,char *path)
{	
	tmp=localtime(&fa->st_mtime);
	strcpy((fp+cnt)->name,ent->d_name);
	(fp+cnt)->inode=fa->st_ino;
	strcpy((fp+cnt)->path,path);
	strcpy((char *)(fp+cnt)->hash,(char *)calhash(path));

	(fp+cnt)->hour=tmp->tm_hour;
	(fp+cnt)->min=tmp->tm_min;
	(fp+cnt)->sec=tmp->tm_sec;
	(fp+cnt)->mday1=tmp->tm_mday;
	(fp+cnt)->mon1=tmp->tm_mon+1;
	(fp+cnt)->year1=(2000+(tmp->tm_year%100));
	return;
}


void fc(char *drf){
	DIR *dir;
	struct dirent *ent;
	struct stat fa;
	char path[5000];
	if((dir=opendir(drf))==NULL)
		return;
	while((ent=readdir(dir))!=NULL)
	{
		if(!strcmp(ent->d_name,".."))
		continue;
		if(!strcmp(ent->d_name,"."))
		continue;
		strcpy(path,drf);
		strcat(path,"/");
		strcat(path,ent->d_name);
		lstat(path,&fa);
		if(S_ISDIR(fa.st_mode)){		
			fc(path);
		}
		else{
			memset(&fa,'\0',sizeof(fa));
			lstat(path,&fa);
			if(f==1)
				fillfp(&fa,ent,path);
			cnt++;
	
		}
		memset(path,'\0',sizeof(path));	
	}
	return;
	
}

void print_md5_sum(unsigned char* md) {
	int i;
	for(i=0; i <MD5_DIGEST_LENGTH; i++) {
            printf("%d ",md[i]);
	
    }
    return;
}

unsigned long get_size_by_fd(int fd) {
	struct stat statbuf;
	if(fstat(fd, &statbuf) < 0);
	return statbuf.st_size;
}

unsigned char * calhash(char *path) {
	int file_descript;
	unsigned long file_size;
	char* file_buffer;

	file_descript = open(path, O_RDONLY);
	if(file_descript < 0);
	file_size = get_size_by_fd(file_descript);

	file_buffer = mmap(0, file_size, PROT_READ, MAP_SHARED, file_descript, 0);
	MD5((unsigned char*) file_buffer, file_size, result);
	munmap(file_buffer, file_size);


	return result;
}

int main()
{	
	FILE *fp2,*fp4,*fp5,*fp8;
	char a,yn;
	int size;
	fp4=fopen("sign.log","r");
	fseek(fp4,0,SEEK_END);
	size=ftell(fp4);

	if(size==0){
		fclose(fp4);
		printf("Please enter the New password:\n");
		scanf("%s",passwd);
		fp5=fopen("password.log","w");
		fwrite(passwd,sizeof(passwd),1,fp5);
		X:

		printf("Enter the folder or directory to monitor\n");
		scanf("%s",folderpath);
		createstruct(folderpath);
		if(count==0){
			printf("INVALID DIRECTORY (OR) DIRECTORY DOESN'T CONTAIN ANY FILES\n");
			return -1;
		}
		fp8=fopen("folder.log","w");
		fwrite(folderpath,sizeof(folderpath),1,fp8);
		fp4=fopen("sign.log","w");
		a='i';
		fwrite(&a,sizeof(char),1,fp4);
		fc(folderpath); 
		fp2=fopen("db.log","w");
		fwrite(fp,sizeof(struct fileprop),count,fp2);
		printf("Intial database created\n");
		fclose(fp2);
		fclose(fp4);
		return 0;
	}


	fclose(fp4);
	fp8=fopen("folder.log","r");
	fread(folderpath,sizeof(folderpath),1,fp8);
	fclose(fp8);
	printf("The current folder/directory that is being monitored is %s \nWould you like the change the directory/folder that to be monitored(y/n)?\n",folderpath);
	scanf(" %c",&yn);
	if(yn=='y')
		goto X;
	else
	{
		strcpy(folderpath1,folderpath);
		createstruct(folderpath);
		monitor();
		printf("\n");
	}
	return 0;
}
void verifynupdate(int index,int jind)
{
	char yn;
	printf("__________*****__________\nFile:%s\nPath:%s\n",fp[index].name,fp[index].path);
	printf("Is this file modified by you (y/n):\n");
	scanf(" %c",&yn);	
	printf("enter password\n");
	scanf(" %s",ps);
	printf("__________*****__________\n");
	if(!strcmp(passwd,ps)&&yn=='y')
	{
		return ;
	}
	else if(!strcmp(passwd,ps)&&yn=='n'){
		printf("ALERT!!!!!!!!  FILES GOT MODIFIED BY MALICIOUS PROGRAM/UNKONWN USER\n");
	}
	else
	{
		strcpy(fp[index].name,fp3[jind].name);
		fp[index].inode=fp3[jind].inode;
		strcpy((char *)fp[index].hash,(char *)fp3[jind].hash);
		strcpy(fp[index].path,fp3[jind].path);
		fp[index].hour=fp3[jind].hour;
		fp[index].min=fp3[jind].min;
		fp[index].sec=fp3[jind].sec;
		fp[index].mday1=fp3[jind].mday1;
		fp[index].mon1=fp3[jind].mon1;
		fp[index].year1=fp3[jind].year1;
	}
	return ;
}
*/	
void monitor()
{
	int j,jind;
	FILE *fp6,*fp7;
	fp7=fopen("password.log","r");
	fread(passwd,sizeof(passwd),1,fp7);
	fp6=fopen("db.log","r");
	fc(folderpath1);
	int index;
	for(i=0;i<count;i++){
		for(j=0;j<fcnt;j++){	
			if(fp[i].inode==fp3[j].inode){
				if(!strcmp(fp3[j].name,fp[i].name)&&(fp3[j].inode==fp[i].inode)&&(!strcmp((char *)fp3[j].hash,(char *)fp[i].hash))&&(!strcmp(fp3[j].path,fp[i].path))&&(fp3[j].hour==fp[i].hour)&&(fp3[j].min==fp[i].min)&&(fp3[j].sec==fp[i].sec)&&(fp3[j].mday1==fp[i].mday1)&&(fp3[j].mon1==fp[i].mon1)&&(fp3[j].year1==fp[i].year1)){
					
											}
				else
				{
					index=i;
					jind=j;
					verifynupdate(index,jind);
					flag=1;
				}
			}
		}
	}
	if(flag==0)
		printf("\n---------------No file has got modified--------------\n");
	fp6=fopen("db.log","w");
	fwrite(fp,sizeof(struct fileprop),count,fp6);
	fclose(fp6);
}

void print()
{
	int l=0;
	printf("in print");
	printf("count= %d\n",count);
	for(l=0;l<count;l++){
		printf("\n1.file %s inode %d path %s time - %d:%d:%d  \n  hash: ",fp[l].name,fp[l].inode,fp[l].path,fp[l].hour,fp[l].min,fp[l].sec);
		print_md5_sum(fp[l].hash);
		printf("\n2.file %s inode %d path %s time - %d:%d:%d  \n  hash: ",fp3[l].name,fp3[l].inode,fp3[l].path,fp3[l].hour,fp3[l].min,fp3[l].sec);
		print_md5_sum(fp3[l].hash);
		
	}
	for(l=0;l<count;l++){	
		
	}
	return;
}

void createstruct(char *drf){
	FILE *ff;	
	DIR *dir;
	struct dirent *ent;
	
	struct stat fa;
	char path[5000];
	if((dir=opendir(drf))==NULL)
		return;

	while((ent=readdir(dir))!=NULL)
	{

		if(!strcmp(ent->d_name,".."))
		continue;
		if(!strcmp(ent->d_name,"."))
		continue;
		strcpy(path,drf);
		strcat(path,"/");
		strcat(path,ent->d_name);
		stat(path,&fa);
		if(S_ISDIR(fa.st_mode)){		
			fc(path);
		}
		else{
			count++;
		}
		memset(path,'\0',sizeof(path));
	}
	count=count+cnt;
		f=1;
	cnt=0;
	fp=(struct fileprop*)calloc(count,sizeof(struct fileprop));
	if(fp==NULL){
		printf("memory allocation failed\n");
		return;
	}
	ff=fopen("db.log","r");
	fseek(ff,0,SEEK_END);
	int e=ftell(ff);	
	rewind(ff);
	fcnt=e/sizeof(struct fileprop);
	fp3=(struct fileprop*)calloc(e/sizeof(struct fileprop),sizeof(struct fileprop));
	fread(fp3,sizeof(struct fileprop),e/sizeof(struct fileprop),ff);
	fclose(ff);
	return;
}
