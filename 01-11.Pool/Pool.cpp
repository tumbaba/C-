#include "Pool.h"

void FObjectBase::Delete()
{
	Pool->free(this);
}
