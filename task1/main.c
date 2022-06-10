#include <assert.h>
#include "brackets.h"


int main() {
    assert(is_cbs("(a)[b*(c+d)]") == true);

    assert(is_cbs("(a)[b*(c+d)]{") == false);

    assert(is_cbs("(a)[b*(c+d)]}") == false);

    assert(is_cbs("(a)[b*(c+d)]]") == false);

    assert(is_cbs("(a)[b*(c+d])") == false);
}
