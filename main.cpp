#include <iostream>
#include <stdio.h>
#include "source.h"
#include "circuit.h"

using namespace std;

int main()
{
    circuit_D a(0,1.2, 10e-9, 0.1e-6, 0);
    a.choix_source();
    a.f_euler(500e-9, 1e-10);

return 0;
}
