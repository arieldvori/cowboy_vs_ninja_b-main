#include "Point.hpp"
#include <cmath>
using namespace std;

Point::Point(double x, double y) : xval(x), yval(y) {}

double Point::getxval(){
  return this->xval;
}
double Point::getyval(){
  return this->yval;
}

double Point::distance(const Point &other) const{ 
  //dis=sqrt{(x1-x2)^2+(y1-y2)^2}
  double xdis = (this->xval-other.xval)*(this->xval-other.xval);
  double ydis = (this->yval-other.yval)*(this->yval-other.yval);
  return sqrt(xdis+ydis);
}
string Point::print() const{
  string str;
  str=  "(" + to_string(this->xval) + "," + to_string(yval) + ")"; 
  return str;
}

const Point Point::moveTowards(const Point &src,const Point &dest, double distance) {
  double src_dest_dis= src.distance(dest);
  if(distance==0)
    return src;
  if(distance<0)
    throw invalid_argument("distance cant be less than 0");
  //if the given distance is bigger so the point is the dest
  if(distance>=src_dest_dis)
    return dest;
  double xdis = dest.xval-src.xval;
  double ydis = dest.yval-src.yval;
  //finding the ratio between the two distances
  double ratio = distance/src_dest_dis;
  //grow the src by the ratio
  return Point(src.xval+ratio*xdis,src.yval+ratio*ydis);
}
