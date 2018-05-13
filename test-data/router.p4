#include <FixedThreeTables.p4>

control ingress(inout headers_t hdr, inout arch_metadata_t arch_metadata) {
    action drop() {
        mark_to_drop();
    }

    action punt_to_ctrl() {
        packet_in();
    }

    action set_output(bit<9> eport) {
        arch_metadata.egress_port = eport;
    }

    action set_output_and_dst_mac(bit<9> eport, bit<48> dmac) {
        set_output(eport);
        hdr.eth.dst_addr = dmac;
    }

    table filtering {
        key = {
            hdr.eth.ether_type: exact;
        }
        actions = {
            punt_to_ctrl;
            NoAction;
            drop;
        }
        deafult_action = drop;
    }

    table tmac {
        key = {
            hdr.eth.dst_addr: exact;
        }
        actions = {
            NoAction;
            drop;
        }
        deafult_action = drop;
    }

    table routing {
        key = {
            hdr.ipv4.dst_addr: exact;
        }
        actions = {
            set_output_and_dst_mac;
            drop;
            NoAction;
        }
        deafult_action = drop;
    }

    apply{
      filtering.apply();
      tmac.apply();
      routing.apply();
    }
}

FixedThreeTables(ingress()) main;
