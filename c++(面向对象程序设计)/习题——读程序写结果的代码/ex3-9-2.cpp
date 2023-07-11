#include<iostream> 
using std::cout;
using std::endl;
class Implementation {
      public:
         Implementation( int v ) { value = v; }
         void setValue( int v ) { value = v; }
         int getValue() const { return value; }
     private:
        int value;
  };
class Interface {
     public:
        Interface( int );
        void setValue( int );  
        int getValue() const;  
     private:
        Implementation *ptr;    
  };
  Interface::Interface( int v ) : ptr ( new Implementation( v ) ) { }
  void Interface::setValue( int v ) { ptr->setValue( v ); }
  int Interface::getValue() const { return ptr->getValue(); }
void main()
  {  Interface i( 5 );
     cout << i.getValue() << endl;
     i.setValue( 10 );
     cout << i.getValue() << endl;
  }
