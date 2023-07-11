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
	bool label;         // 座位是否已订标志
	double price;       // 该电影不同座位票价
public:
	Seat(): label(true), price(0) {}                // 构造函数
	void SetLabel(bool lb) { label = lb; }          // 设置该座位是否已被预订标记
	void SetPrice(double p) { price = p; }          // 设置该座位票价
	bool GetLabel() const { return label; }
	double GetPrice() const { return price; }       
};

class MovieInfo { 
private:
	string MovieName;				// 电影名
	string ShowTime;                // 场次
	double price[3];                // 3种不同票价
	int TotalTickets, LeftTickets;	// 总票数、剩余票数
	int SoldTickets;			    // 出票情况
	int TotalSeat, LeftSeat;		// 总座位数、剩余座位数
	int line, row;                  // 记录选择座位情况
	Seat S[10][10];                 // 座位图// 电影信息类，主要设置电影名，票价等
public:
	MovieInfo();                                    // 构造函数
	MovieInfo(const string &name, const string& t, int p1, int p2, int p3);

	void SetMovieInfoEach(const string &name);                // 设置电影信息，用于调用SetShowTime和SetPriceByPosition
    void SetShowTime(const string& t) { ShowTime = t; }       // 设置电影播放时间
    void SetPriceByPosition(double p1, double p2, double p3);  // 设置不同位置票价，分成三种不同票价

	string GetMovieName() const { return MovieName; }  // 得到电影名称
	string GetShowTime() const  { return ShowTime; }   // 得到播放时间

	void ShowSeat() const;                            // 显示座位情况
	bool SeatChoose(int& TurnOver);                   // 选择座位
	void ChooseResult() const;                        // 用户选择结果显示
	void Pay();                                       // 付款

	int SeatTotal() const { return TotalSeat; }       // 显示总座位数
	int SeatLeft() const { return LeftSeat; }         // 显示剩余座位数

	int TicketTotal() const { return TotalSeat; }     // 显示总票数
	int TicketSold() const { return SoldTickets; }    // 显示已售票数
	int TicketLeft() const { return LeftTickets; }    // 显示余票
		
};
MovieInfo::MovieInfo(): MovieName(" "), TotalTickets(0),       // 默认构造函数
		LeftTickets(0), SoldTickets(0), TotalSeat(0), LeftSeat(0), line(0), row(0)
{
}

MovieInfo::MovieInfo(const string &name, const string& t, int p1, int p2, int p3)
		: MovieName(name), TotalTickets(100), LeftTickets(100), SoldTickets(0), 
			TotalSeat(100), LeftSeat(100), line(0), row(0)
{
	SetShowTime(t);                                    // 显示当前时间
	SetPriceByPosition(p1, p2, p3);                    // 设置该部电影不同位置票价
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (i < 3)  
				S[i][j].SetPrice(price[0]);            // 设置每个座位票价，前30个座位票价为price[0]
			else if (i < 6)  
				S[i][j].SetPrice(price[1]);            // 中间30个座位票价price[1]
			else  
				S[i][j].SetPrice(price[2]);            // 最后40个座位票价price[2]
}

void MovieInfo::SetMovieInfoEach(const string &name)         // 设置电影信息
{
	MovieName = name;
	cout << "电影名称: " << MovieName << endl;
	TotalTickets = 100, LeftTickets = 100;   // 总票数、余票数
	SoldTickets = 0;                         // 初始化为0
	TotalSeat = 100, LeftSeat = 100;         // 总座位数、余下座位数
	line = 0, row = 0;

	string t;
	cout << "请设置放映时间：" << endl;
	cin >> t;
	SetShowTime(t);                          // 设置放映时间，这里每天放映两场
		
	int p1, p2, p3;
 	cout << "请分别输入前排座、中心座、后排座的票价：" << endl;
	cin >> p1 >> p2 >> p3;
	SetPriceByPosition(p1, p2, p3);                    // 设置不同位置票价，这里分成三种票价
		
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (i < 3)  
				S[i][j].SetPrice(price[0]);            // 设置每个座位票价，前30个座位票价为price[0]
			else if (i < 6)  
				S[i][j].SetPrice(price[1]);            // 中间30个座位票价price[1]
			else  
				S[i][j].SetPrice(price[2]);            // 最后40个座位票价price[2]
}

void MovieInfo::SetPriceByPosition(double p1, double p2, double p3)  // 设置不同位置票价，分成三种不同票价
{
	price[0] = p1;
	price[1] = p2;
	price[2] = p3;
}

void MovieInfo::ShowSeat() const                     // 显示座位情况
{
	int i;
	cout<<"座位表为："<<endl;
	for (i = 9; i >= 0; i--) {                      // 显示座位表
		for (int j = 0; j < 10; j++) 
			cout << "[" << i << "," << j << "]" << " ";
		cout << endl;
	}
	cout<<"各座位的票价为："<<endl;
	for (i = 9; i >= 0; i--) {                     // 显示每个座位价格
		for (int j = 0; j < 10; j++) 
			cout << S[i][j].GetPrice() << "   ";
		cout << endl;
	}
	cout<<"各座位出票情况：1为空座"<<endl;
	for (i = 9; i >= 0; i--) {                     // 显示该座位是否已预订
		for (int j = 0; j < 10; j++) 
			cout << S[i][j].GetLabel() << "   ";
		cout << endl; 
	}  
}

bool MovieInfo::SeatChoose(int& TurnOver)          // 为该部电影选择座位
{	
	cout << "该电影还有 " << TicketLeft() << " 张票剩余" << endl; 
	if (LeftTickets == 0) {                        // 该部电影票已售完
		cout << "对不起，电影票已售光." << endl;
		cout << "请选择其他场次的电影." << endl;   // 选择其他电影
		return false;
	}
	cout << "<<" << MovieName << ">>" << endl;
	ShowSeat();                                     // 显示座位情况
	int i, j;
	cout << "请选择座位: " << endl;   // 用户选择座位
	cin >> i >> j;
	while (S[i][j].GetLabel() == false) {    // 该座位已预订
		cout << "该座位已售出，请选择其他座位 \n";  // 选择其他座位
		ShowSeat();
		cin >> i >> j;
	}
	S[i][j].SetLabel(false);				// 座位已选择，记为false，不能再选择
	line = i;								// 记录选择的行
	row = j;								// 记录选择的列
	LeftTickets--;							// 余票减1
	LeftSeat--;								// 座位数减1
	SoldTickets++;							// 已售出加1
	cout << "恭喜您订票成功" << endl;
	ChooseResult();                   // 显示用户订票结果
	TurnOver += S[line][row].GetPrice();
	cout << "确认付款? "<< endl;// 提示付款
	cout<<"1.是    2.否"<<endl;
	int choice;
	cin >> choice;
	Pay();                            // 转到付款界面
	cout << "付款成功！" << endl;
	cout << "请按0回到主界面" << endl;  // 付款成功，提示返回主界面
	cin >> choice;
	return true;
}

void MovieInfo::ChooseResult() const   // 显示用户选择电影的信息，包括电影名、播放时间、座位和票价
{
	cout<<"*****************************************\n";
	cout << "电影信息: " << endl;
	cout << "电影名称: " << MovieName << endl;
	cout << "播放时间: " << ShowTime << endl;
	cout << "座位号: " << line << "排" << row << "列" << endl;
	cout << "票价为: " << S[line][row].GetPrice() << endl;
	cout<<"*****************************************\n";
	oFile<<"*****************************************\n";
	oFile << "电影信息: " << endl;
	oFile << "电影名称: " << MovieName << endl;
	oFile << "播放时间: " << ShowTime << endl;
	oFile << "座位号: " << line << "排" << row << "列" << endl;
	oFile << "票价为: " << S[line][row].GetPrice() << endl;
	oFile<<"*****************************************\n";
	cout<<"文件已存入film.txt中"<<endl;
}

void MovieInfo::Pay()               // 付款界面
{
	cout<<"*****************************************\n";
	cout << "请进入网上银行" << endl;   
	cout << "1.是     2.否" << endl;
	int choice;
	cin >> choice;
	cout<<"*****************************************\n";
	cout << "您已付款 " << S[line][row].GetPrice() << "元" << endl;  // 付款成功
	cout << "1.是     2.否" << endl;
	cin >> choice;
	cout<<"*****************************************\n";
}

class ATVM {
public:
	ATVM();                                                // 默认构造函数
	ATVM(const string& s1, const string& s2, const string& s3,   // 构造函数
		const string& s4, const string& s5);

	void Initialize();                                     // 初始化，显示给用户看的第一个界面

	bool Self_Help_Tickets(int& TurnOver);                 // 自助购票函数 

	void SetMovieInfoAll(const string& s1, const string& s2, const string& s3, 
		const string& s4, const string& s5);                 // 设置所有电影信息

	void MovieList();                                // 当天要播放电影列表
	
	void ShowCurrentTime();							 // 显示当前时间
    int GetCurrentTime();							 // 得到当前时间 

	int GetTicketSoldAllDay()  { return TicketSoldAllDay; }   // 当天已售票数总和

	void SetNowPlaying();                          // 设置要播放的电影

	char StaffOperator();                          // 工作人员设置界面

	int ChooseMatch(MovieInfo* MOVIE, const string& time, const string& name);  // 用户选择场次是否存在

	void ShowTurnOver()                       // 显示营业额
    { 
		cout << "今日营业额为： " << TurnOver << endl;
		oFile << "今日营业额为： " << TurnOver << endl;
		cout<<"文件已存入film.txt中"<<endl;
	}

	void BusinessState()                         // 营业状况介绍
	{
		cout << "本电影院营业时间为早六点到次日凌晨两点" << endl;
		cout << "每两个小时放映一场电影，请查询后购票" << endl;
	}

private:
	time_t now;
	MovieInfo MOVIE[10];
	string nowPlaying;
	long password;                 // 密码
	int TicketSoldAllDay;
	int TurnOver;                  // 营业额         
	long GetPassword() { return password; }
};

ATVM::ATVM()             // 默认构造函数
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
	password = 0;                                 // 密码初始值为0
	TicketSoldAllDay = 0;                         // 总售票数为0
	TurnOver = 0;                                 // 营业额为0
	nowPlaying = "";                             // 当前播放为空
}

ATVM::ATVM(const string& s1, const string& s2, const string& s3,   // 构造函数
		const string& s4, const string& s5) 
{   // 为每部电影设置信息，包括电影名、播放时间、以及不同座位票价
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
	password = 123456;                 // 密码初始值设为123456
	TicketSoldAllDay = 0;              // 总售票数为0
	TurnOver = 0;                      // 营业额为0
	nowPlaying = "";                   // 当前播放为空
}

void ATVM::Initialize()                       
{
	cout<<"********************************************************************************\n";
    cout<<"  C++面向对象程序设计  课程设计  12级计算计科学与技术1班  李畅  2012329620003    \n";
    cout<<"********************************************************************************\n";
	cout<<"****************************欢迎光临华元电影院**********************************"<<endl;
	ShowCurrentTime();                    // 显示当前日期时间
	SetNowPlaying();                      // 设置要播放的电影
	cout<<"*****************************************\n";
	cout << "今日上映" << endl;
	MovieList();                     // 显示当天要播放的电影及时间
	cout<<endl;
	cout << "此时播放: \n" << nowPlaying << endl;
	cout<<"*****************************************\n";
	cout << "请选择将要进行的操作: " << endl;
	cout << "1.购票  " << endl;     // 用户选项
	cout << "2.营业时间查询    " << endl;
	cout << "3.员工通道    " << endl;
	cout<<"*****************************************\n";
	int choice;
	int times;
	int hour;
	while (cin >> choice && (choice = toupper(choice))    
		&& !(choice == 1 || choice == 2 || choice == 3 )) 
		cout << "请重新选择!" << endl;   // 如果选择不正确则重新选择
	switch (choice) {
		case 1:                         // 用户选择购票
			hour = GetCurrentTime();
			if (hour >= 2 && hour < 6) {   // 营业时间不对，不能购票
				cout << "对不起，现在不是营业时间" << endl;
				cout << "0.返回" << endl; 
			cin >> choice;
			}
			else {
				while (!Self_Help_Tickets(TurnOver));  // 自助购票函数
				TicketSoldAllDay++;                    // 当天出售总票数加1
			}
			break;
		case 2:
			BusinessState();                   //  营业状况介绍
			cout << "0.返回" << endl;
			cin >> choice;
			break;
		case 3:                              // 员工通道
			times = 3;
			cout << "请输入密码: ";    // 需要输入密码，有3次机会
			long pwd;
			while (cin >> pwd && pwd != password && times != 1) {
				times--;
				cout << "密码错误!" << endl;
				cout <<	"你还有 " << times << " 次机会。 ";
			}
			if (times == 1 && pwd != 123456) {
				cout << "密码验证错误!" << endl;    // 次数到限，回到主界面
				cout << "0.返回" << endl;
				cin >> choice;
			}
			else {
				while (choice != 0) 
					choice = StaffOperator();        // 密码正确，进入员工界面
			}
			break;

	}
}

bool ATVM::Self_Help_Tickets(int& TurnOver)         // 自助购票界面
{
	MovieList();                                    // 显示今日播放电影列表
	cout << "请选择你想看的电影: " << endl;
	cout << "例如，输入如下 \"22:00 哈利波特\"" << endl;
	string time, name;                              // 用户选择的场次（包括名字、播放时间）  
	cin >> time;
    getchar();
	getline(cin, name);
	int i;
	while ((i = ChooseMatch(MOVIE, time, name)) == -1) {  // 用户选择的场次不存在
		cout << "电影不存在或者以放映，请重新选择!" << endl;  // 重新选择
		cin >> time;
		getchar();
		getline(cin, name);
	}
	return MOVIE[i].SeatChoose(TurnOver);               // 用户选择了某一场次电影，进入该部电影选座位界面
}

void ATVM::SetMovieInfoAll(const string& s1, const string& s2, const string& s3, 
		const string& s4, const string& s5)          
{	// 为每部电影设置信息，包括电影名、播放时间、以及不同座位票价
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
	TicketSoldAllDay = 0;                                       // 已售总票数为0
	TurnOver = 0;                                               // 营业额为0
	nowPlaying = "";                                            // 当前播放为空
	cout << "电影信息设置完毕" << endl;  // 电影信息设置完毕
	cout << "请按0退出" << endl;									// 选择退出
	char choice;
	cin >> choice;
}

void ATVM::MovieList()                                  // 显示今日播放电影列表
{
	int i;
	cout << "\n时间   " << "  电影" << endl;
	for (i = 0; i < 10; i++)
		cout << MOVIE[i].GetShowTime() << "    " 
			<< MOVIE[i].GetMovieName() << endl;
}

void ATVM::ShowCurrentTime()                     // 显示当前日期时间
{
	char ch1[20], ch2[20];
	time(&now);
	struct tm *TM = localtime(&now);
	strftime(ch1, 20, "%x", TM);                 // 设置日期显示格式
	strftime(ch2, 20, "%X", TM);                 // 设置时间显示格式
	cout << "现在是： " << ch1;
	cout << "北京时间为： " << ch2 << endl;
}

int ATVM::GetCurrentTime()                   // 得到当前日期时间
{ 
	char ch1[20], ch2[20];
	time(&now);
	struct tm *TM = localtime(&now);
	strftime(ch1, 20, "%x", TM);              // 设置日期显示格式
	strftime(ch2, 20, "%X", TM);              // 设置时间显示格式
	char temp[2];
	int hour;
	strncpy(temp, ch2, 2);
	hour = atoi(temp);
	return hour;                            // 返回时
}

void ATVM::SetNowPlaying()                 // 设置每天某一时刻要播放的电影
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

char ATVM::StaffOperator()                    // 员工界面
{
	cout<<"*****************************************\n";
	cout << "欢迎进入员工界面: " << endl;
	cout << "1.查询各场次出票情况" << endl;  // 选择列表
	cout << "2.查询今日出票情况" << endl;
	cout << "3.设置电影信息" << endl;
	cout << "4.查询今日营业额" << endl;
	cout << "5.修改密码" << endl;
	cout << "0.退出" << endl;
	cout<<"*****************************************\n";
	int choice;
	int i, times;
	string s1, s2, s3, s4, s5;                            // 用于设置5部电影名字 
	while (cin >> choice && (choice = toupper(choice))
		&& !(choice == 1 || choice == 2 || choice == 3 
		|| choice == 4 || choice == 5 || choice == 0)) 
		cout << "请重新选择!" << endl;
	getchar();
	switch (choice) {
		case 1:                                        // 查看每一天每一场次的出票情况
			cout << "\n电影名           " << "            上映时间:" <<"    售票情况：" << endl; 
			for (i = 0; i < 10; i++) 
				cout << MOVIE[i].GetMovieName() << "                    "
				    << MOVIE[i].GetShowTime() << "          " 
					<< MOVIE[i].TicketSold() << endl;
			oFile << "\n电影名           " << "            上映时间:" <<"    售票情况：" << endl; 
			for (i = 0; i < 10; i++) 
				oFile << MOVIE[i].GetMovieName() << "                    "
				    << MOVIE[i].GetShowTime() << "          " 
					<< MOVIE[i].TicketSold() << endl;
			cout<<"文件已存入film.txt中"<<endl;
			break;
		case 2:                                        // 查看总出票数
			cout << "今日电影院总出票数： ";
			cout << GetTicketSoldAllDay() << endl;
			oFile << "今日电影院总出票数： ";
			oFile << GetTicketSoldAllDay() << endl;
			cout<<"文件已存入film.txt中"<<endl;
			break;
		case 3:                                        // 设置电影信息
			cout << "请输入5部电影的名字: " << endl;

			getline(cin, s1);
			getline(cin, s2);
			getline(cin, s3);
			getline(cin, s4);
			getline(cin, s5);

			SetMovieInfoAll(s1, s2, s3, s4, s5);
			break;
		case 4:
			ShowTurnOver();                             // 显示营业额
			break;
		case 5:                                       // 更改密码
			times = 3;
			cout << "请输入密码: ";    // 输入老密码
			long pwd;
			while (cin >> pwd && pwd != password && times != 1) {
				times--;
				cout << "密码错误!" << endl; 
				cout <<	"你还有 " << times  << "次机会。 ";
			}
			if (times == 1 && pwd != 123456) {
			  	cout << "密码验证错误!" << endl;
				cout << "0.返回" << endl;
				cin >> choice;
			}
			else {
				cout << "请输新的入密码: ";       // 输入新密码
				cin >> password;
				cout << "密码已被更改" << endl;
				cout << "新密码为 " << GetPassword() << endl;  // 显示新密码
			    oFile << "密码已被更改" << endl;
				oFile << "新密码为 " << GetPassword() << endl;  
				cout<<"文件已存入film.txt中"<<endl;
			}
			break;
		case 0: 			                             // 退出
			break;            
	}
	if (choice != 0) {
		cout << "9.返回" << endl;                     // 返回员工界面
		cout << "0.回到主屏幕" << endl;        // 返回主界面
		cin >> choice;
	}
	return choice;
}

int ATVM::ChooseMatch(MovieInfo* MOVIE, const string& time, const string& name)   
{   // 用于判断用户选择的场次是否存在
	string TM;
	const char *ch2 = new char[20];
    int hour;
	char temp[2];
	for (int i = 0; i < 10; i++) {
		TM = MOVIE[i].GetShowTime();
		ch2 = time.c_str();
		strncpy(temp, ch2, 2);
	    hour = atoi(temp);
		if (MOVIE[i].GetShowTime() == time        // 选择的场次时间和电影名称都匹配
			&& MOVIE[i].GetMovieName() == name 
			&& (hour >= GetCurrentTime() || 
			(hour >= 0 && hour <= 2 && hour < GetCurrentTime())))      // 选择的场次还未播放
			return i;
	}
	return -1;
}

int main()
{
	
	ATVM A("纳尼亚传奇", "怪物史莱克", "泰坦尼克号", "复仇者联盟", "速度与激情");
	while (1) {
		A.Initialize(); 
	}
	return 0;
}