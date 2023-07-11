#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <cctype>
using namespace std;
ofstream oFile("Film.txt",ios::app|ios::out);

class Seat {  
private: 
	bool label;         // ��λ�Ƿ��Ѷ���־
	double price;       // �õ�Ӱ��ͬ��λƱ��
public:
	Seat(): label(true), price(0) {}                // ���캯��
	void SetLabel(bool lb) { label = lb; }          // ���ø���λ�Ƿ��ѱ�Ԥ�����
	void SetPrice(double p) { price = p; }          // ���ø���λƱ��
	bool GetLabel() const { return label; }
	double GetPrice() const { return price; }       
};

class MovieInfo { 
private:
	string MovieName;				// ��Ӱ��
	string ShowTime;                // ����
	double price[3];                // 3�ֲ�ͬƱ��
	int TotalTickets, LeftTickets;	// ��Ʊ����ʣ��Ʊ��
	int SoldTickets;			    // ��Ʊ���
	int TotalSeat, LeftSeat;		// ����λ����ʣ����λ��
	int line, row;                  // ��¼ѡ����λ���
	Seat S[10][10];                 // ��λͼ// ��Ӱ��Ϣ�࣬��Ҫ���õ�Ӱ����Ʊ�۵�
public:
	MovieInfo();                                    // ���캯��
	MovieInfo(const string &name, const string& t, int p1, int p2, int p3);

	void SetMovieInfoEach(const string &name);                // ���õ�Ӱ��Ϣ�����ڵ���SetShowTime��SetPriceByPosition
    void SetShowTime(const string& t) { ShowTime = t; }       // ���õ�Ӱ����ʱ��
    void SetPriceByPosition(double p1, double p2, double p3);  // ���ò�ͬλ��Ʊ�ۣ��ֳ����ֲ�ͬƱ��

	string GetMovieName() const { return MovieName; }  // �õ���Ӱ����
	string GetShowTime() const  { return ShowTime; }   // �õ�����ʱ��

	void ShowSeat() const;                            // ��ʾ��λ���
	bool SeatChoose(int& TurnOver);                   // ѡ����λ
	void ChooseResult() const;                        // �û�ѡ������ʾ
	void Pay();                                       // ����

	int SeatTotal() const { return TotalSeat; }       // ��ʾ����λ��
	int SeatLeft() const { return LeftSeat; }         // ��ʾʣ����λ��

	int TicketTotal() const { return TotalSeat; }     // ��ʾ��Ʊ��
	int TicketSold() const { return SoldTickets; }    // ��ʾ����Ʊ��
	int TicketLeft() const { return LeftTickets; }    // ��ʾ��Ʊ
		
};
MovieInfo::MovieInfo(): MovieName(" "), TotalTickets(0),       // Ĭ�Ϲ��캯��
		LeftTickets(0), SoldTickets(0), TotalSeat(0), LeftSeat(0), line(0), row(0)
{
}

MovieInfo::MovieInfo(const string &name, const string& t, int p1, int p2, int p3)
		: MovieName(name), TotalTickets(100), LeftTickets(100), SoldTickets(0), 
			TotalSeat(100), LeftSeat(100), line(0), row(0)
{
	SetShowTime(t);                                    // ��ʾ��ǰʱ��
	SetPriceByPosition(p1, p2, p3);                    // ���øò���Ӱ��ͬλ��Ʊ��
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (i < 3)  
				S[i][j].SetPrice(price[0]);            // ����ÿ����λƱ�ۣ�ǰ30����λƱ��Ϊprice[0]
			else if (i < 6)  
				S[i][j].SetPrice(price[1]);            // �м�30����λƱ��price[1]
			else  
				S[i][j].SetPrice(price[2]);            // ���40����λƱ��price[2]
}

void MovieInfo::SetMovieInfoEach(const string &name)         // ���õ�Ӱ��Ϣ
{
	MovieName = name;
	cout << "��Ӱ����: " << MovieName << endl;
	TotalTickets = 100, LeftTickets = 100;   // ��Ʊ������Ʊ��
	SoldTickets = 0;                         // ��ʼ��Ϊ0
	TotalSeat = 100, LeftSeat = 100;         // ����λ����������λ��
	line = 0, row = 0;

	string t;
	cout << "�����÷�ӳʱ�䣺" << endl;
	cin >> t;
	SetShowTime(t);                          // ���÷�ӳʱ�䣬����ÿ���ӳ����
		
	int p1, p2, p3;
 	cout << "��ֱ�����ǰ����������������������Ʊ�ۣ�" << endl;
	cin >> p1 >> p2 >> p3;
	SetPriceByPosition(p1, p2, p3);                    // ���ò�ͬλ��Ʊ�ۣ�����ֳ�����Ʊ��
		
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (i < 3)  
				S[i][j].SetPrice(price[0]);            // ����ÿ����λƱ�ۣ�ǰ30����λƱ��Ϊprice[0]
			else if (i < 6)  
				S[i][j].SetPrice(price[1]);            // �м�30����λƱ��price[1]
			else  
				S[i][j].SetPrice(price[2]);            // ���40����λƱ��price[2]
}

void MovieInfo::SetPriceByPosition(double p1, double p2, double p3)  // ���ò�ͬλ��Ʊ�ۣ��ֳ����ֲ�ͬƱ��
{
	price[0] = p1;
	price[1] = p2;
	price[2] = p3;
}

void MovieInfo::ShowSeat() const                     // ��ʾ��λ���
{
	int i;
	cout<<"��λ��Ϊ��"<<endl;
	for (i = 9; i >= 0; i--) {                      // ��ʾ��λ��
		for (int j = 0; j < 10; j++) 
			cout << "[" << i << "," << j << "]" << " ";
		cout << endl;
	}
	cout<<"����λ��Ʊ��Ϊ��"<<endl;
	for (i = 9; i >= 0; i--) {                     // ��ʾÿ����λ�۸�
		for (int j = 0; j < 10; j++) 
			cout << S[i][j].GetPrice() << "   ";
		cout << endl;
	}
	cout<<"����λ��Ʊ�����1Ϊ����"<<endl;
	for (i = 9; i >= 0; i--) {                     // ��ʾ����λ�Ƿ���Ԥ��
		for (int j = 0; j < 10; j++) 
			cout << S[i][j].GetLabel() << "   ";
		cout << endl; 
	}  
}

bool MovieInfo::SeatChoose(int& TurnOver)          // Ϊ�ò���Ӱѡ����λ
{	
	cout << "�õ�Ӱ���� " << TicketLeft() << " ��Ʊʣ��" << endl; 
	if (LeftTickets == 0) {                        // �ò���ӰƱ������
		cout << "�Բ��𣬵�ӰƱ���۹�." << endl;
		cout << "��ѡ���������εĵ�Ӱ." << endl;   // ѡ��������Ӱ
		return false;
	}
	cout << "<<" << MovieName << ">>" << endl;
	ShowSeat();                                     // ��ʾ��λ���
	int i, j;
	cout << "��ѡ����λ: " << endl;   // �û�ѡ����λ
	cin >> i >> j;
	while (S[i][j].GetLabel() == false) {    // ����λ��Ԥ��
		cout << "����λ���۳�����ѡ��������λ \n";  // ѡ��������λ
		ShowSeat();
		cin >> i >> j;
	}
	S[i][j].SetLabel(false);				// ��λ��ѡ�񣬼�Ϊfalse��������ѡ��
	line = i;								// ��¼ѡ�����
	row = j;								// ��¼ѡ�����
	LeftTickets--;							// ��Ʊ��1
	LeftSeat--;								// ��λ����1
	SoldTickets++;							// ���۳���1
	cout << "��ϲ����Ʊ�ɹ�" << endl;
	ChooseResult();                   // ��ʾ�û���Ʊ���
	TurnOver += S[line][row].GetPrice();
	cout << "ȷ�ϸ���? "<< endl;// ��ʾ����
	cout<<"1.��    2.��"<<endl;
	int choice;
	cin >> choice;
	Pay();                            // ת���������
	cout << "����ɹ���" << endl;
	cout << "�밴0�ص�������" << endl;  // ����ɹ�����ʾ����������
	cin >> choice;
	return true;
}

void MovieInfo::ChooseResult() const   // ��ʾ�û�ѡ���Ӱ����Ϣ��������Ӱ��������ʱ�䡢��λ��Ʊ��
{
	cout<<"*****************************************\n";
	cout << "��Ӱ��Ϣ: " << endl;
	cout << "��Ӱ����: " << MovieName << endl;
	cout << "����ʱ��: " << ShowTime << endl;
	cout << "��λ��: " << line << "��" << row << "��" << endl;
	cout << "Ʊ��Ϊ: " << S[line][row].GetPrice() << endl;
	cout<<"*****************************************\n";
	oFile<<"*****************************************\n";
	oFile << "��Ӱ��Ϣ: " << endl;
	oFile << "��Ӱ����: " << MovieName << endl;
	oFile << "����ʱ��: " << ShowTime << endl;
	oFile << "��λ��: " << line << "��" << row << "��" << endl;
	oFile << "Ʊ��Ϊ: " << S[line][row].GetPrice() << endl;
	oFile<<"*****************************************\n";
	cout<<"�ļ��Ѵ���film.txt��"<<endl;
}

void MovieInfo::Pay()               // �������
{
	cout<<"*****************************************\n";
	cout << "�������������" << endl;   
	cout << "1.��     2.��" << endl;
	int choice;
	cin >> choice;
	cout<<"*****************************************\n";
	cout << "���Ѹ��� " << S[line][row].GetPrice() << "Ԫ" << endl;  // ����ɹ�
	cout << "1.��     2.��" << endl;
	cin >> choice;
	cout<<"*****************************************\n";
}

class ATVM {
public:
	ATVM();                                                // Ĭ�Ϲ��캯��
	ATVM(const string& s1, const string& s2, const string& s3,   // ���캯��
		const string& s4, const string& s5);

	void Initialize();                                     // ��ʼ������ʾ���û����ĵ�һ������

	bool Self_Help_Tickets(int& TurnOver);                 // ������Ʊ���� 

	void SetMovieInfoAll(const string& s1, const string& s2, const string& s3, 
		const string& s4, const string& s5);                 // �������е�Ӱ��Ϣ

	void MovieList();                                // ����Ҫ���ŵ�Ӱ�б�
	
	void ShowCurrentTime();							 // ��ʾ��ǰʱ��
    int GetCurrentTime();							 // �õ���ǰʱ�� 

	int GetTicketSoldAllDay()  { return TicketSoldAllDay; }   // ��������Ʊ���ܺ�

	void SetNowPlaying();                          // ����Ҫ���ŵĵ�Ӱ

	char StaffOperator();                          // ������Ա���ý���

	int ChooseMatch(MovieInfo* MOVIE, const string& time, const string& name);  // �û�ѡ�񳡴��Ƿ����

	void ShowTurnOver()                       // ��ʾӪҵ��
    { 
		cout << "����Ӫҵ��Ϊ�� " << TurnOver << endl;
		oFile << "����Ӫҵ��Ϊ�� " << TurnOver << endl;
		cout<<"�ļ��Ѵ���film.txt��"<<endl;
	}

	void BusinessState()                         // Ӫҵ״������
	{
		cout << "����ӰԺӪҵʱ��Ϊ�����㵽�����賿����" << endl;
		cout << "ÿ����Сʱ��ӳһ����Ӱ�����ѯ��Ʊ" << endl;
	}

private:
	time_t now;
	MovieInfo MOVIE[10];
	string nowPlaying;
	long password;                 // ����
	int TicketSoldAllDay;
	int TurnOver;                  // Ӫҵ��         
	long GetPassword() { return password; }
};

ATVM::ATVM()             // Ĭ�Ϲ��캯��
{
	MOVIE[0] = MovieInfo("", "00:00", 0, 0, 0);
	MOVIE[1] = MovieInfo("", "00:00", 0, 0, 0);
	MOVIE[2] = MovieInfo("", "00:00", 0, 0, 0);
	MOVIE[3] = MovieInfo("", "00:00", 0, 0, 0);
	MOVIE[4] = MovieInfo("", "00:00", 0, 0, 0);
	MOVIE[5] = MovieInfo("", "00:00", 0, 0, 0);
	MOVIE[6] = MovieInfo("", "00:00", 0, 0, 0);
	MOVIE[7] = MovieInfo("", "00:00", 0, 0, 0);
	MOVIE[8] = MovieInfo("", "00:00", 0, 0, 0);
	MOVIE[9] = MovieInfo("", "00:00", 0, 0, 0);
	password = 0;                                 // �����ʼֵΪ0
	TicketSoldAllDay = 0;                         // ����Ʊ��Ϊ0
	TurnOver = 0;                                 // Ӫҵ��Ϊ0
	nowPlaying = "";                             // ��ǰ����Ϊ��
}

ATVM::ATVM(const string& s1, const string& s2, const string& s3,   // ���캯��
		const string& s4, const string& s5) 
{   // Ϊÿ����Ӱ������Ϣ��������Ӱ��������ʱ�䡢�Լ���ͬ��λƱ��
	MOVIE[0] = MovieInfo(s1, "06:00", 50, 40, 30);
	MOVIE[1] = MovieInfo(s2, "08:00", 60, 50, 40);
	MOVIE[2] = MovieInfo(s3, "10:00", 70, 60, 50);
	MOVIE[3] = MovieInfo(s4, "12:00", 100, 80, 60);
	MOVIE[4] = MovieInfo(s5, "14:00", 50, 40, 30);
	MOVIE[5] = MovieInfo(s1, "16:00", 50, 40, 30);
	MOVIE[6] = MovieInfo(s2, "18:00", 60, 50, 40);
	MOVIE[7] = MovieInfo(s3, "20:00", 70, 60, 50);
	MOVIE[8] = MovieInfo(s4, "22:00", 100, 80, 60);
	MOVIE[9] = MovieInfo(s5, "00:00", 50, 40, 30);
	password = 123456;                 // �����ʼֵ��Ϊ123456
	TicketSoldAllDay = 0;              // ����Ʊ��Ϊ0
	TurnOver = 0;                      // Ӫҵ��Ϊ0
	nowPlaying = "";                   // ��ǰ����Ϊ��
}

void ATVM::Initialize()                       
{
	cout<<"********************************************************************************\n";
    cout<<"  C++�������������  �γ����  12������ƿ�ѧ�뼼��1��  �  2012329620003    \n";
    cout<<"********************************************************************************\n";
	cout<<"****************************��ӭ���ٻ�Ԫ��ӰԺ**********************************"<<endl;
	ShowCurrentTime();                    // ��ʾ��ǰ����ʱ��
	SetNowPlaying();                      // ����Ҫ���ŵĵ�Ӱ
	cout<<"*****************************************\n";
	cout << "������ӳ" << endl;
	MovieList();                     // ��ʾ����Ҫ���ŵĵ�Ӱ��ʱ��
	cout<<endl;
	cout << "��ʱ����: \n" << nowPlaying << endl;
	cout<<"*****************************************\n";
	cout << "��ѡ��Ҫ���еĲ���: " << endl;
	cout << "1.��Ʊ  " << endl;     // �û�ѡ��
	cout << "2.Ӫҵʱ���ѯ    " << endl;
	cout << "3.Ա��ͨ��    " << endl;
	cout<<"*****************************************\n";
	int choice;
	int times;
	int hour;
	while (cin >> choice && (choice = toupper(choice))    
		&& !(choice == 1 || choice == 2 || choice == 3 )) 
		cout << "������ѡ��!" << endl;   // ���ѡ����ȷ������ѡ��
	switch (choice) {
		case 1:                         // �û�ѡ��Ʊ
			hour = GetCurrentTime();
			if (hour >= 2 && hour < 6) {   // Ӫҵʱ�䲻�ԣ����ܹ�Ʊ
				cout << "�Բ������ڲ���Ӫҵʱ��" << endl;
				cout << "0.����" << endl; 
			cin >> choice;
			}
			else {
				while (!Self_Help_Tickets(TurnOver));  // ������Ʊ����
				TicketSoldAllDay++;                    // ���������Ʊ����1
			}
			break;
		case 2:
			BusinessState();                   //  Ӫҵ״������
			cout << "0.����" << endl;
			cin >> choice;
			break;
		case 3:                              // Ա��ͨ��
			times = 3;
			cout << "����������: ";    // ��Ҫ�������룬��3�λ���
			long pwd;
			while (cin >> pwd && pwd != password && times != 1) {
				times--;
				cout << "�������!" << endl;
				cout <<	"�㻹�� " << times << " �λ��ᡣ ";
			}
			if (times == 1 && pwd != 123456) {
				cout << "������֤����!" << endl;    // �������ޣ��ص�������
				cout << "0.����" << endl;
				cin >> choice;
			}
			else {
				while (choice != 0) 
					choice = StaffOperator();        // ������ȷ������Ա������
			}
			break;

	}
}

bool ATVM::Self_Help_Tickets(int& TurnOver)         // ������Ʊ����
{
	MovieList();                                    // ��ʾ���ղ��ŵ�Ӱ�б�
	cout << "��ѡ�����뿴�ĵ�Ӱ: " << endl;
	cout << "���磬�������� \"22:00 ��������\"" << endl;
	string time, name;                              // �û�ѡ��ĳ��Σ��������֡�����ʱ�䣩  
	cin >> time;
    getchar();
	getline(cin, name);
	int i;
	while ((i = ChooseMatch(MOVIE, time, name)) == -1) {  // �û�ѡ��ĳ��β�����
		cout << "��Ӱ�����ڻ����Է�ӳ��������ѡ��!" << endl;  // ����ѡ��
		cin >> time;
		getchar();
		getline(cin, name);
	}
	return MOVIE[i].SeatChoose(TurnOver);               // �û�ѡ����ĳһ���ε�Ӱ������ò���Ӱѡ��λ����
}

void ATVM::SetMovieInfoAll(const string& s1, const string& s2, const string& s3, 
		const string& s4, const string& s5)          
{	// Ϊÿ����Ӱ������Ϣ��������Ӱ��������ʱ�䡢�Լ���ͬ��λƱ��
	MOVIE[0].SetMovieInfoEach(s1);
	MOVIE[1].SetMovieInfoEach(s2);
	MOVIE[2].SetMovieInfoEach(s3);
	MOVIE[3].SetMovieInfoEach(s4);
	MOVIE[4].SetMovieInfoEach(s5);
	MOVIE[5].SetMovieInfoEach(s1);
	MOVIE[6].SetMovieInfoEach(s2);
	MOVIE[7].SetMovieInfoEach(s3);
	MOVIE[8].SetMovieInfoEach(s4);
	MOVIE[9].SetMovieInfoEach(s5);
	TicketSoldAllDay = 0;                                       // ������Ʊ��Ϊ0
	TurnOver = 0;                                               // Ӫҵ��Ϊ0
	nowPlaying = "";                                            // ��ǰ����Ϊ��
	cout << "��Ӱ��Ϣ�������" << endl;  // ��Ӱ��Ϣ�������
	cout << "�밴0�˳�" << endl;									// ѡ���˳�
	char choice;
	cin >> choice;
}

void ATVM::MovieList()                                  // ��ʾ���ղ��ŵ�Ӱ�б�
{
	int i;
	cout << "\nʱ��   " << "  ��Ӱ" << endl;
	for (i = 0; i < 10; i++)
		cout << MOVIE[i].GetShowTime() << "    " 
			<< MOVIE[i].GetMovieName() << endl;
}

void ATVM::ShowCurrentTime()                     // ��ʾ��ǰ����ʱ��
{
	char ch1[20], ch2[20];
	time(&now);
	struct tm *TM = localtime(&now);
	strftime(ch1, 20, "%x", TM);                 // ����������ʾ��ʽ
	strftime(ch2, 20, "%X", TM);                 // ����ʱ����ʾ��ʽ
	cout << "�����ǣ� " << ch1;
	cout << "����ʱ��Ϊ�� " << ch2 << endl;
}

int ATVM::GetCurrentTime()                   // �õ���ǰ����ʱ��
{ 
	char ch1[20], ch2[20];
	time(&now);
	struct tm *TM = localtime(&now);
	strftime(ch1, 20, "%x", TM);              // ����������ʾ��ʽ
	strftime(ch2, 20, "%X", TM);              // ����ʱ����ʾ��ʽ
	char temp[2];
	int hour;
	strncpy(temp, ch2, 2);
	hour = atoi(temp);
	return hour;                            // ����ʱ
}

void ATVM::SetNowPlaying()                 // ����ÿ��ĳһʱ��Ҫ���ŵĵ�Ӱ
{
	int hour = GetCurrentTime();
	if (hour >= 6 && hour <= 8)
		nowPlaying = MOVIE[0].GetMovieName();
	else if(hour >= 8 && hour < 10)
		nowPlaying = MOVIE[1].GetMovieName();
	else if(hour >= 10 && hour < 12)
		nowPlaying = MOVIE[2].GetMovieName();
	else if(hour >= 12 && hour < 14)
		nowPlaying = MOVIE[3].GetMovieName();
	else if(hour >= 14 && hour < 16)
		nowPlaying = MOVIE[4].GetMovieName();
	else if(hour >= 16 && hour < 18)
		nowPlaying = MOVIE[0].GetMovieName();
	else if(hour >= 18 && hour < 20)
		nowPlaying = MOVIE[1].GetMovieName();
	else if(hour >= 20 && hour < 22)
		nowPlaying = MOVIE[2].GetMovieName();
	else if(hour >= 22 && hour < 24)
		nowPlaying = MOVIE[3].GetMovieName();
	else if(hour >= 0 && hour < 2)
		nowPlaying = MOVIE[4].GetMovieName();
	else
		nowPlaying = "";
}

char ATVM::StaffOperator()                    // Ա������
{
	cout<<"*****************************************\n";
	cout << "��ӭ����Ա������: " << endl;
	cout << "1.��ѯ�����γ�Ʊ���" << endl;  // ѡ���б�
	cout << "2.��ѯ���ճ�Ʊ���" << endl;
	cout << "3.���õ�Ӱ��Ϣ" << endl;
	cout << "4.��ѯ����Ӫҵ��" << endl;
	cout << "5.�޸�����" << endl;
	cout << "0.�˳�" << endl;
	cout<<"*****************************************\n";
	int choice;
	int i, times;
	string s1, s2, s3, s4, s5;                            // ��������5����Ӱ���� 
	while (cin >> choice && (choice = toupper(choice))
		&& !(choice == 1 || choice == 2 || choice == 3 
		|| choice == 4 || choice == 5 || choice == 0)) 
		cout << "������ѡ��!" << endl;
	getchar();
	switch (choice) {
		case 1:                                        // �鿴ÿһ��ÿһ���εĳ�Ʊ���
			cout << "\n��Ӱ��           " << "            ��ӳʱ��:" <<"    ��Ʊ�����" << endl; 
			for (i = 0; i < 10; i++) 
				cout << MOVIE[i].GetMovieName() << "                    "
				    << MOVIE[i].GetShowTime() << "          " 
					<< MOVIE[i].TicketSold() << endl;
			oFile << "\n��Ӱ��           " << "            ��ӳʱ��:" <<"    ��Ʊ�����" << endl; 
			for (i = 0; i < 10; i++) 
				oFile << MOVIE[i].GetMovieName() << "                    "
				    << MOVIE[i].GetShowTime() << "          " 
					<< MOVIE[i].TicketSold() << endl;
			cout<<"�ļ��Ѵ���film.txt��"<<endl;
			break;
		case 2:                                        // �鿴�ܳ�Ʊ��
			cout << "���յ�ӰԺ�ܳ�Ʊ���� ";
			cout << GetTicketSoldAllDay() << endl;
			oFile << "���յ�ӰԺ�ܳ�Ʊ���� ";
			oFile << GetTicketSoldAllDay() << endl;
			cout<<"�ļ��Ѵ���film.txt��"<<endl;
			break;
		case 3:                                        // ���õ�Ӱ��Ϣ
			cout << "������5����Ӱ������: " << endl;

			getline(cin, s1);
			getline(cin, s2);
			getline(cin, s3);
			getline(cin, s4);
			getline(cin, s5);

			SetMovieInfoAll(s1, s2, s3, s4, s5);
			break;
		case 4:
			ShowTurnOver();                             // ��ʾӪҵ��
			break;
		case 5:                                       // ��������
			times = 3;
			cout << "����������: ";    // ����������
			long pwd;
			while (cin >> pwd && pwd != password && times != 1) {
				times--;
				cout << "�������!" << endl; 
				cout <<	"�㻹�� " << times  << "�λ��ᡣ ";
			}
			if (times == 1 && pwd != 123456) {
			  	cout << "������֤����!" << endl;
				cout << "0.����" << endl;
				cin >> choice;
			}
			else {
				cout << "�����µ�������: ";       // ����������
				cin >> password;
				cout << "�����ѱ�����" << endl;
				cout << "������Ϊ " << GetPassword() << endl;  // ��ʾ������
			    oFile << "�����ѱ�����" << endl;
				oFile << "������Ϊ " << GetPassword() << endl;  
				cout<<"�ļ��Ѵ���film.txt��"<<endl;
			}
			break;
		case 0: 			                             // �˳�
			break;            
	}
	if (choice != 0) {
		cout << "9.����" << endl;                     // ����Ա������
		cout << "0.�ص�����Ļ" << endl;        // ����������
		cin >> choice;
	}
	return choice;
}

int ATVM::ChooseMatch(MovieInfo* MOVIE, const string& time, const string& name)   
{   // �����ж��û�ѡ��ĳ����Ƿ����
	string TM;
	const char *ch2 = new char[20];
    int hour;
	char temp[2];
	for (int i = 0; i < 10; i++) {
		TM = MOVIE[i].GetShowTime();
		ch2 = time.c_str();
		strncpy(temp, ch2, 2);
	    hour = atoi(temp);
		if (MOVIE[i].GetShowTime() == time        // ѡ��ĳ���ʱ��͵�Ӱ���ƶ�ƥ��
			&& MOVIE[i].GetMovieName() == name 
			&& (hour >= GetCurrentTime() || 
			(hour >= 0 && hour <= 2 && hour < GetCurrentTime())))      // ѡ��ĳ��λ�δ����
			return i;
	}
	return -1;
}

int main()
{
	
	ATVM A("�����Ǵ���", "����ʷ����", "̩̹��˺�", "����������", "�ٶ��뼤��");
	while (1) {
		A.Initialize(); 
	}
	return 0;
}