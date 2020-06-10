#include "mother.h"
#include "daughter.h"
#include "brother.h"

int main()
{
    Mother Kate;
    Daughter Kas("Lia Glia");
    Daughter *borsh= new Daughter();
    Brother Bor("Borbba2");

    borsh->SayHello();
    Kate.SayHello();
    Kas.SayHello();
    Bor.SayHello();
    return 0;
}
