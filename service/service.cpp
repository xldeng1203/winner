/*
   Copyright (C) 2014-2015 别怀山(fool). See Copyright Notice in core.h
*/
#include "service.h"

namespace service{
	void register_service(){
		S2CallbackService::RegisterClass();
		S3CoroutineService::RegisterClass();
	}
}
