#include <stdio.h>
#include <stdlib.h>
#include <time.h>
1.
yes,struct's name won't conflict member's name.
2.
(a)
struct{
    double real;
    double imaginary;
}c1, c2, c3;
(b)
struct{
    double real;
    double imaginary;
}c1={0.0, 1.0}, c2={1.0, 0.0}, c3;
(c)
yes, c1=c2;
(d)
c3.real=c1.real+c2.real;
c3.imaginary=c1.imaginary+c2.imaginary;
3.
(a)
struct complex{
    double real;
    double imaginary;
};
(b)
struct complex c1, c2, c3;
(c)
struct complex make_complex(struct complex a, double real, double imaginary)
{
    a.real=real;
    a.imaginary=imaginary;

    return a;
}
(d)
struct complex add_complex(struct complex a, struct complex b)
{
    a.real=a.real+b.real;
    a.imaginary=a.imaginary+b.imaginary;

    return a;
}
4.
(a)
typedef struct{
    double real;
    double imaginary;
}complex;
(b)
complex c1, c2, c3;
(c)
complex make_complex(complex a, double real, double imaginary)
{
    a.real=real;
    a.imaginary=imaginary;

    return a;
}
(d)
complex add_complex(complex a, complex b)
{
    a.real=a.real+b.real;
    a.imaginary=a.imaginary+b.imaginary;

    return a;
}
5.
(a)
int day_of_year(date d)
{
    int sum;
    switch(d.month)
    {
        case 1:     sum=0;break;
        case 2:     sum=31;break;
        case 3:     sum=59;break;
        case 4:     sum=90;break;
        case 5:     sum=120;break;
        case 6:     sum=151;break;
        case 7:     sum=182;break;
        case 8:     sum=212;break;
        case 9:     sum=243;break;
        case 10:    sum=273;break;
        case 11:    sum=304;break;
        case 12:    sum=334;break;
    }
    sum+=d.day;
    return sum;
}
(b)
int compare_dates(date d1, date d2)
{
    if(d1.day==d2.day&&d1.month==d2.month&&d1.year==d2.year)
        return 0;
    else if(d1.year<=d2.year&&d1.month<=d2.month&&d1.day<d2.day)
        return -1;
    else
        return 1;
}
6.
time split_time(long total_seconds)
{
    time ans;
    ans.hours=total_seconds/60/60;
    total_seconds-=ans.hours*3600;
    ans.minutes=total_seconds/60;
    total_seconds-=ans.minutes*60;
    ans.seconds=total_seconds;
    return ans;
}
7.
(a)
fraction simplify(fraction a)
{
    int flag;
    flag=(a.numerator < a.denomiator ? a.numerator : a.denomiator);

    for(int i=flag ; i>0 ; i--){
        if(a.numerator%i==0 && a.denomiator%i==0){
            a.numerator/=i;
            a.denomiator/=i;
            break;
        }
    }
    return a;
}
(b)
fraction add(fraction a, fraction b)
{
    a.numerator*=b.denomiator;
    b.numerator*=a.denomiator;
    a.denomiator*=b.denomiator;
    a.numerator+=b.numerator;
    return a;
}
simplify(a);
(c)
fraction add(fraction a, fraction b)
{
    a.numerator*=b.denomiator;
    b.numerator*=a.denomiator;
    a.denomiator*=b.denomiator;
    a.numerator-=b.numerator;
    return a;
}
simply(a);
(d)
fraction add(fraction a, fraction b)
{
    a.numerator*=b.numerator;
    a.denomiator*=b.denomiator;
    return a;
}
simply(a);
(e)
fraction add(fraction a, fraction b)
{
    a.numerator*=b.denomiator;
    a.denomiator*=b.numerator;
    return a;
}
simply(a);
8.
(a)
const struct color MAGENTA={255, 0, 255};
(b)
const struct color MAGENTA={.red=255, .blue=255};
9.
(a)
int strict(int a)
{
    if(a>255)   a=255;
    if(a<0)     a=0;
    return a;
}

color make_color(int red, int green, int blue)
{
    color a;
    a.red=strict(red);
    a.green=strict(green);
    a.blue=strict(blue);

    return a;
}
(b)
int getRed(color c)
{
    return c.red;
}
(c)
bool equal_color(color color1, color color2)
{
    if(color1.red==color2.red&&color1.green==color2.green&&color1.blue==color2.blue)
        return true;

    return false;
}
(d)
int strict(int a)
{
    if(a>0 && a<3) a=3;
    return a;
}
int strict1(int a){
    if(a>255)   a=255;
    return a;
}
color brighter(color c)
{
    color cc=c;
    cc.blue=strict(cc.blue); cc.green=strict(cc.green); cc.red=strict(cc.red);
    cc.blue/=0.7; cc.green/=0.7; cc.red/=0.7;
    if(c.blue==0&&c.green==0&&c.red==0){
        c.blue=c.green=c.red=3;
        return c;
    }
    cc.blue=strict1(cc.blue); cc.green=strict1(cc.green); cc.red=strict1(cc.red);;
    return cc;
}
(e)
color brighter(color c)
{
    color cc=c;
    cc.blue*=0.7; cc.green*=0.7; cc.red*=0.7;
    return cc;
}
9.
(a)
int area(rectangle r)
{
   return (a.lower_right.x-a.upper_left.x)*(a.upper_left.y-a.lower_right.y);
}
(b)
point center(rectangle r)
{
    point mid;
    mid.x=(a.lower_right.x+a.upper_left.x)/2;
    mid.y=(a.lower_right.y+a.upper_left.y)/2;
    return mid;
}
(c)
point move(point a, int x, int y)
{
    a.x+=x;
    a.y+=y;
    return a;
}
(d)
bool lieinornot(point a, rectangle r)
{
    if(a.x>=r.upper_left.x && a.x<=r.lower_right.x && a.y>=r.lower_right.y && a.y<=r.upper_left.y)
        return true;

    return false;
}
11.
20
12.
16
13.
legal: (b), (d)
illegal:
(a)enum shape_kind{ RECTANGLE, CIRCLE }
(c)s.u.rectangle.height=25;
(e), (f)s.u.circle.radius=5;
14.
float area(struct shape a)
{
    if(a.shape_kind==0)
        return (a.u.rectangle.height*a.u.rectangle.width);
    else
        return (a.u.circle.radius*a.u.circle.radius*3.14);
}
15.
(a)enum week{ MONDAY, TUSEDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAT, SUNDAY};
(b)typedef enum { MONDAY, TUSEDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAT, SUNDAY}week;
16.
(a)yes(b)yes(c)yes(d)no(e)yes
17.
a,b,c,d,e\a,d
18.
(a)
typedef enum{ pawn, knight, bishop, rook, queen, king, empty}Piece;
typedef enum{ black, white }Color;
(b)
typedef struct{
    int Piece;
    int Color;
}Square;
(e)
Square board={ empty, black };
19.
typedef struct{
    char name[41];
    int year;
    enum {EM, SS} type;
    int type;
    int players;
}pinall_machine;
20.
int switch1(int x, int y, direction a)
{
    switch(a)
    {
        case NOUTH:     return -y;break;
        case SOUTH:     return y;break;
        case EAST:      return x;break;
        case WEST:      return -x;break;
    }
}
21.
(a)0,1,2,3(b)11,12,13(c)14,15,16,24,25(d)45,46,47,37,38,39
22.
(a)enum chess_pieces {king=200,queen=5,rook=3,dishop=3,knight=}

