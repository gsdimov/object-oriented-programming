#ifndef __LINE_SEGMENT_HPP
#define __LINE_SEGMENT_HPP

struct Point { double x, y; };

class LineSegment {
public:
  // при разделната компилация само ДЕКЛАРИРАМЕ методите в .hpp файла,
  // т.е. не пишем техните тела (дефиниции) тук!
  LineSegment(Point const &begin, Point const &end);

  // мутатори (setters)
  void setBegin(Point const &begin);
  void setEnd(Point const &end);

  // бяхме показали Point const &getBegin() const;
  // като друг възможен начин за дефиниране на долните
  // селектори. ще обясним по-подробно защо има смисъл,
  // когато си говорим за жизнен жикъл на обекти,
  // но накратко - тъй като ще връщаме директно полета на класа
  // (begin и end), няма нужда задължително да правим копие,
  // а можем да върнем референция към вече съществуващ обект.
  // това е валидно, защото begin и end ще бъдат "живи"
  // през целия жизнен цикъл на обект от тип LineSegment,
  // т.е. връщайки референция към някое от двете полета,
  // няма начин да получим т.нар. висяща референция
  // (референция, която сочи към невалиден обект)

  // селектори (getters)
  Point getBegin() const;
  Point getEnd() const;

  double length() const;

  double slope() const;

  Point midpoint() const;

  void translate(double dx, double dy);

private:
  Point begin, end;
};

#endif // __LINE_SEGMENT_HPP
