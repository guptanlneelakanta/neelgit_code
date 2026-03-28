#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
    // Enable automatic memory leak checking at program exit
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    
    // Optional: set a breakpoint on a specific allocation number if a leak is found
    // _CrtSetBreakAlloc(18); 

    // A deliberate memory leak
    int* leaked_ptr = (int*)malloc(sizeof(int));
    if (leaked_ptr == NULL) {
        // Always check if allocation failed
        return 1;
    }
    *leaked_ptr = 10;

    // The _CrtDumpMemoryLeaks() call is automatically made at exit 
    // due to the _CrtSetDbgFlag() call above.
    
    // If you don't use _CrtSetDbgFlag for automatic checks, 
    // you would manually call:
    // _CrtDumpMemoryLeaks(); 

    return 0;
}
