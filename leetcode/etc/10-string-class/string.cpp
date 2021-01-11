#include <cstdio>
#include <iostream>
#include <cstring>

class String{

    private:
        unsigned int SizeS;
        char *Buffer;

    public:
        String():SizeS(0){}

        String(unsigned int i):SizeS(i){Buffer=new char[SizeS];}

        String(const char *string)
        {
            //defines the initialiser
            SizeS = strlen(string);                 //find out the length of the string
            Buffer = new char[SizeS];               //allocate space for the entire string+1 for terminator
            memcpy(Buffer,string,SizeS);            //copy to buffer the whole thing
            Buffer[SizeS]=0;                        //terminate the buffer with an end character
        }

        char * GetBuffer() const { return this->Buffer; }

        String (const String& copied) :SizeS(copied.SizeS)
        {
            // defines how copying  works
            Buffer = new char[SizeS];
            memcpy(Buffer,copied.Buffer,SizeS);
        }

        char operator[] (unsigned int index) const
        {
            // defines how the [] operator works
            if (index <= this->SizeS)
                return this->Buffer[index];
            else 
                return this->Buffer[0];
        }

        String& operator += (const String& to_concat)
        {
            unsigned int newSize = this->SizeS + to_concat.SizeS;
            char* p = new char[newSize];

            memcpy(p,this->Buffer,this->SizeS);
            memcpy(p+this->SizeS,to_concat.Buffer,to_concat.SizeS);

            delete[](this->Buffer);

            this->Buffer=p;
            this->SizeS=newSize;

            return *this;
        }

        String& operator + (const String& to_add)
        {
            unsigned int newSize = this->SizeS + to_add.SizeS-1;
            char *tmp= new char[newSize];

            memcpy(tmp,this->Buffer,this->SizeS);
            memcpy(tmp+SizeS,to_add.Buffer,to_add.SizeS);

            delete[](this->Buffer);
            this->Buffer= tmp;
            this->SizeS = newSize;

            return *this;
        }
};

std::ostream&  operator<< (std::ostream& stream, const String& other) { stream << other.GetBuffer(); return stream; }

int main()
{
    String c="foo";
    String d="man";

    std::cout<<c<<std::endl;
    c += c;
    c += d;
    c = c+d;
    std::cout<<c<<std::endl;



    return 1;
}
