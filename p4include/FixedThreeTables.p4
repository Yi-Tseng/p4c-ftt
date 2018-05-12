#ifndef _FIXED_THREE_TABLES__P4_
#define _FIXED_THREE_TABLES__P4_

header ethernet_t {
    bit<48> dst_addr;
    bit<48> src_addr;
    bit<16> ether_type;
}

header ipv4_t {
    bit<4>  version;
    bit<4>  ihl;
    bit<6>  dscp;
    bit<2>  ecn;
    bit<16> len;
    bit<16> identification;
    bit<3>  flags;
    bit<13> frag_offset;
    bit<8>  ttl;
    bit<8>  protocol;
    bit<16> hdr_checksum;
    bit<32> src_addr;
    bit<32> dst_addr;
}

struct headers_t {
    ethernet_t eth;
    ipv4_t ipv4;
}

@metadata
struct arch_metadata_t {
    bit<9>  ingress_port;
    bit<9>  egress_port;
}

match_kind {
    exact,
    ternary
}

action NoAction() {
}

extern void mark_to_drop();
extern void packet_in();

@pipeline
control Ingress(inout headers_t hdr, inout arch_metadata_t arch_metadata);

package FixedThreeTables(Ingress ig);


#endif /* _FIXED_THREE_TABLES_P4_ */
