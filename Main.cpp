#include <iostream>
#include <conio.h>
#include "point.h"
#include "GUI.h"
#include "Shape.h"
#include "Window.h"
#include "STC.h"
#include <process.h>

using std::cout;
using std::endl;
using std::cin;
using std::ostream;
using std::ios_base;
using namespace::Grafix;
using namespace::_Xception;

_CRT_DEPRECATE_TEXT("yo");_declspec(deprecated("yo"));
_CRT_OBSOLETE(_TEST)inline void test(void *) throw()
{
	cout<<"\nIn Thread";
	_sleep(2000);
	cout<<endl<<__LINE__<<' '<<__FILE__<<' '<<__FUNCSIG__<<" "<<__FUNCDNAME__<<" "<<__FUNCTION__<<"\nThread Function ends";
	_endthread();
}

//class C
//{
//public:
//    static _ui32 i;
//public:
//    static auto n_instances() -> unsigned int { return i; }
//    
//    C(){ ++i; }
//	~C() { --i; }
//    C( C const& ) { ++i; }
//};

//_ui32 C::i;    // definition

class C
{
private:
    static auto n()										//static _i32r n()
        -> int&
    {
        static int the_count;
        return the_count;
    }
public:
    static auto n_instances() -> int { return n(); }
    ~C() { --n(); }
    C(){ ++n(); }
    C( C const& ) { ++n(); }
};

void main()
{
	window w[5] ={
					window(),
					window(10, 10, 20, 30,  " ", __REGULAR),
				//	window(10, 10, 40, 20, "window3", " ", __BOLD),
				//	window(20, 20, 30, 50, " ", __REGULAR),
				//	window(0, 5, 10, 60, " ", __REGULAR),
					window(0, 5, 8, 30, " ", __BOLD),
				//	window()
				};
//	GUI g(vector<window>(w, &w[2]));
//	_declspec(thread) static int t=1;
	cout<<"Booting...\n\n";
	GUI g(w, 4);
	g.Draw();
	STC<GUI> Yo(&g);
	GUI *gp;
	gp = Yo.get();
	Yo->Draw();
	Yo->Draw();
//	gp = new GUI(w, 2);
//	cout<<w[1].get_name();
//	w[0].Draw();
	/*cout<<"\nStarting Thread"
		<<_beginthread(test, 0, 0);
	cout<<"\nMain Ends";
	cout<<endl<<__TIME__;*/
	//_sleep(2000);
	//test(" ");
	//_endthread();
	/*C c[3];
	cout<<C::n_instances()<<endl;
	C c_;
	cout<<C::n_instances()<<endl;*/
	_getch();
}