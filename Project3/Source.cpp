#include <SFML\Graphics.hpp>
#include <cmath>
#include <iostream>
#include<fstream>
#include<SFML/Audio/Music.hpp>
#include <SFML/Audio/SoundStream.hpp>
#include<SFML/Network.hpp>
#include<SFML/Network/Socket.hpp>
#include<SFML/System.hpp>

sf::UdpSocket socket;
char data2[1] = { 'q' };
std::size_t received;
sf::IpAddress sender;
sf::IpAddress sara = "169.254.181.131";
unsigned short port;
unsigned short port2 = 54000;
bool ft = false;
char talareceive[5];
char mahyasend[5];
char sarareceive[5];
char raanareceive[5];
char maryamreceive[5];
char tir[2];
char finalshomare[1];
int finalemtiaz[1];
std::string name;

int a = 0, a1 = 0;
//static int xx = 0;


sf::VideoMode Vmode(4000, 200, 32);
sf::RenderWindow Window(Vmode, "JT");
sf::Texture texturem;
sf::Texture texturem1;
sf::Music music;
sf::Texture do0;
sf::Texture do1;
sf::Texture do2;
sf::Texture do3;
sf::Texture do4;
sf::Sprite sdo0;
sf::Sprite sdo1;
sf::Sprite sdo2;
sf::Sprite sdo3;
sf::Sprite sdo4;
int doshman = 5;
void doshmanmin(){
	doshman--;
}
void doshmanaks(){
	if (5 - doshman == 1){
		if (!do4.loadFromFile("i.png"))
			std::cerr << "imorde";
		sdo4.setTexture(do4);
	}
	if (5 - doshman == 2){
		if (!do3.loadFromFile("i.png"))
			std::cerr << "i1morde";
		sdo3.setTexture(do3);
	}
	if (5 - doshman == 3){
		if (!do2.loadFromFile("i.png"))
			std::cerr << "i2morde";
		sdo2.setTexture(do2);
	}
	if (5 - doshman == 4){
		if (!do3.loadFromFile("i.png"))
			std::cerr << "i3morde";
		sdo3.setTexture(do3);
	}
	if (5 - doshman == 5){
		if (!do4.loadFromFile("i.png"))
			std::cerr << "i4morde";
		sdo4.setTexture(do4);
	}
}

class JT{
	friend bool enemycheck();
	friend void shelik();
	friend bool boardcheck();
	sf::RectangleShape line;
	sf::Texture texture;
	sf::Texture joon;
	sf::Texture joon1;
	sf::Texture joon2;
	sf::Texture s0;
	sf::Texture s1;
	sf::Texture s2;
	sf::Sprite sjoon;
	sf::Sprite sjoon1;
	sf::Sprite sjoon2;
	sf::Sprite ss0;
	sf::Sprite ss1;
	sf::Sprite ss2;
	sf::Sprite jt;
	sf::View view2;
	//	sf::Texture texture;
	//sf::Sprite jt;
	float xJT;
	float yJT;
	int Joon;
	int star;
	int mode;
public:
	JT(float a, float b, int d){
		//tup.setTexture(texturet);
		//xx = 0;
		mode = d;
		jt.setOrigin(369 / 2, 188 / 2);
		std::cerr << "construct!\n";
		if (!texture.loadFromFile("image.png"))
			std::cerr << "load Image failed in class";
		jt.setTexture(texture);
		if (!joon.loadFromFile("joon1.png"))
			std::cerr << "joon1";
		sjoon.setTexture(joon);
		if (!joon1.loadFromFile("joon1.png"))
			std::cerr << "joon2";
		sjoon1.setTexture(joon1);
		if (!joon2.loadFromFile("joon1.png"))
			std::cerr << "joon3";
		sjoon2.setTexture(joon2);
		if (!s0.loadFromFile("star.png"))
			std::cerr << "star0";
		ss0.setTexture(s0);
		if (!s1.loadFromFile("star.png"))
			std::cerr << "star1";
		ss1.setTexture(s1);
		if (!s2.loadFromFile("star.png"))
			std::cerr << "star2";
		ss2.setTexture(s2);
		xJT = a;
		yJT = b;
		Joon = 300;
		star = 0;
		jt.setPosition(a, b);
		sjoon.setPosition(90, 60);
		sjoon1.setPosition(250, 60);
		sjoon2.setPosition(410, 60);
		ss0.setPosition(90, 450);
		ss1.setPosition(250, 450);
		ss2.setPosition(410, 450);
		line.setPosition(90, 600);
		//Window.draw(jt);
	}
	void drawj()
	{
		Window.draw(jt);
	}
	void drawjoon(){

		//view2.reset(sf::FloatRect(20, 5, 350, 200));
		//view2.setViewport(sf::FloatRect(1000, 50, 300, 500));
		//Window.setView(view2);
		Window.draw(sjoon);
		Window.draw(sjoon1);
		Window.draw(sjoon2);
		Window.draw(ss0);
		Window.draw(ss1);
		Window.draw(ss2);
		Window.draw(line);
	}
	float getx(){
		return jt.getPosition().x;
	}
	float gety(){
		return jt.getPosition().y;
	}
	void setxy(float a, float b){
		jt.setPosition(jt.getPosition().x + a, jt.getPosition().y + b);
	}
	void marg(std::string a, int b){
		jt.setPosition(-8000, -8000);
		std::ofstream out("output.txt");
		out << a << b;
		out.close();
		mahyasend[4] = 'm';
	}
	void rotate(float a)
	{
		jt.rotate(a);
	}

	void settrotate()
	{
		jt.setRotation(0);
	}
	void setTJ()
	{

		if (mode == 0)
			jt.setTexture(texturem);
		else
			jt.setTexture(texturem1);

	}

	int getjoon(){
		return Joon;
	}
	void minusjoon(int c){
		Joon = Joon - c;
	}
	void starplus(int c){
		star = star + c;
	}
	int getstar(){
		return star;
	}
	/*void setdoshman(int b){
	doshman = b;
	}
	void doshmanmin(){
	doshman--;
	}*/
	void joonaks(int a){
		if (a == 0){
			if (!joon.loadFromFile("joon.png"))
				std::cerr << "joon1b";
			sjoon.setTexture(joon);
		}
		if (a == 1){
			if (!joon1.loadFromFile("joon.png"))
				std::cerr << "joon2b";
			sjoon1.setTexture(joon1);
		}
		if (a == 2){
			if (!joon2.loadFromFile("joon.png"))
				std::cerr << "joon3b";
			sjoon2.setTexture(joon2);
		}
	}
	void staraks(int a){
		if (a == 1){
			if (!s0.loadFromFile("star1.png"))
				std::cerr << "sstar1";
			ss0.setTexture(s0);
		}
		if (a == 2){
			if (!s1.loadFromFile("star1.png"))
				std::cerr << "sstar2";
			ss1.setTexture(s1);
		}
		if (a == 3){
			if (!s2.loadFromFile("star1.png"))
				std::cerr << "sstar3";
			ss2.setTexture(s2);
		}
	}

};
class Tup{
	friend void shelik();
	sf::Texture texture;
	sf::Sprite tup;
	float xtup;
	float ytup;
	int modee;
	int xx;
public:
	void drawt()
	{
		Window.draw(tup);
	}
	float getx(){
		return tup.getPosition().x;
	}
	float gety(){
		return tup.getPosition().y;
	}
	void setxy(float a, float b){
		tup.setPosition(tup.getPosition().x + a, tup.getPosition().y + b);
	}
	void setnew(float a, float b){
		tup.setPosition(a, b);
	}
	void settup(float a, float b)
	{
		if (modee == 1)
		{
			if (!texture.loadFromFile("tir1.png"))
				std::cerr << "textue 1 gule";
		}
		if (modee == 2)
		{
			if (!texture.loadFromFile("tir2.png"))
				std::cerr << "textue 2 gule";

		}
		if (modee == 3){
			if (!texture.loadFromFile("tir3.png"))
				std::cerr << "textue 3 gule";

		}
		tup.setTexture(texture);

		tup.setPosition(a, b);
	}
	void setmode(int a){
		modee = a;
	}
	Tup(){
		tup.setOrigin(369 / 2, 188 / 2);
		tup.setPosition(-800, -800);
		xx = 0;
	}
	/*~Tup(){

	}*/
	void Deletetup(){
		tup.setPosition(-800, -800);
	}
	void setxx(int a)
	{
		xx = a;
	}
	int getxx()
	{
		return xx;
	}
};

JT hehe(50, 50, 0);
JT hehe1(2100, 1600, 1);
//sf::RectangleShape rectangle(sf::Vector2f(500, 40));
//sf::RectangleShape rectanglez(sf::Vector2f(500, 40));
Tup *gule = new Tup;
Tup *gule1 = new Tup;
bool up = true, down = true, right = true, left = true;
void ab_marz(){
	if (hehe.getx() > 200 && hehe.getx()<2000 && hehe.gety()>1200 && hehe.gety() < 2000)
		down = false;
	else if (hehe.getx() > 2200 && hehe.getx()<3600 && hehe.gety()>1400 && hehe.gety() < 2000)
		down = false;
	else
		down = true;
	if (hehe.getx() > 200 && hehe.getx()<2000 && hehe.gety()>2000 && hehe.gety() < 2020)
		up = false;
	else if (hehe.getx() > 2200 && hehe.getx()<4000 && hehe.gety()>2000 && hehe.gety() < 2080)
		up = false;
	else
		up = true;
}

bool b = 1, b1 = 1;
bool count = 1;
bool count1 = 1;

bool boardcheck(float e, float f, JT juje, Tup *gulee){
	if (gulee->getxx() % 3 == 0){
		if (a == 0)
		{
			if ((juje.getx() - e) > 400)
				return false;
			else
				return true;
		}
		else if (a == 1)
		{
			if ((e - juje.getx()) > 400)
				return false;
			else
				return true;
		}
		else if (a == 2)
		{
			if ((juje.gety() - f) > 400)
				return false;
			else
				return true;
		}
		else if (a == 3)
		{
			if ((f - juje.gety()) > 400)
				return false;
			else
				return true;
		}
	}
	if (gulee->getxx() % 3 == 1){
		if (a == 0)
		{
			if ((juje.getx() - e) > 600)
				return false;
			else
				return true;
		}
		else if (a == 1)
		{
			if ((e - juje.getx()) > 600)
				return false;
			else
				return true;
		}
		else if (a == 2)
		{
			if ((juje.gety() - f) > 600)
				return false;
			else
				return true;
		}
		else if (a == 3)
		{
			if ((f - juje.gety()) > 600)
				return false;
			else
				return true;
		}
	}
	if (gulee->getxx() % 3 == 2){
		if (a == 0)
		{
			if ((juje.getx() - e) > 800)
				return false;
			else
				return true;
		}
		else if (a == 1)
		{
			if ((e - juje.getx()) > 800)
				return false;
			else
				return true;
		}
		else if (a == 2)
		{
			if ((juje.gety() - f) > 800)
				return false;
			else
				return true;
		}
		else if (a == 3)
		{
			if ((f - juje.gety()) > 800)
				return false;
			else
				return true;
		}
	}
}

/*bool enemycheck()
{
if (hehe.gety() - hehe.getx() < 117 || hehe.getx() - hehe.gety() < 117)
return false;
return true;
}
*/
void shelik(JT juje, Tup *gulee)
{
	float mogheiata = 0;
	float mogheiatb = 0;
	if (b == 0)
	{
		mogheiata = juje.getx();
		mogheiatb = juje.gety();
		//gule.setPosition(hehe.getx(), hehe.gety());
		b = 1;
	}
	bool c = boardcheck(gulee->getx(), gulee->gety(), juje, gulee);
	if (c == true){
		if (gulee->getxx() % 3 == 0){
			if (a == 0)
				gulee->setxy(-50, 0);
			else if (a == 1)
				gulee->setxy(50, 0);
			else if (a == 2)
				gulee->setxy(0, -50);
			else if (a == 3)
				gulee->setxy(0, 50);
		}
		if (gulee->getxx() % 3 == 1){
			if (a == 0)
				gulee->setxy(-70, 0);
			else if (a == 1)
				gulee->setxy(70, 0);
			else if (a == 2)
				gulee->setxy(0, -70);
			else if (a == 3)
				gulee->setxy(0, 70);
		}
		if (gulee->getxx() % 3 == 2){
			if (a == 0)
				gulee->setxy(-70, 0);
			else if (a == 1)
				gulee->setxy(70, 0);
			else if (a == 2)
				gulee->setxy(0, -70);
			else if (a == 3)
				gulee->setxy(0, 70);
		}
	}
	else
	{
		gulee->Deletetup();
		count = 1;
		return;
	}
	gulee->drawt();
	//Window.draw(gule);
}

bool boardcheck1(float e, float f, JT juje, Tup *gulee){
	if (gulee->getxx() % 3 == 0){
		if (a == 0)
		{
			if ((juje.getx() - e) > 400)
				return false;
			else
				return true;
		}
		else if (a1 == 1)
		{
			if ((e - juje.getx()) > 400)
				return false;
			else
				return true;
		}
		else if (a1 == 2)
		{
			if ((juje.gety() - f) > 400)
				return false;
			else
				return true;
		}
		else if (a1 == 3)
		{
			if ((f - juje.gety()) > 400)
				return false;
			else
				return true;
		}
	}
	if (gulee->getxx() % 3 == 1){
		if (a1 == 0)
		{
			if ((juje.getx() - e) > 600)
				return false;
			else
				return true;
		}
		else if (a1 == 1)
		{
			if ((e - juje.getx()) > 600)
				return false;
			else
				return true;
		}
		else if (a1 == 2)
		{
			if ((juje.gety() - f) > 600)
				return false;
			else
				return true;
		}
		else if (a1 == 3)
		{
			if ((f - juje.gety()) > 600)
				return false;
			else
				return true;
		}
	}
	if (gulee->getxx() % 3 == 2){
		if (a1 == 0)
		{
			if ((juje.getx() - e) > 800)
				return false;
			else
				return true;
		}
		else if (a1 == 1)
		{
			if ((e - juje.getx()) > 800)
				return false;
			else
				return true;
		}
		else if (a1 == 2)
		{
			if ((juje.gety() - f) > 800)
				return false;
			else
				return true;
		}
		else if (a1 == 3)
		{
			if ((f - juje.gety()) > 800)
				return false;
			else
				return true;
		}
	}
}

/*bool enemycheck1()
{
if (hehe.gety() - hehe.getx() < 117 || hehe.getx() - hehe.gety() < 117)
return false;
return true;
}
*/
void shelik1(JT juje, Tup *gulee)
{
	float mogheiata = 0;
	float mogheiatb = 0;
	if (b1 == 0)
	{
		mogheiata = juje.getx();
		mogheiatb = juje.gety();
		//gule.setPosition(hehe.getx(), hehe.gety());
		b1 = 1;
	}
	bool c = boardcheck1(gulee->getx(), gulee->gety(), juje, gulee);
	if (c == true){
		if (gulee->getxx() % 3 == 0){
			if (a1 == 0)
				gulee->setxy(-50, 0);
			else if (a1 == 1)
				gulee->setxy(50, 0);
			else if (a1 == 2)
				gulee->setxy(0, -50);
			else if (a1 == 3)
				gulee->setxy(0, 50);
		}
		if (gulee->getxx() % 3 == 1){
			if (a1 == 0)
				gulee->setxy(-70, 0);
			else if (a1 == 1)
				gulee->setxy(70, 0);
			else if (a1 == 2)
				gulee->setxy(0, -70);
			else if (a1 == 3)
				gulee->setxy(0, 70);
		}
		if (gulee->getxx() % 3 == 2){
			if (a1 == 0)
				gulee->setxy(-70, 0);
			else if (a1 == 1)
				gulee->setxy(70, 0);
			else if (a1 == 2)
				gulee->setxy(0, -70);
			else if (a1 == 3)
				gulee->setxy(0, 70);
		}
	}
	else
	{
		gulee->Deletetup();
		count1 = 1;
		return;
	}
	gulee->drawt();
	//Window.draw(gule);
}

void tala(){

	if (socket.bind(54000) != sf::Socket::Done)
	{
		std::cerr << "error1" << std::endl;
	}


	std::cout << talareceive << std::endl;
	while (Window.isOpen())
	{

		if (socket.receive(talareceive, 5, received, sender, port) != sf::Socket::Done)
		{
			std::cerr << "erroooooor recieve" << std::endl;
		}

		if (talareceive[4] == 'm' && talareceive[1] != mahyasend[1]){
			doshmanmin();
			doshmanaks();
			hehe1.marg(name, hehe1.getstar());
			talareceive[4] = 'v';
		}

		if (talareceive[1] != mahyasend[1]){

			if (talareceive[3] == 'z' && talareceive[2] == mahyasend[1]){
				hehe.starplus(10);
				std::cout << hehe.getstar() << std::endl;
				if (hehe.getstar() >= 100)
					hehe.staraks(1);
				if (hehe.getstar() >= 200)
					hehe.staraks(2);
				if (hehe.getstar() >= 0)
					hehe.staraks(3);

			}
			else if (talareceive[3] == 'h' && talareceive[2] == mahyasend[1]) {
				hehe.starplus(20);
				std::cout << hehe.getstar() << std::endl;
				if (hehe.getstar() >= 100)
					hehe.staraks(1);
				if (hehe.getstar() >= 200)
					hehe.staraks(2);
				if (hehe.getstar() >= 0)
					hehe.staraks(3);

			}
			else if (talareceive[3] == 'f' && talareceive[2] == mahyasend[1]) {
				hehe.starplus(30);
				std::cout << hehe.getstar() << std::endl;
				if (hehe.getstar() >= 100)
					hehe.staraks(1);
				if (hehe.getstar() >= 200)
					hehe.staraks(2);
				if (hehe.getstar() >= 0)
					hehe.staraks(3);
			}



			if (talareceive[0] == 'l')
			{
				//mode = 0;
				if (a1 != 0)
				{
					if (!texturem1.loadFromFile("image.png"))
						std::cout << "tooye thread harekate khodam" << std::endl;
					hehe1.setTJ();
				}
				hehe1.setxy(-10, 0);
				a1 = 0;
			}
			if (talareceive[0] == 'x')
			{
				//std::cout << xx;
				gule1->setxx(gule1->getxx() + 1);
				//xx = 1;

			}
			if (talareceive[0] == '0'){
				//if (!texture12.loadFromFile("tir.png")){
				gule1->setmode(1);
				gule1->settup(hehe1.getx(), hehe1.gety());
				//	return 1;
				//}


				if (enemycheck() == false){

					std::cout << hehe.getjoon() << "    " << enemycheck() << std::endl;
					//hehe.minusjoon((gule1->getxx() % 3) * 10 + 10);
					hehe.starplus((gule1->getxx() % 3) * 10 + 10);
					if (hehe.getjoon() <= 200)
						hehe.joonaks(2);
					if (hehe.getjoon() <= 100)
						hehe.joonaks(1);
					if (hehe.getjoon() <= 0)
						hehe.joonaks(0);
					//if (hehe.getstar() == 300 || hehe.getstar() == 600 || hehe.getstar() == 900)
					//hehe.staraks(hehe.getstar() / 300);
					if (hehe.getjoon() <= 0){
						doshmanmin();
						doshmanaks();
						hehe.marg(name, hehe.getstar());
					}
					//be man tir zadan chek kardam ke behem khorde chek kardam ke kodoom tire
					if (talareceive[0] == '0' && talareceive[1] != mahyasend[1]){
						hehe.minusjoon(10);
						mahyasend[3] = 'z';
						mahyasend[2] = talareceive[1];

						if (socket.send(mahyasend, 5, sara, port2) != sf::Socket::Done)
						{
							std::cerr << "error sending" << std::endl;
						}

					}
					if (talareceive[0] == '1' && talareceive[1] != mahyasend[1]){
						hehe.minusjoon(20);
						mahyasend[3] = 'h';
						mahyasend[2] = talareceive[1];

						if (socket.send(mahyasend, 5, sara, port2) != sf::Socket::Done)
						{
							std::cerr << "error sending" << std::endl;
						}

					}
					if (talareceive[0] == '2' && talareceive[1] != mahyasend[1]){
						hehe.minusjoon(30);
						mahyasend[3] = 'f';
						mahyasend[2] = talareceive[1];

						if (socket.send(mahyasend, 5, sara, port2) != sf::Socket::Done)
						{
							std::cerr << "error sending" << std::endl;
						}

					}

				}



			}
			if (talareceive[0] == '1'){
				//if (!texture12.loadFromFile("tir1.png")){
				gule1->setmode(2);
				gule1->settup(hehe1.getx(), hehe1.gety());

				if (enemycheck() == false){

					std::cout << hehe.getjoon() << "    " << enemycheck() << std::endl;
					//hehe.minusjoon((gule1->getxx() % 3) * 10 + 10);
					hehe.starplus((gule1->getxx() % 3) * 10 + 10);
					if (hehe.getjoon() == 100 || hehe.getjoon() == 200 || hehe.getjoon() == 0)
						hehe.joonaks(hehe.getjoon() % 100);
					//if (hehe.getstar() == 300 || hehe.getstar() == 600 || hehe.getstar() == 900)
					//hehe.staraks(hehe.getstar() / 300);
					if (hehe.getjoon() == 0){
						doshmanmin();
						doshmanaks();
						hehe.marg(name, hehe.getstar());
					}
					//be man tir zadan chek kardam ke behem khorde chek kardam ke kodoom tire
					if (talareceive[0] == '0' && talareceive[1] != mahyasend[1]){
						hehe.minusjoon(10);
						mahyasend[3] = 'z';
						mahyasend[2] = talareceive[1];

						if (socket.send(mahyasend, 5, sara, port2) != sf::Socket::Done)
						{
							std::cerr << "error sending" << std::endl;
						}
						mahyasend[3] = 'v';

					}
					if (talareceive[0] == '1' && talareceive[1] != mahyasend[1]){
						hehe.minusjoon(20);
						mahyasend[3] = 'h';
						mahyasend[2] = talareceive[1];

						if (socket.send(mahyasend, 5, sara, port2) != sf::Socket::Done)
						{
							std::cerr << "error sending" << std::endl;
						}
						mahyasend[3] = 'v';

					}
					if (talareceive[0] == '2' && talareceive[1] != mahyasend[1]){
						hehe.minusjoon(30);
						mahyasend[3] = 'f';
						mahyasend[2] = talareceive[1];

						if (socket.send(mahyasend, 5, sara, port2) != sf::Socket::Done)
						{
							std::cerr << "error sending" << std::endl;
						}
						mahyasend[3] = 'v';

					}

				}


			}
			if (talareceive[0] == '2'){
				//if (!texture12.loadFromFile("tir2.png")){
				gule1->setmode(3);
				gule1->settup(hehe1.getx(), hehe1.gety());

				if (enemycheck() == false){

					std::cout << hehe.getjoon() << "    " << enemycheck() << std::endl;
					//hehe.minusjoon((gule1->getxx() % 3) * 10 + 10);
					hehe.starplus((gule1->getxx() % 3) * 10 + 10);
					if (hehe.getjoon() == 100 || hehe.getjoon() == 200 || hehe.getjoon() == 0)
						hehe.joonaks(hehe.getjoon() % 100);
					//if (hehe.getstar() == 300 || hehe.getstar() == 600 || hehe.getstar() == 900)
					//hehe.staraks(hehe.getstar() / 300);
					if (hehe.getjoon() == 0){
						doshmanmin();
						doshmanaks();
						hehe.marg(name, hehe.getstar());
					}
					//be man tir zadan chek kardam ke behem khorde chek kardam ke kodoom tire
					if (talareceive[0] == '0' && talareceive[1] != mahyasend[1]){
						hehe.minusjoon(10);
						mahyasend[3] = 'z';
						mahyasend[2] = talareceive[1];

						if (socket.send(mahyasend, 5, sara, port2) != sf::Socket::Done)
						{
							std::cerr << "error sending" << std::endl;
						}

					}
					if (talareceive[0] == '1' && talareceive[1] != mahyasend[1]){
						hehe.minusjoon(20);
						mahyasend[3] = 'h';
						mahyasend[2] = talareceive[1];

						if (socket.send(mahyasend, 5, sara, port2) != sf::Socket::Done)
						{
							std::cerr << "error sending" << std::endl;
						}

					}
					if (talareceive[0] == '2' && talareceive[1] != mahyasend[1]){
						hehe.minusjoon(30);
						mahyasend[3] = 'f';
						mahyasend[2] = talareceive[1];

						if (socket.send(mahyasend, 5, sara, port2) != sf::Socket::Done)
						{
							std::cerr << "error sending" << std::endl;
						}

					}

				}

			}
			//gule.setTexture(texture12);

			count1 = 0;
			b1 = 0;


			if (talareceive[0] == 'r')
			{
				//mode = 0;
				if (a1 != 1)
				{
					if (!texturem1.loadFromFile("image4.png"))
						std::cout << "tooye thread harekate khodam" << std::endl;
					//Sprite.setTexture(texture);
					hehe1.setTJ();
				}
				//hehe.rotate(10);
				//Sprite.move(+10, 0);
				hehe1.setxy(10, 0);
				//hehe.aks(2);
				a1 = 1;
			}
			if (talareceive[0] == 'u')
			{
				//mode = 0;
				if (a1 != 2)
				{
					if (!texturem1.loadFromFile("image5.png"))
						return;
					//hehe.rotate(-90);
					//hehe.aks(3);
					hehe1.setTJ();
				}
				hehe1.setxy(0, -10);
				a1 = 2;
			}
			if (talareceive[0] == 'd')
			{
				if (a1 != 2)
				{
					if (!texturem1.loadFromFile("image5.png"))
						return;
					//hehe.rotate(-90);
					//hehe.aks(3);
					hehe1.setTJ();
				}
				hehe1.setxy(0, +10);
				//hehe.rotate(-10);
				a1 = 3;
			}

			else if (talareceive[0] == 'i')
			{
				hehe1.rotate(10);
			}
			else if (talareceive[0] == 'o')
			{
				hehe1.rotate(-10);
			}



		}
	}
}
bool enemycheck()
{
	if ((hehe.getx() - gule1->getx() < 300 && hehe.gety() - gule1->gety() < 300 &&
		hehe.gety() - gule1->gety() >= -300 && hehe.getx() - gule1->getx() >= -300) ||
		(gule1->getx() - hehe.getx() < 300 && gule1->gety() - hehe.gety() < 300 &&
		gule1->getx() - hehe.getx() >= -300 && gule1->getx() - hehe.getx() >= -300))
		return false;
	return true;
}
void mahya(){


	ab_marz();



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (hehe.getx() > 200) && left == true)
	{
		//mode = 0;
		//mode = 0;
		//hehe.settrotate();
		if (a != 0)
		{
			if (!texturem.loadFromFile("image.png"))
				return;
			hehe.setTJ();
		}
		hehe.setxy(-10, 0);
		a = 0;
		mahyasend[0] = 'l';
		if (socket.send(mahyasend, 5, sara, port2) != sf::Socket::Done)
		{
			std::cerr << "error sending" << std::endl;
		}
		mahyasend[0] = 'v';

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{

		gule->setxx(gule->getxx() + 1);
		/*mahyasend[0] = 'x';
		if (socket.send(mahyasend, 2, sara, port2) != sf::Socket::Done)
		{
		std::cerr << "error sending" << std::endl;
		}*/


	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{



		if (gule->getxx() % 3 == 0){


			gule->setmode(1);
			mahyasend[0] = '0';
			if (socket.send(mahyasend, 5, sara, port2) != sf::Socket::Done)
			{
				std::cerr << "error sending" << std::endl;
			}
			std::cout << mahyasend[0] << std::endl;
			mahyasend[0] = 'v';

		}

		else if (gule->getxx() % 3 == 1){
			std::cout << mahyasend << std::endl;
			gule->setmode(2);
			mahyasend[0] = '1';
			if (socket.send(mahyasend, 5, sara, port2) != sf::Socket::Done)
			{
				std::cerr << "error sending" << std::endl;
			}

			mahyasend[0] = 'v';

		}
		else if (gule->getxx() % 3 == 2){

			gule->setmode(3);
			mahyasend[0] = '2';

			if (socket.send(mahyasend, 5, sara, port2) != sf::Socket::Done)
			{
				std::cerr << "error sending" << std::endl;
			}
			mahyasend[0] = 'v';

		}


		count = 0;
		b = 0;
		gule->settup(hehe.getx(), hehe.gety());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && hehe.getx()<6000 && right == true)
	{
		mahyasend[0] = 'r';
		if (socket.send(mahyasend, 5, sara, port2) != sf::Socket::Done)
		{
			std::cerr << "error sending" << std::endl;
		}
		mahyasend[0] = 'v';
		if (a != 1)
		{
			if (!texturem.loadFromFile("image4.png"))
				return;
			hehe.setTJ();
		}
		hehe.setxy(10, 0);
		//a = 1;
		a = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && hehe.gety()>120 && up == true)
	{
		mahyasend[0] = 'u';
		if (socket.send(mahyasend, 5, sara, port2) != sf::Socket::Done)
		{
			std::cerr << "error sending" << std::endl;
		}
		mahyasend[0] = 'v';
		//mode = 0;
		if (a != 2)
		{
			if (!texturem.loadFromFile("image5.png"))
				return;
			//hehe.rotate(-90);
			//hehe.aks(3);
			hehe.setTJ();
		}
		hehe.setxy(0, -10);
		a = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && hehe.gety()<3000 && down == true)
	{
		mahyasend[0] = 'd';
		if (socket.send(mahyasend, 5, sara, port2) != sf::Socket::Done)
		{
			std::cerr << "error sending" << std::endl;
		}
		mahyasend[0] = 'v';
		//mode = 0;
		if (a != 3)
		{
			if (!texturem.loadFromFile("image3.png"))
				return;
			//hehe.rotate(-90);
			//hehe.aks(3);
			hehe.setTJ();
		}
		//Sprite.setTexture(texture);
		//hehe.setTJ();
		//Sprite.move(0, +10);
		hehe.setxy(0, +10);
		//hehe.rotate(-10);
		a = 3;
	}

	//if (count == 0)
	//{
	// //sf::Thread thread(&Sh());
	// //thread.launch()
	// shelik(hehe);
	// //if (enemycheck(gule.getPosition().x , enemy.getPosition().x) == false)
	// //	enemy.scale(0, 0);
	//}


}

int main()
{
	mahyasend[1] = '1';

	/*if (socket.bind(54000) != sf::Socket::Done)
	{
	std::cerr << "error1" << std::endl;
	}*/


	std::cin >> name;

	//if (socket.send(data2, 2, sara, port2) != sf::Socket::Done)
	//{
	//std::cerr << "error sending" << std::endl;
	//}

	sf::Event event;
	sf::Thread thread(&tala);
	sf::Thread thread2(&mahya);
	//Open it from an audio file
	if (!music.openFromFile("music.ogg"))
	{
		// error...
		std::cerr << "oh\n";
	}
	// Change some parameters
	music.setPosition(0, 1, 10); // change its 3D position
	music.setPitch(2);           // increase the pitch
	music.setVolume(50);         // reduce the volume
	music.setLoop(true);         // make it loop
	// Play it
	music.play();
	sf::Texture texture1;
	sf::Texture bg;
	sf::Texture texture12;
	if (!do0.loadFromFile("i1.png"))
		std::cerr << "i1";
	sdo0.setTexture(do0);
	if (!do1.loadFromFile("i1.png"))
		std::cerr << "i2";
	sdo1.setTexture(do1);
	if (!do2.loadFromFile("i1.png"))
		std::cerr << "i3";
	sdo2.setTexture(do2);
	if (!do3.loadFromFile("i1.png"))
		std::cerr << "i4";
	sdo3.setTexture(do3);
	if (!do4.loadFromFile("i1.png"))
		std::cerr << "i5";
	sdo4.setTexture(do4);
	if (!bg.loadFromFile("finally.png"))
		return 1;

	sdo0.setPosition(90, 260);
	sdo1.setPosition(250, 260);
	sdo2.setPosition(410, 260);
	sdo3.setPosition(170, 320);
	sdo4.setPosition(330, 320);

	//if (!texturem.loadFromFile("image.png"))
	//	return 1;
	if (!texture1.loadFromFile("images.png"))
		return 1;
	sf::Sprite enemy;
	sf::Sprite bkg;
	sf::View view(sf::FloatRect(0.04, 0.06, Window.getSize().x, 2000));
	sf::View viewr(sf::FloatRect(0, 0, Window.getSize().x, 2000));
	//rectangle.setFillColor(sf::Color(205, 55, 0));
	//rectangle.setPosition(sf::Vector2f(80, 800));
	//rectanglez.setFillColor(sf::Color(255, 165, 0));
	//rectanglez.setPosition(sf::Vector2f(80, 670));
	thread.launch();



	Window.setFramerateLimit(60);

	//gule.setTexture(texture12);
	//Sprite.setTexture(texture);
	//enemy.setTexture(texture1);
	bkg.setTexture(bg);

	//view.reset(sf::FloatRect(0, 0, 1000, 500));
	view.setViewport(sf::FloatRect(0, 0.06, 0.75, 0.8));
	viewr.setViewport(sf::FloatRect(0.75, 0.05, 0.9, 1));
	//view.setViewport(sf::FloatRect(0, 0, 1.f, 1.f));
	sf::Vector2f position(0, 0);

	//Sprite.setPosition(50, 50);
	enemy.setPosition(450, 100);
	bkg.setPosition(0, 0);
	bkg.setScale(4, 4);
	while (Window.isOpen())
	{
		if (count1 == 0)
		{
			//sf::Thread thread(&Sh());
			//thread.launch()
			shelik1(hehe1, gule1);
			//if (enemycheck(gule.getPosition().x , enemy.getPosition().x) == false)
			//	enemy.scale(0, 0);
		}

		while (Window.pollEvent(event))
		{
			//mahyasend[4] = count;
			if (event.type == sf::Event::Closed)
				Window.close();
			thread2.launch();
		}

		if (count == 0)
		{
			//sf::Thread thread(&Sh());
			//thread.launch()
			shelik(hehe, gule);
			//if (enemycheck(gule.getPosition().x , enemy.getPosition().x) == false)
			//	enemy.scale(0, 0);
		}

		position.x = (hehe.getx() + 10) - 500;
		position.y = (hehe.gety() + 10) - 250;
		if (position.x < 0)
			position.x = 0;
		if (position.y < 0)
			position.y = 0;
		view.reset(sf::FloatRect(position.x, position.y, 1000, 500));
		view.zoom(1.65f);
		Window.setView(view);
		Window.clear(sf::Color(0, 0, 0));
		Window.draw(bkg);
		//Window.draw(Sprite);
		hehe.drawj();
		hehe1.drawj();
		gule1->drawt();
		gule->drawt();
		//std::cout<<hehe.getxt() << std::endl;
		Window.draw(enemy);
		Window.setView(viewr);
		//Window.draw(rectangle);
		//Window.draw(rectanglez);
		//Window.draw(rectangle);
		//Window.draw(rectanglez);
		Window.draw(sdo0);
		Window.draw(sdo1);
		Window.draw(sdo2);
		Window.draw(sdo3);
		Window.draw(sdo4);
		hehe.drawjoon();

		//Window.draw(gule);
		Window.display();
	}



	return 0;
}




