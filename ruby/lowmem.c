/*
 * MessagePack for Ruby lowmem switch
 *
 * Copyright (C) 2011 Moodstocks SAS
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */
#include "ruby.h"
#include "compat.h"
#include "pack.h"

static VALUE MessagePack_lowmem_on(VALUE self)
{
	rb_define_method(rb_cFloat,  "to_msgpack", MessagePack_Float_to_msgpack_lowmem, -1);
	return Qtrue;
}

static VALUE MessagePack_lowmem_off(VALUE self)
{
	rb_define_method(rb_cFloat,  "to_msgpack", MessagePack_Float_to_msgpack, -1);
	return Qtrue;
}

void Init_msgpack_lowmem(VALUE mMessagePack)
{
	rb_define_module_function(mMessagePack, "lowmem_on", MessagePack_lowmem_on, 0);
	rb_define_module_function(mMessagePack, "lowmem_off", MessagePack_lowmem_off, 0);
}
