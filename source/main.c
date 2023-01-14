#include "engine.h"

int main(void) 
{   
    printf("hello wawa");
    Init(&GEngineInstance);

    while (1)
    {
        Update(&GEngineInstance);
    }
    
    Close(&GEngineInstance);

    return 0;
}