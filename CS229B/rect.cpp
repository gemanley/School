#include <iostream>
using namespace std;

class CRect
{
		int width, height;
	public:
		CRect(int, int);
		CRect();
		~CRect ();  // Deconstructor
		CRect operator + (CRect);
		CRect(const CRect&);
		void set_values(int, int);
		CRect& operator= (const CRect& param);
		int area() {return width*height;}
};

CRect::CRect()
{
	width = 5;
	height = 5;
}

void CRect::set_values(int a, int b)
{
	width = a;
	height = b;
}

CRect::CRect (int a, int b)
{
	width = a;
	height = b;
}
CRect::~CRect()
{
	// Used if width and height were pointers
	//delete width;
	//delete height;
	
	width = 0;
	height = 0;
}

CRect::CRect (const CRect& rect)
{
	// Copy constructor
	width = rect.width;
	height = rect.height;
}

CRect CRect::operator+ (CRect param)
{
	CRect temp;
	temp.width = width + param.width;
	return temp;
}
CRect& CRect::operator= (const CRect& param)
{
	width=param.width;
	height=param.height;
	return *this;
}

int main()
{
	CRect rect (3, 4);
	CRect rectb; // Note absence of parentheses on default constructor
	CRect rectc;
	rectc = rect + rectb; // Alternatively rectc = rect.operator+ (rectb)
	cout << "rect area: " << rect.area() << endl;
	cout << "rectb area: " << rectb.area() << endl;
	cout << "rectc area: " << rectc.area() << endl;
	return 0;
}
