#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXINT 65536
#define LEN 10000
int n=100;
typedef struct {                         // ���������洢��ʾ
	char data;							 // ������
	int weight;                          // Ȩֵ
	int parent, lchild, rchild;         // ����㡢���ӡ��Һ���
} HTNode, *HuffmanTree;                 // ��̬��������洢��������

typedef char** HuffmanCode;            // ��̬��������洢�����������
 
typedef struct {                       // �ַ����洢��ʾ
	char character;                    // �ַ�
	int frequency;                    // �ַ�����Ƶ�ʣ���ΪȨֵ
} List, *Chart;

int CreateChart(Chart &h)             // �����ַ���h
{
	int m, n;
	char e;   
	printf ("����n(��ʾ�ַ�����С���ַ�������Ȩֵ����)��");
	while (scanf ("%d", &n) != 1) {
		getchar();
		printf ("������������");
		scanf ("%d", &n);
	}
	h = (Chart)malloc(sizeof(List) * n);
	printf ("�����ַ���Ƶ�ȣ�\n");
	for (int i = 0; i < n; i++) {
	   	getchar();
		printf ("��%d��", i);
		scanf ("%c %d", &e, &m);
		h[i].character = e;
		h[i].frequency = m;
	}
	return n;
}

void PrintChart(Chart h, int n)                  // ����ַ���
{
	printf ("�ַ���Ϊ��\n");
	for (int i = 0; i < n; i++) {
		printf ("%c ", h[i].character);
		printf ("%d\n", h[i].frequency);
	}
}

void SelectMinTwo(HuffmanTree &T, int n, int &s1, int &s2)        // ѡ��Ȩֵ��С�Ĵ�С�����Ŷ�����
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

void PrintTree(HuffmanTree T, int n)                    // ��ӡ��������
{
	printf ("��������Ϊ��\n");
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

void CreateHuffmanTree(HuffmanTree &T, Chart &h, int n)         // ������������
{
	int i;
	int s1 = 0, s2 = 0;
	T = (HuffmanTree)malloc(sizeof(HTNode) * (n * 2 - 1));
	for (i = 0; i < n * 2 - 1; i++) {                           // ��ʼ��
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
		SelectMinTwo(T, n + i, s1, s2);                        // ѡ��Ȩֵ��С�Ĵ�С�����Ŷ�����
		T[n + i].parent = -1;                                  // �����¸���parent��
		T[n + i].lchild = s1;								   // �����¸�������	
		T[n + i].rchild = s2;                                  // �����¸����Һ���
		T[n + i].data = ' ';                                   // �����¸���������
		T[n + i].weight = T[s1].weight + T[s2].weight;         // �����¸���ȨֵΪ��С�ʹ�С������Ȩֵ֮��
		T[s1].parent = n + i;                                  // �޸���С������parent��
		T[s2].parent = n + i;                                  // �޸���С������parent��
	}
	printf ("\n");
}
void HuffmanPutIn(FILE *x){                                      //���뱨��
	if ((x = fopen("ToBeTran.txt", "w")) == NULL) {    
		printf ("File open error!\n");
		exit(0);
	}
getchar();
char ch[100];
		printf("\n���뱨������");                              //�����޷����ܿո����
		gets(ch);
	    fputs(ch,x);
			if(fclose(x)){
		printf("can not close the file !\n");
		exit(0);
			}
}

void HuffmanCoding(HuffmanTree &T, HuffmanCode &HC, int n)    // �����
{
	int f, c;
    int start;
	HC = (HuffmanCode)malloc(sizeof(char *) * n);            // ����n��char *���͵��ַ����������洢����Ҷ�ӽ��ı���
	char *cd = (char *)malloc(sizeof(char) * n);             // ����n��char���͵��ַ����������洢Ҷ�ӽ��ı���
	cd[n - 1] = '\0';
	for (int i = 0; i < n; i++) {                            // ��Ҷ�ӽ�������һ��Ҷ�ӵ�����·��
		start = n - 1;
		for (c = i, f = T[i].parent; f != -1; c = f, f = T[f].parent)
			if (T[f].lchild == c)
				cd[--start] = '0';                           
			else
				cd[--start] = '1';
		HC[i] = (char *)malloc(sizeof(char) * (n - start));   // Ϊÿ�����ı������洢�ռ�
		strcpy(HC[i], &cd[start]);
	}
	free(cd);
}

void Coding(HuffmanCode &HC,FILE *x,FILE* y,HuffmanTree &T){//�Ա������ݽ��б��벢���������"CodeFile.txt
	char ch;
	int i;
	if((x=fopen("ToBeTran.txt","r"))==NULL){     //�򿪱����ļ�
		printf("ToBeTran File open error! \n");
		exit(0);
	}
	if((y=fopen("CodeFile.txt","w"))==NULL){     //�򿪱������ļ�
		printf("CodeFile File  open error! \n");
		exit(0);
	}
	while(!(feof(x))){                              //��ȡ��������
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
void HuffmanTranslate(HuffmanTree T, char *&str, int n,FILE* y)          // ���룬����������ݴ���str
{
	int k = 0;
	unsigned i, j = 0;
	char *Code = (char *)malloc(sizeof(char) * LEN);        // ����ռ������洢���ļ��ж�ȡ�ı���
	str = (char *)malloc(sizeof(char) * (n + 1));          // ����ռ������洢���뷭�������

	FILE *pFile;
		if((y=fopen("CodeFile.txt","r"))==NULL){        //�򿪱����ļ�
		printf("CodeFile File  open error! \n");
		exit(0);
	}
	fscanf(y, "%s", Code);                             // ��ȡ�ļ����ݵ�Code
	fclose(y);                                         // �ر��ļ�
	printf ("��CodeFile�ļ��ж�ȡ�ı���Ϊ��\n%s\n", Code);
	printf ("CodeFile��ı����Խ��ո�ʽ���Ϊ��\n");       // �Խ��ո�ʽ���ն����
	for (i = 0; i < strlen(Code); i++) {
		printf ("%c", Code[i]);
		if ((i + 1) % 50 == 0)
			printf ("\n");
	}
	printf ("\n");

	if ((pFile = fopen("CodePrin.txt", "w")) == NULL) {   // ��������ո�ʽ�����ļ�CodePrin
		printf ("File open error!\n");
		exit(0);
	}
	for (i = 0; i < strlen(Code); i++) {
		fprintf (pFile, "%c", Code[i]);                  // ��CodePrin�ļ�д�����
		if ((i + 1) % 50 == 0)
			fprintf (pFile, "\n");
	}
	fclose(pFile);                                      // �ر��ļ�
	
	i = 2 * n - 2;                                      // ����iΪ�����洢λ��
	while (j != strlen(Code)) {                         // ������̣���������з���
		if (Code[j] == '0')
			i = T[i].lchild;
		else
			i = T[i].rchild;
		if (T[i].lchild == -1 && T[i].rchild == -1) {   // ����Ҷ�ӽ��
			str[k++] = T[i].data;                       // ��Ҷ�ӽ������������str
			i = 2 * n - 2;
		}
		j++;
	}
	str[k] = '\0';                                    //������
	free(Code);                                      // �ͷſռ�
} 

void PrintCode(HuffmanCode HC, int n)               // ��ӡ�����
{
	printf ("�����Ϊ��\n");
	for (int i = 0; i < n; i++)
		printf ("%s ", HC[i]);
	printf ("\n");
}

void UI()                                          // �û�����
{
	printf ("------------------------------------\n");
	printf ("   1.�����ַ���    2.��ʾ�ַ���\n");
	printf ("   3.�����������  4.��ʾ��������\n");
	printf ("   5.����          6.��ʾ����\n");
	printf ("   7.����          8.��ʾ���������\n");
	printf ("   9.�˳�\n");
	printf ("   ��ѡ�������\n");
	printf ("------------------------------------\n");
}

int main()                          // ������
{
	HuffmanTree T;
	Chart h;
	HuffmanCode HC;
	FILE *pFile, *fp,*x,*y;			// �ļ�ָ��
	char *str = NULL;		    	// �洢����
	int i;                          //����
	char choice;                    // �洢�û�ѡ��
	printf("********************************************************************************\n");
	printf(" ���ݽṹ���㷨    �γ����    12���������ѧ�뼼��һ��    �    2012329620003\n");
	printf("********************************************************************************\n");
	UI();
	while (scanf ("%c", &choice) && (choice = toupper(choice)) != 'Q') {
		switch (choice) {
			case '1':
				n = CreateChart(h);                                   // �����ַ���
				UI();                                                 // �ٴ���ʾUI
				break;
			case '2':
				PrintChart(h, n);                                    // ����ַ���
				UI();  
				break;
			case '3': 
				CreateHuffmanTree(T, h, n);                          // �����������
				printf ("������ϣ���ѡ��4���鿴\n");
				if ((pFile = fopen("hfmTree.txt", "w")) == NULL) {     // ��hfmTreeд���������       
					printf ("File open error!\n");
					exit(0);
				}
				fprintf (pFile, "��������Ϊ��\n");
				fprintf(pFile, "  parent lchild rchild data weight\n");
				for (i = 0; i < n * 2 - 1; i++) {                                   
					fprintf (pFile, "%d: ", i);
					fprintf(pFile, "%3d %6d %6d %5c %5d\n", T[i].parent, T[i].lchild         // ���������������ļ�hfmTree 
						, T[i].rchild, T[i].data, T[i].weight);
				}
				fclose(pFile);

				char c;                                             
				if ((pFile = fopen("hfmTree.txt", "r")) == NULL){
					printf ("File open error!\n");
					exit(0);													// ���ļ�hfmTree�е����ݸ��Ƶ�TreePrint��
				}
				if ((fp = fopen("TreePrint.txt", "w")) == NULL) {
					printf ("File open error!\n");
					exit(0);
				}
				while (!feof(pFile)) {                                       // ���ƹ���
					c = fgetc(pFile);
					fputc(c, fp);
				}
				fclose(pFile);
				fclose(fp);
				UI();
				break;
			case '4':
				PrintTree(T, n);                                          // ��ӡ��������
				UI();
				break;
			case '5':
				 HuffmanCoding(T, HC, n);                               //�����                            
				printf ("������ϣ���ѡ��6���鿴����\n");
				if ((pFile = fopen("CodeFile.txt", "w")) == NULL) {
					printf ("File open error!\n");
					exit(0);
				}
				for (i = 0; i < n; i++)
					fprintf (pFile, "%s", HC[i]);                   // ������д���ļ�
				fclose(pFile);
			
				  HuffmanPutIn(x);
                 Coding(HC,x,y,T);
				 	UI();

				break;
			case '6':
				PrintCode(HC, n);                                  // ���ն˴�ӡ������
				UI();
				break;
			case '7':
				HuffmanTranslate(T, str, n,y);                       // ����
				printf ("������ϣ���ѡ��8���鿴����\n");
				if ((pFile = fopen("TextFile.txt", "w")) == NULL) {
					printf ("File open error!\n");
					exit(0);
				}
				fprintf (pFile, "%s", str);						   // ����������ļ�
				fclose(pFile);
				UI();
				break;
			case '8':
				printf ("����������Ϊ��%s\n", str);            // ���ն�������������
				UI();
				break;
			case '9':
				printf ("�������");                             // �û�ѡ��q�������˳�
				break;
		}
	}
	return 0; 
}