#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
#define ok 1
 
//赫夫曼树的存储结构
typedef struct {
    	char ch;
    	int weight;
    	int parent,lchild,rchild;
}HTNode,*Huffmantree;  
typedef int Status;
 
//用s1和s2返回前end个结点中最小权重和次小权重的序号 
Status select(Huffmantree HT,int end,int &s1,int &s2)
{
	int i,count;
	int m,n,tmp;
	if(end<2)
		return 0;
	for(i=1,count=1;i<=end;i++)
	{
		if(HT[i].parent ==0)
		{
			if(count==1)
				m=i;
			if(count==2)
				n=i;
			count++;
		}
		if(count>2)
			break;
	}
	if(HT[m].weight>HT[n].weight)
	{
		tmp=n;
		n=m;
		m=tmp;
	}
	i=(m>n?m:n)+1;
	while(i<=end)
	{
		if(HT[i].parent==0)
		{
			if(HT[i].weight<HT[m].weight)
			{
				n=m;
				m=i;
			}
			else
			{
				if(HT[i].weight>=HT[m].weight&&HT[i].weight<HT[n].weight)
				n=i;
			}
		}
		i++;
	}
	s1=HT[m].weight<=HT[n].weight?m:n;
	s2=HT[m].weight>HT[n].weight?m:n;
	return ok;
}
 
 
//w[]存放n个字符的权值，str存放n个字符名ch，构造赫夫曼树HT，并求出n个字符的编码
int HuffmanCoding(Huffmantree &HT,char** &HC, int *w, int n,char *str)
{
	int i,m;
     if (n<=1)  return 0;  
    	m = 2*n-1;
     HT =(Huffmantree)malloc((m+1)*sizeof(HTNode));
     for(i=1; i<=n; i++) 
	{
         HT[i].weight = w[i-1];
         HT[i].parent = 0;
         HT[i].lchild = HT[i].rchild = 0;
         HT[i].ch=str[i-1];
    }
    for(; i<=m; ++i)//m=2*n-1
	{
		 HT[i].ch='\0';
         HT[i].parent = 0;
         HT[i].lchild = HT[i].rchild = 0;
	} 
	for(i=n+1; i<=m; i++)
	{//构造赫夫曼树,m=2*n-1
    //从HT[1..i-1]中选择parent为0且weight最小的两个结点，其序号为s1和s2
    int s1, s2;
    select(HT,i-1,s1,s2);
    HT[s1].parent = i;     HT[s2].parent = i; 
    HT[i].lchild = s1;       HT[i].rchild = s2;
    HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
//从叶子到根逆向求每个字符的赫夫曼编码
   HC = (char **)malloc((n+1)*sizeof(char*));
   char *cd;
   cd = (char *)malloc(n*sizeof(char));    
   cd[n-1] = '\0';
   for(i=1; i<=n; i++)  
   {
      int start = n-1;
      for(int c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
      	{
           if (HT[f].lchild == c)   cd[--start]='0';
           else cd[--start]='1';
    	}
      HC[i] = (char*)malloc((n-start)*sizeof(char));
      strcpy(HC[i],&cd[start]);
      	//printf("%c的哈夫曼编码是%s\n",HT[i].ch,HC[i]);
   }
  free(cd);
 
  return ok;
}//HuffmanCoding
 
//将二进制编码翻译回信息原文，m是树根的编号
int  Decoding(Huffmantree HT,int m,char *buff)
 {   
       int p = m;   
	  while (*buff != '\0' && p != 0) {
           if ((*buff)=='0') 
                 p = HT[p].lchild; //进入左分支
	      else 
                 p = HT[p].rchild; //进入右分支
	      buff++; 
           if (!HT[p].lchild && !HT[p].rchild) { 
               //进入叶子结点
               printf("%c",HT[p].ch);   
               p = m; //重新从树根出发进行译码
           }//if
	}//while
	return ok;
}//Decoding	
 
void ShowHuffmanTree(Huffmantree HT,int n)
{
	int i;
	printf("┍┉┉┉┉┉┉┉┉┱┉┉┉┉┉┉┉┉┱┉┉┉┉┉┉┉┉┲┉┉┉┉┉┉┉┉┲┉┉┉┉┉┉┉┉┲┉┉┉┉┉┉┉┉┒\n");
	printf("┋   ch   ┋ order  ┋ weight ┋ parent ┋ lchild ┋ rchild ┋\n");
	for(i=1;i<=n;i++)
			printf("┋   %c    ┋   %2d   ┋   %3d  ┋   %2d   ┋   %2d   ┋   %2d   ┋\n",
			HT[i].ch,i,HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
	printf("┖┉┉┉┉┉┉┉┉┺┉┉┉┉┉┉┉┉┺┉┉┉┉┉┉┉┉┺┉┉┉┉┉┉┉┉┺┉┉┉┉┉┉┉┉┺┉┉┉┉┉┉┉┉┚\n");
 } 
 
 void ShowHuffmanCode(Huffmantree HT,char** HC,int n)
 {
 	int i;
 	printf("┍┉┉┉┉┉┉┉┉┱┉┉┉┉┉┉┉┉┲┉┉┉┉┉┉┉┉┲┉┉┉┉┉┉┉┉┲┉┉┉┉┉┉┉┉┒\n");
 	printf("┋   ch   ┋ order  ┋ weight ┋        ┋  Code  ┋\n");
 	for(i=1;i<=n;i++)
 	printf("┋   %c    ┋   %2d   ┋   %2d   ┋  ---->  %-8s┋\n",
	 HT[i].ch,i,HT[i].weight,HC[i]);
 	printf("┖┉┉┉┉┉┉┉┉┺┉┉┉┉┉┉┉┉┺┉┉┉┉┉┉┉┉┺┉┉┉┉┉┉┉┉┺┉┉┉┉┉┉┉┉┚\n");
 }
 
int main()
{
	int n,m;
	printf("请输入叶子结点的个数：");
	scanf("%d",&n);
	int w[n]; 
	printf("\n请依次输入各结点的权值：\n");
	for(int i=0;i<n;i++)
		scanf("%d",&w[i]); 
	char str[n];
	printf("\n给叶子结点起个名字：\n");
	scanf("%s",str);
	Huffmantree HT;char** HC;
	printf("\n哈夫曼树构建中...\n\n"); 
	HuffmanCoding( HT, HC, w,  n, str);
	printf("打印哈夫曼树：\n"); 
	ShowHuffmanTree( HT,2*n-1);
	printf("\n打印叶子结点的哈夫曼编码：\n"); 
	ShowHuffmanCode( HT, HC, n);
	
	printf("\n执行解码操作，请输入一串哈夫曼编码：\n");
	char buff[50];
	scanf("%s",buff);
	printf("解码为：\n");
	Decoding( HT, 2*n-1 ,buff);
	printf("\n");
	system("pause");
	return 0;
}
 
/* test data
8
5 29 7 8 14 23 3 11
abcdefgh
a的哈夫曼编码是0001
b的哈夫曼编码是10
c的哈夫曼编码是1110
d的哈夫曼编码是1111
e的哈夫曼编码是110
f的哈夫曼编码是01
g的哈夫曼编码是0000
h的哈夫曼编码是001
*/