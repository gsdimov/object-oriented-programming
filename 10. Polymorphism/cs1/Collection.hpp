#ifndef __COLLECTION_HPP
#define __COLLECTION_HPP

class Collection {
public:
  virtual void add(int)=0;
  virtual void remove(int)=0;
  virtual bool contains(int) const=0;

  virtual ~Collection()=default;
};

#endif // __COLLECTION_HPP
