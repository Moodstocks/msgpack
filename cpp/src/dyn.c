#include "msgpack/pack.h"
#include "msgpack/unpack.h"
#include "msgpack/sbuffer.h"

void msgpack_dyn_packer_init(msgpack_packer* pk, void* data)
{ msgpack_packer_init(pk, data, msgpack_sbuffer_write); }

int msgpack_dyn_pack_array(msgpack_packer* pk, unsigned int n)
{ return msgpack_pack_array(pk, n); }

int msgpack_dyn_pack_raw(msgpack_packer* pk, size_t l)
{ return msgpack_pack_raw(pk, l); }

void msgpack_dyn_unpacked_init(msgpack_unpacked* result)
{ msgpack_unpacked_init(result); }

int msgpack_dyn_pack_raw_body(msgpack_packer* pk, const void* b, size_t l)
{ return msgpack_pack_raw_body(pk, b, l); }
