#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXINT 65536
#define LEN 10000
int n=100;
typedef struct {                         // 哈夫曼树存储表示
	char data;							 // 数据域
	int weight;                          // 权值
	int parent, lchild, rchild;         // 父结点、左孩子、右孩子
} HTNode, *HuffmanTree;                 // 动态分配数组存储哈夫曼树

typedef char** HuffmanCode;            // 动态分配数组存储哈夫曼编码表
 
typedef struct {                       // 字符集存储表示
	char character;                    // 字符
	int frequency;                    // 字符出现频率，作为权值
} List, *Chart;

int CreateChart(Chart &h)             // 建立字符集h
{
	int m, n;
	char e;   
	printf ("输入n(表示字符集大小，字符个数和权值个数)：");
	while (scanf ("%d", &n) != 1) {
		getchar();
		printf ("请输入整数：");
		scanf ("%d", &n);
	}
	h = (Chart)malloc(sizeof(List) * n);
	printf ("输入字符和频度：\n");
	for (int i = 0; i < n; i++) {
	   	getchar();
		printf ("第%d：", i);
		scanf ("%c %d", &e, &m);
		h[i].character = e;
		h[i].frequency = m;
	}
	return n;
}

void PrintChart(Chart h, int n)                  // 输出字符集
{
	printf ("字符集为：\n");
	for (int i = 0; i < n; i++) {
		printf ("%c ", h[i].character);
		printf ("%d\n", h[i].frequency);
	}
}

void SelectMinTwo(HuffmanTree &T, int n, int &s1, int &s2)        // 选择权值最小的次小的两颗二叉树
{
	int m1, m2;
	m1 = m2 = MAXINT;
	for (int j = 0; j < n; j++)
		if (T[j].parent == -1 && T[j].weight <= m1) {
			s2 = s1;
			s1 = j;
			m2 = m1;
			m1 = T[s1].weight;
		}
		else if (T[j].parent == -1 && T[j].weight <= m2) {  // T[s1].weight < T[j].weight < T[s2].weight
			s2 = j;
			m2 = T[s2].weight;
		}
}

void PrintTree(HuffmanTree T, int n)                    // 打印哈夫曼树
{
	printf ("哈夫曼树为：\n");
	printf ("  parent lchild rchild data weight\n");
    for (int i = 0; i < n * 2 - 1; i++) {
		printf ("%d: ", i);
		printf ("%3d ", T[i].parent);
		printf ("%6d ", T[i].lchild);
		printf ("%6d ", T[i].rchild);
		printf ("%5c ", T[i].data);
		printf ("%5d\n", T[i].weight);
	}
}

void CreateHuffmanTree(HuffmanTree &T, Chart &h, int n)         // 建立哈夫曼树
{
	int i;
	int s1 = 0, s2 = 0;
	T = (HuffmanTree)malloc(sizeof(HTNode) * (n * 2 - 1));
	for (i = 0; i < n * 2 - 1; i++) {                           // 初始化
		T[i].parent = -1;
		T[i].lchild = -1;
		T[i].rchild = -1;
		T[i].data = ' '; 
		T[i].weight = 0;
	}
	for (i = 0; i < n; i++) {
		T[i].data = h[i].character;
		T[i].weight = h[i].frequency;
	}
	for (i = 0; i < n - 1; i++) {                  
		s1 = 0, s2 = 0;
		SelectMinTwo(T, n + i, s1, s2);                        // 选择权值最小的次小的两颗二叉树
		T[n + i].parent = -1;                                  // 设置新根的parent域
		T[n + i].lchild = s1;								   // 设置新根的左孩子	
		T[n + i].rchild = s2;                                  // 设置新根的右孩子
		T[n + i].data = ' ';                                   // 设置新根的数据域
		T[n + i].weight = T[s1].weight + T[s2].weight;         // 设置新根的权值为最小和次小二叉树权值之和
		T[s1].parent = n + i;                                  // 修改最小二叉树parent域
		T[s2].parent = n + i;                                  // 修改最小二叉树parent域
	}
	printf ("\n");
}
void HuffmanPutIn(FILE *x){                                      //输入报文
	if ((x = fopen("ToBeTran.txt", "w")) == NULL) {    
		printf ("File open error!\n");
		exit(0);
	}
getchar();
char ch[100];
		printf("\n输入报文内容");                              //输入无法接受空格符；
		gets(ch);
	    fputs(ch,x);
			if(fclose(x)){
		printf("can not close the file !\n");
		exit(0);
			}
}

void HuffmanCoding(HuffmanTree &T, HuffmanCode &HC, int n)    // 编码表
{
	int f, c;
    int start;
	HC = (HuffmanCode)malloc(sizeof(char *) * n);            // 分配n个char *类型的字符数组用来存储所有叶子结点的编码
	char *cd = (char *)malloc(sizeof(char) * n);             // 分配n个char类型的字符数组用来存储叶子结点的编码
	cd[n - 1] = '\0';
	for (int i = 0; i < n; i++) {                            // 从叶子结点出发走一条叶子到根的路径
		start = n - 1;
		for (c = i, f = T[i].parent; f != -1; c = f, f = T[f].parent)
			if (T[f].lchild == c)
				cd[--start] = '0';                           
			else
				cd[--start] = '1';
		HC[i] = (char *)malloc(sizeof(char) * (n - start));   // 为每个结点的编码分配存储空间
		strcpy(HC[i], &cd[start]);
	}
	free(cd);
}

void Coding(HuffmanCode &HC,FILE *x,FILE* y,HuffmanTree &T){//对报文内容进行编码并将结果存入"CodeFile.txt
	char ch;
	int i;
	if((x=fopen("ToBeTran.txt","r"))==NULL){     //打开报文文件
		printf("ToBeTran File open error! \n");
		exit(0);
	}
	if((y=fopen("CodeFile.txt","w"))==NULL){     //打开编码结果文件
		printf("CodeFile File  open error! \n");
		exit(0);
	}
	while(!(feof(x))){                              //读取报文内容
		ch=fgetc(x);
		for(i=0;i<=n;i++){
			if(ch==T[i].data){
				fputs(HC[i],y);
				break;
			}
		}
	}
	if(fclose(x)){
		printf("can not close the file !\n");
		exit(0);
	}
	if(fclose(y)){
		printf("can not close the file !\n");
		exit(0);
	}
}
void HuffmanTranslate(HuffmanTree T, char *&str, int n,FILE* y)          // 译码，将翻译的内容存入str
{
	int k = 0;
	unsigned i, j = 0;
	char *Code = (char *)malloc(sizeof(char) * LEN);        // 分配空间用来存储从文件中读取的编码
	str = (char *)malloc(sizeof(char) * (n + 1));          // 分配空间用来存储编码翻译的内容

	FILE *pFile;
		if((y=fopen("CodeFile.txt","r"))==NULL){        //打开编码文件
		printf("CodeFile File  open error! \n");
		exit(0);
	}
	fscanf(y, "%s", Code);                             // 读取文件内容到Code
	fclose(y);                                         // 关闭文件
	printf ("从CodeFile文件中读取的编码为：\n%s\n", Code);
	printf ("CodeFile里的编码以紧凑格式输出为：\n");       // 以紧凑格式向终端输出
	for (i = 0; i < strlen(Code); i++) {
		printf ("%c", Code[i]);
		if ((i + 1) % 50 == 0)
			printf ("\n");
	}
	printf ("\n");

	if ((pFile = fopen("CodePrin.txt", "w")) == NULL) {   // 将编码紧凑格式存入文件CodePrin
		printf ("File open error!\n");
		exit(0);
	}
	for (i = 0; i < strlen(Code); i++) {
		fprintf (pFile, "%c", Code[i]);                  // 向CodePrin文件写入编码
		if ((i + 1) % 50 == 0)
			fprintf (pFile, "\n");
	}
	fclose(pFile);                                      // 关闭文件
	
	i = 2 * n - 2;                                      // 设置i为根结点存储位置
	while (j != strlen(Code)) {                         // 译码过程，将编码进行翻译
		if (Code[j] == '0')
			i = T[i].lchild;
		else
			i = T[i].rchild;
		if (T[i].lchild == -1 && T[i].rchild == -1) {   // 到了叶子结点
			str[k++] = T[i].data;                       // 将叶子结点的数据域存入str
			i = 2 * n - 2;
		}
		j++;
	}
	str[k] = '\0';                                    //译码结果
	free(Code);                                      // 释放空间
} 

void PrintCode(HuffmanCode HC, int n)               // 打印编码表
{
	printf ("编码表为：\n");
	for (int i = 0; i < n; i++)
		printf ("%s ", HC[i]);
	printf ("\n");
}

void UI()                                          // 用户界面
{
	printf ("------------------------------------\n");
	printf ("   1.构造字符集    2.显示字符集\n");
	printf ("   3.构造哈夫曼树  4.显示哈夫曼树\n");
	printf ("   5.编码          6.显示编码\n");
	printf ("   7.译码          8.显示翻译的内容\n");
	printf ("   9.退出\n");
	printf ("   请选择操作：\n");
	printf ("------------------------------------\n");
}

int main()                          // 主函数
{
	HuffmanTree T;
	Chart h;
	HuffmanCode HC;
	FILE *pFile, *fp,*x,*y;			// 文件指针
	char *str = NULL;		    	// 存储译码
	int i;                          //计数
	char choice;                    // 存储用户选择
	printf("********************************************************************************\n");
	printf(" 数据结构与算法    课程设计    12级计算机科学与技术一班    李畅    2012329620003\n");
	printf("********************************************************************************\n");
	UI();
	while (scanf ("%c", &choice) && (choice = toupper(choice)) != 'Q') {
		switch (choice) {
			case '1':
				n = CreateChart(h);                                   // 建立字符集
				UI();                                                 // 再次显示UI
				break;
			case '2':
				PrintChart(h, n);                                    // 输出字符集
				UI();  
				break;
			case '3': 
				CreateHuffmanTree(T, h, n);                          // 构造哈夫曼树
				printf ("构造完毕，请选择4来查看\n");
				if ((pFile = fopen("hfmTree.txt", "w")) == NULL) {     // 向hfmTree写入哈夫曼树       
					printf ("File open error!\n");
					exit(0);
				}
				fprintf (pFile, "哈夫曼树为：\n");
				fprintf(pFile, "  parent lchild rchild data weight\n");
				for (i = 0; i < n * 2 - 1; i++) {                                   
					fprintf (pFile, "%d: ", i);
					fprintf(pFile, "%3d %6d %6d %5c %5d\n", T[i].parent, T[i].lchild         // 将哈夫曼树存入文件hfmTree 
						, T[i].rchild, T[i].data, T[i].weight);
				}
				fclose(pFile);

				char c;                                             
				if ((pFile = fopen("hfmTree.txt", "r")) == NULL){
					printf ("File open error!\n");
					exit(0);													// 将文件hfmTree中的内容复制到TreePrint中
				}
				if ((fp = fopen("TreePrint.txt", "w")) == NULL) {
					printf ("File open error!\n");
					exit(0);
				}
				while (!feof(pFile)) {                                       // 复制过程
					c = fgetc(pFile);
					fputc(c, fp);
				}
				fclose(pFile);
				fclose(fp);
				UI();
				break;
			case '4':
				PrintTree(T, n);                                          // 打印哈夫曼树
				UI();
				break;
			case '5':
				 HuffmanCoding(T, HC, n);                               //编码表                            
				printf ("编码完毕，请选择6来查看编码\n");
				if ((pFile = fopen("CodeFile.txt", "w")) == NULL) {
					printf ("File open error!\n");
					exit(0);
				}
				for (i = 0; i < n; i++)
					fprintf (pFile, "%s", HC[i]);                   // 将编码写入文件
				fclose(pFile);
			
				  HuffmanPutIn(x);
                 Coding(HC,x,y,T);
				 	UI();

				break;
			case '6':
				PrintCode(HC, n);                                  // 向终端打印出编码
				UI();
				break;
			case '7':
				HuffmanTranslate(T, str, n,y);                       // 翻译
				printf ("翻译完毕，请选择8来查看译码\n");
				if ((pFile = fopen("TextFile.txt", "w")) == NULL) {
					printf ("File open error!\n");
					exit(0);
				}
				fprintf (pFile, "%s", str);						   // 将译码存入文件
				fclose(pFile);
				UI();
				break;
			case '8':
				printf ("翻译后的文字为：%s\n", str);            // 向终端输出翻译的内容
				UI();
				break;
			case '9':
				printf ("程序结束");                             // 用户选择q，程序退出
				break;
		}
	}
	return 0; 
}